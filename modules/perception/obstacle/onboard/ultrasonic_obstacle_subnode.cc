/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include "modules/perception/obstacle/onboard/ultrasonic_obstacle_subnode.h"

#include "modules/common/log.h"

namespace apollo {
namespace perception {

void UltrasonicObstacleSubnode::OnUltrasonic(
    const apollo::canbus::Chassis& message) {
  ++seq_num_;
  std::shared_ptr<SensorObjects> sensor_objects(new SensorObjects);
  double timestamp = message.header().timestamp_sec();
  sensor_objects->timestamp = timestamp;
  // TODO(all) set sensor_objects->sensor_type
  sensor_objects->sensor_id = device_id_;
  sensor_objects->seq_num = seq_num_;

  // TODO(all) transform message to object and insert into sensor_objects

  if (!PublishDataAndEvent(timestamp, sensor_objects)) {
    AERROR << "Failed to publish data.";
    sensor_objects->error_code = apollo::common::PERCEPTION_ERROR_PROCESS;
    return;
  }
}

bool UltrasonicObstacleSubnode::PublishDataAndEvent(
    const double timestamp, const SharedDataPtr<SensorObjects>& data) {
  // TODO(all) implement
  return true;
}

}  // namespace perception
}  // namespace apollo
