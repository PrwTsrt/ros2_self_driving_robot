// Copyright (c) 2018 Samsung Research America
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <string>
#include <memory>
#include <cmath>

#include "my_nav2_behavior_tree/obstacle_warning_action.hpp"

namespace my_nav2_behavior_tree
{

NotifyAction::NotifyAction(
  const std::string & xml_tag_name,
  const std::string & action_name,
  const BT::NodeConfiguration & conf)
: BtActionNode<nav2_behavior_plugin::action::ObstacleWarning>(xml_tag_name, action_name, conf),
  initialized_(false)
{
}

void NotifyAction::initialize()
{
  std::string message;
  getInput("message_to_send", message);
//   if (duration <= 0) {
//     RCLCPP_WARN(
//       node_->get_logger(), "Wait duration is negative or zero "
//       "(%f). Setting to positive.", duration);
//     duration *= -1;
//   }

  goal_.message = message;
  initialized_ = true;
}

void NotifyAction::on_tick()
{
  if (!initialized_) {
    initialize();
  }

  increment_recovery_count();
}

}  // namespace my_nav2_behavior_tree

#include "behaviortree_cpp_v3/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  BT::NodeBuilder builder =
    [](const std::string & name, const BT::NodeConfiguration & config)
    {
      return std::make_unique<my_nav2_behavior_tree::NotifyAction>(name, "notify", config);
    };

  factory.registerBuilder<my_nav2_behavior_tree::NotifyAction>("Notify", builder);
}