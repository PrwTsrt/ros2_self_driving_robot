// Copyright (c) 2020 Samsung Research America
// This code is licensed under MIT license (see LICENSE.txt for details)

#ifndef NAV2_NOTIFY_RECOVEY__OBSTACLE_WARNING_HPP_
#define NAV2_NOTIFY_RECOVEY__OBSTACLE_WARNING_HPP_

#include <chrono>
#include <string>
#include <memory>
#include <iostream>
#include <curl/curl.h>

#include "nav2_behaviors/timed_behavior.hpp"
#include "nav2_behavior_plugin/action/obstacle_warning.hpp"

namespace nav2_behavior_plugin
{

using namespace nav2_behaviors;  // NOLINT
using Action = nav2_behavior_plugin::action::ObstacleWarning;

class Notify : public TimedBehavior<Action>
{
public:
  Notify();
  ~Notify();

  Status onRun(const std::shared_ptr<const Action::Goal> command) override;

  Status onCycleUpdate() override;

  void onConfigure() override;

  /**
   * @brief Method to determine the required costmap info
   * @return costmap resources needed
   */

protected:
  std::string _token;
};

}  // namespace nav2_behavior_plugin

#endif  // NAV2_NOTIFY_RECOVEY__OBSTACLE_WARNING_HPP_
