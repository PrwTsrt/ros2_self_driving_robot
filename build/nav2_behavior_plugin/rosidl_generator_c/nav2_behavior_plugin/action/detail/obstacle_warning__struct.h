// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nav2_behavior_plugin:action/ObstacleWarning.idl
// generated code does not contain a copyright notice

#ifndef NAV2_BEHAVIOR_PLUGIN__ACTION__DETAIL__OBSTACLE_WARNING__STRUCT_H_
#define NAV2_BEHAVIOR_PLUGIN__ACTION__DETAIL__OBSTACLE_WARNING__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/ObstacleWarning in the package nav2_behavior_plugin.
typedef struct nav2_behavior_plugin__action__ObstacleWarning_Goal
{
  rosidl_runtime_c__String message;
} nav2_behavior_plugin__action__ObstacleWarning_Goal;

// Struct for a sequence of nav2_behavior_plugin__action__ObstacleWarning_Goal.
typedef struct nav2_behavior_plugin__action__ObstacleWarning_Goal__Sequence
{
  nav2_behavior_plugin__action__ObstacleWarning_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav2_behavior_plugin__action__ObstacleWarning_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'total_elapsed_time'
#include "builtin_interfaces/msg/detail/duration__struct.h"

/// Struct defined in action/ObstacleWarning in the package nav2_behavior_plugin.
typedef struct nav2_behavior_plugin__action__ObstacleWarning_Result
{
  builtin_interfaces__msg__Duration total_elapsed_time;
  uint16_t error_code;
} nav2_behavior_plugin__action__ObstacleWarning_Result;

// Struct for a sequence of nav2_behavior_plugin__action__ObstacleWarning_Result.
typedef struct nav2_behavior_plugin__action__ObstacleWarning_Result__Sequence
{
  nav2_behavior_plugin__action__ObstacleWarning_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav2_behavior_plugin__action__ObstacleWarning_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/ObstacleWarning in the package nav2_behavior_plugin.
typedef struct nav2_behavior_plugin__action__ObstacleWarning_Feedback
{
  uint8_t structure_needs_at_least_one_member;
} nav2_behavior_plugin__action__ObstacleWarning_Feedback;

// Struct for a sequence of nav2_behavior_plugin__action__ObstacleWarning_Feedback.
typedef struct nav2_behavior_plugin__action__ObstacleWarning_Feedback__Sequence
{
  nav2_behavior_plugin__action__ObstacleWarning_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav2_behavior_plugin__action__ObstacleWarning_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "nav2_behavior_plugin/action/detail/obstacle_warning__struct.h"

/// Struct defined in action/ObstacleWarning in the package nav2_behavior_plugin.
typedef struct nav2_behavior_plugin__action__ObstacleWarning_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  nav2_behavior_plugin__action__ObstacleWarning_Goal goal;
} nav2_behavior_plugin__action__ObstacleWarning_SendGoal_Request;

// Struct for a sequence of nav2_behavior_plugin__action__ObstacleWarning_SendGoal_Request.
typedef struct nav2_behavior_plugin__action__ObstacleWarning_SendGoal_Request__Sequence
{
  nav2_behavior_plugin__action__ObstacleWarning_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav2_behavior_plugin__action__ObstacleWarning_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/ObstacleWarning in the package nav2_behavior_plugin.
typedef struct nav2_behavior_plugin__action__ObstacleWarning_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} nav2_behavior_plugin__action__ObstacleWarning_SendGoal_Response;

// Struct for a sequence of nav2_behavior_plugin__action__ObstacleWarning_SendGoal_Response.
typedef struct nav2_behavior_plugin__action__ObstacleWarning_SendGoal_Response__Sequence
{
  nav2_behavior_plugin__action__ObstacleWarning_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav2_behavior_plugin__action__ObstacleWarning_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/ObstacleWarning in the package nav2_behavior_plugin.
typedef struct nav2_behavior_plugin__action__ObstacleWarning_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} nav2_behavior_plugin__action__ObstacleWarning_GetResult_Request;

// Struct for a sequence of nav2_behavior_plugin__action__ObstacleWarning_GetResult_Request.
typedef struct nav2_behavior_plugin__action__ObstacleWarning_GetResult_Request__Sequence
{
  nav2_behavior_plugin__action__ObstacleWarning_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav2_behavior_plugin__action__ObstacleWarning_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "nav2_behavior_plugin/action/detail/obstacle_warning__struct.h"

/// Struct defined in action/ObstacleWarning in the package nav2_behavior_plugin.
typedef struct nav2_behavior_plugin__action__ObstacleWarning_GetResult_Response
{
  int8_t status;
  nav2_behavior_plugin__action__ObstacleWarning_Result result;
} nav2_behavior_plugin__action__ObstacleWarning_GetResult_Response;

// Struct for a sequence of nav2_behavior_plugin__action__ObstacleWarning_GetResult_Response.
typedef struct nav2_behavior_plugin__action__ObstacleWarning_GetResult_Response__Sequence
{
  nav2_behavior_plugin__action__ObstacleWarning_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav2_behavior_plugin__action__ObstacleWarning_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "nav2_behavior_plugin/action/detail/obstacle_warning__struct.h"

/// Struct defined in action/ObstacleWarning in the package nav2_behavior_plugin.
typedef struct nav2_behavior_plugin__action__ObstacleWarning_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  nav2_behavior_plugin__action__ObstacleWarning_Feedback feedback;
} nav2_behavior_plugin__action__ObstacleWarning_FeedbackMessage;

// Struct for a sequence of nav2_behavior_plugin__action__ObstacleWarning_FeedbackMessage.
typedef struct nav2_behavior_plugin__action__ObstacleWarning_FeedbackMessage__Sequence
{
  nav2_behavior_plugin__action__ObstacleWarning_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav2_behavior_plugin__action__ObstacleWarning_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NAV2_BEHAVIOR_PLUGIN__ACTION__DETAIL__OBSTACLE_WARNING__STRUCT_H_
