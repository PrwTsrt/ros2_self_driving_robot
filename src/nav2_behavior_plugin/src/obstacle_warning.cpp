// Copyright (c) 2020 Samsung Research America
// This code is licensed under MIT license (see LICENSE.txt for details)

#include <cmath>
#include <chrono>
#include <memory>

#include "nav2_behavior_plugin/obstacle_warning.hpp"

namespace nav2_behavior_plugin
{

Notify::Notify()
: TimedBehavior<Action>()
{
}

Notify::~Notify()
{
}

// Function to send a message to Line Notify
bool sendLineNotify(const std::string& token, const std::string& message) {
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        std::string url = "https://notify-api.line.me/api/notify";
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, ("Authorization: Bearer " + token).c_str());

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POST, 1L);

        std::string data = "message=" + message;
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
            return false;
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
        
        return true;
    }

    curl_global_cleanup();
}

void Notify::onConfigure()
{
  auto node = node_.lock();
  node->declare_parameter("token","");
  _token = node->get_parameter("token").as_string();
  
//   node->declare_parameter("from_number","");
//   _from_number = node->get_parameter("from_number").as_string();
//   node->declare_parameter("to_number","");
//   _to_number = node->get_parameter("to_number").as_string();
//   _twilio = std::make_shared<twilio::Twilio>(_account_sid, _auth_token);
}

Status Notify::onRun(const std::shared_ptr<const Action::Goal> command)
{
  auto node = node_.lock();
  bool message_success = sendLineNotify(_token, command->message);
  if (!message_success) {
    RCLCPP_INFO(node->get_logger(), "Notify failed.");
    return Status::FAILED;
  }

  RCLCPP_INFO(node->get_logger(), "Notify successfully!");
  return Status::SUCCEEDED;
}

Status Notify::onCycleUpdate()
{
  return Status::SUCCEEDED;
}

}  // namespace nav2_sms_behavior

#include "pluginlib/class_list_macros.hpp"
PLUGINLIB_EXPORT_CLASS(nav2_behavior_plugin::Notify, nav2_core::Behavior)
