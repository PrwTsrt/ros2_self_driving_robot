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

#ifndef MY_NAV2_BEHAVIOR_TREE__OBSTACLE_WARNING_ACTION_HPP_
#define MY_NAV2_BEHAVIOR_TREE__OBSTACLE_WARNING_ACTION_HPP_

#include <string>

#include "nav2_behavior_tree/bt_action_node.hpp"
#include "nav2_behavior_plugin/action/obstacle_warning.hpp"

namespace my_nav2_behavior_tree
{

/**
 * @brief A nav2_behavior_tree::BtActionNode class that wraps nav2_msgs::action::Wait
 */
class NotifyAction : public nav2_behavior_tree::BtActionNode<
  nav2_behavior_plugin::action::ObstacleWarning>
{
public:
  /**
   * @brief A constructor for nav2_behavior_tree::WaitAction
   * @param xml_tag_name Name for the XML tag for this node
   * @param action_name Action name this node creates a client for
   * @param conf BT node configuration
   */
  NotifyAction(
    const std::string & xml_tag_name,
    const std::string & action_name,
    const BT::NodeConfiguration & conf);

  /**
   * @brief Function to perform some user-defined operation on tick
   */
  void on_tick() override;

  /**
   * @brief Function to read parameters and initialize class variables
   */
  void initialize();

  /**
   * @brief Creates list of BT ports
   * @return BT::PortsList Containing basic ports along with node-specific ports
   */
  static BT::PortsList providedPorts()
  {
    return providedBasicPorts(
      {
        BT::InputPort<std::string>("message_to_send", "default message", "Message to notify")
      });
  }

private:
  bool initialized_;
};

}  // namespace my_nav2_behavior_tree

#endif  // MY_NAV2_BEHAVIOR_TREE__OBSTACLE_WARNING_ACTION_HPP_