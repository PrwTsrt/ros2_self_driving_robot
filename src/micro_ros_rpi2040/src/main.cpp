#include <Arduino.h>
#include <micro_ros_platformio.h>

#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <micro_ros_utilities/string_utilities.h>
#include <rmw_microros/rmw_microros.h>

#include <std_msgs/msg/bool.h>
#include <sensor_msgs/msg/range.h>
#include <Ultrasonic.h>

#if !defined(MICRO_ROS_TRANSPORT_ARDUINO_SERIAL)
#error This example is only avaliable for Arduino framework with serial transport.
#endif

#define ROS_DOMAIN_ID 19

rcl_publisher_t publisher_range_left, publisher_range_center, publisher_range_right, 
  publisher_bump_state;
sensor_msgs__msg__Range msg_range_left, msg_range_center, msg_range_right;
std_msgs__msg__Bool msg_bump_state;

rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;
rcl_timer_t timer;

rcl_init_options_t init_options;

#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){error_loop();}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){}}

Ultrasonic ranger[3] = {
  Ultrasonic(17),
  Ultrasonic(5),
  Ultrasonic(3)
};

const int LED_PIN = 26 ;
const int bumper_pin = 6;

// Timeout for each ping attempt
const int timeout_ms = 100;
// Number of ping attempts
const uint8_t attempts = 1;
// Spin period
const unsigned int spin_timeout = RCL_MS_TO_NS(100);
// Enum with connection status
enum states {
    WAITING_AGENT,
    AGENT_AVAILABLE,
    AGENT_CONNECTED,
    AGENT_DISCONNECTED
} state;

// Error handle loop
void error_loop() {
  while(1) {
    delay(100);
  }
}

void timer_callback(rcl_timer_t * timer, int64_t last_call_time) {
  RCLC_UNUSED(last_call_time);
  float range[3];

  for (int i = 0; i < 3; i++){
    range[i] = ranger[i].MeasureInCentimeters() * 0.01;
    if (range[i] > 0.5) range[i] = 0.5;
  }

  msg_bump_state.data = digitalRead(bumper_pin);
  msg_bump_state.data ? range[1] = 0.0 : range[1] = range[1];

  msg_range_left.range =range[0];
  msg_range_center.range = range[1];
  msg_range_right.range = range[2];

  if (timer != NULL) {
    RCSOFTCHECK(rcl_publish(&publisher_range_left, &msg_range_left, NULL));
    RCSOFTCHECK(rcl_publish(&publisher_range_center, &msg_range_center, NULL));
    RCSOFTCHECK(rcl_publish(&publisher_range_right, &msg_range_right, NULL));
    RCSOFTCHECK(rcl_publish(&publisher_bump_state, &msg_bump_state, NULL));
  }
}

void range_msgs_init(sensor_msgs__msg__Range &range_msg, const char *frame_id_name){
  range_msg.header.frame_id = micro_ros_string_utilities_set(range_msg.header.frame_id, frame_id_name);
  range_msg.radiation_type = sensor_msgs__msg__Range__ULTRASOUND;
  range_msg.field_of_view = 15 * (3.14/180); // rad
  range_msg.min_range = 0.03; // m
  range_msg.max_range = 4.0; // m  
}

bool create_entities(void) {
  
  init_options = rcl_get_zero_initialized_init_options();
  allocator = rcl_get_default_allocator();

  RCCHECK(rcl_init_options_init(&init_options, allocator));
  
  size_t domain_id = (size_t)(ROS_DOMAIN_ID);
  RCCHECK(rcl_init_options_set_domain_id(&init_options, domain_id));

  //create init_options
  RCCHECK(rclc_support_init_with_options(&support, 0, NULL, &init_options, &allocator));

  // create node
  RCCHECK(rclc_node_init_default(&node, "micro_ros_raspico_node", "", &support));

  // create publisher
  RCCHECK(rclc_publisher_init_default(
    &publisher_range_left,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, Range),
    "range_left"));
  RCCHECK(rclc_publisher_init_default(
    &publisher_range_center,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, Range),
    "range_center"));
  RCCHECK(rclc_publisher_init_default(
    &publisher_range_right,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, Range),
    "range_right"));
  RCCHECK(rclc_publisher_init_default(
    &publisher_bump_state,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Bool),
    "bumper_state")); 

  // create timer,
  const unsigned int timer_timeout = 50;
  RCCHECK(rclc_timer_init_default(
    &timer,
    &support,
    RCL_MS_TO_NS(timer_timeout),
    timer_callback));

  // create executor
  executor = rclc_executor_get_zero_initialized_executor();
  RCCHECK(rclc_executor_init(&executor, &support.context, 1, &allocator));
  RCCHECK(rclc_executor_add_timer(&executor, &timer));

 digitalWrite(LED_PIN, HIGH);

  return true;
}

void destroy_entities(void){

  rmw_context_t * rmw_context = rcl_context_get_rmw_context(&support.context);
  (void) rmw_uros_set_context_entity_destroy_session_timeout(rmw_context, 0);

  RCCHECK(rcl_publisher_fini(&publisher_range_left, &node));
  RCCHECK(rcl_publisher_fini(&publisher_range_center, &node));
  RCCHECK(rcl_publisher_fini(&publisher_range_right, &node));
  RCCHECK(rcl_publisher_fini(&publisher_bump_state, &node));
  RCCHECK(rcl_node_fini(&node)); 
  RCCHECK(rcl_timer_fini(&timer));
  RCCHECK(rclc_executor_fini(&executor));
  RCCHECK(rclc_support_fini(&support));

  digitalWrite(LED_PIN, LOW);

}

void setup() {

  pinMode(LED_PIN, OUTPUT);
  // Configure serial transport
  Serial.begin(921600);
  set_microros_serial_transports(Serial);
  delay(2000);

  range_msgs_init(msg_range_left, "ranger_left_frame");
  range_msgs_init(msg_range_center, "ranger_center_frame");
  range_msgs_init(msg_range_right, "ranger_right_frame");

}

void loop() {

  switch (state)
    {
        case WAITING_AGENT:
            // Check for agent connection
            state = (RMW_RET_OK == rmw_uros_ping_agent(timeout_ms, attempts)) ? AGENT_AVAILABLE : WAITING_AGENT;
            break;

        case AGENT_AVAILABLE:
            // Create micro-ROS entities
            state = (true == create_entities()) ? AGENT_CONNECTED : WAITING_AGENT;

            if (state == WAITING_AGENT)
            {
                // Creation failed, release allocated resources
                destroy_entities();
            };
            break;

        case AGENT_CONNECTED:
            // Check connection and spin on success
            state = (RMW_RET_OK == rmw_uros_ping_agent(timeout_ms, attempts)) ? AGENT_CONNECTED : AGENT_DISCONNECTED;
            if (state == AGENT_CONNECTED)
            {
                RCSOFTCHECK(rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100)));            }
            break;

        case AGENT_DISCONNECTED:
            // Connection is lost, destroy entities and go back to first step
            destroy_entities();
            state = WAITING_AGENT;
            break;

        default:
            break;
    }

}