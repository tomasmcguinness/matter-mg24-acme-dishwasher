/*
 *
 *    Copyright (c) 2022 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */


// DO NOT EDIT - Generated file
//
// Application configuration for DeviceEnergyManagement based on EMBER configuration
#pragma once

#include <app/util/cluster-config.h>
#include <clusters/DeviceEnergyManagement/AttributeIds.h>
#include <clusters/DeviceEnergyManagement/CommandIds.h>
#include <clusters/DeviceEnergyManagement/Enums.h>

#include <array>

namespace chip {
namespace app {
namespace Clusters {
namespace DeviceEnergyManagement {
namespace StaticApplicationConfig {
namespace detail {
inline constexpr AttributeId kEndpoint2EnabledAttributes[] = {
    Attributes::ESAType::Id,
    Attributes::ESACanGenerate::Id,
    Attributes::ESAState::Id,
    Attributes::AbsMinPower::Id,
    Attributes::AbsMaxPower::Id,
    Attributes::PowerAdjustmentCapability::Id,
    Attributes::Forecast::Id,
    Attributes::OptOutState::Id,
    Attributes::GeneratedCommandList::Id,
    Attributes::AcceptedCommandList::Id,
    Attributes::AttributeList::Id,
    Attributes::FeatureMap::Id,
    Attributes::ClusterRevision::Id,
};
inline constexpr CommandId kEndpoint2EnabledCommands[] = {
    Commands::PowerAdjustRequest::Id,
    Commands::CancelPowerAdjustRequest::Id,
    Commands::StartTimeAdjustRequest::Id,
    Commands::PauseRequest::Id,
    Commands::ResumeRequest::Id,
    Commands::ModifyForecastRequest::Id,
    Commands::RequestConstraintBasedForecast::Id,
    Commands::CancelRequest::Id,
};
} // namespace detail

using FeatureBitmapType = Feature;

inline constexpr std::array<Clusters::StaticApplicationConfig::ClusterConfiguration<FeatureBitmapType>, 1 + 0> kFixedClusterConfig = { {
    {
        .endpointNumber = 2,
        .featureMap = BitFlags<FeatureBitmapType> {
        },
        .enabledAttributes =
            Span<const AttributeId>(detail::kEndpoint2EnabledAttributes),
        .enabledCommands =
            Span<const CommandId>(detail::kEndpoint2EnabledCommands),
    },
} };

// If a specific attribute is supported at all across all endpoint static instantiations
inline constexpr bool IsAttributeEnabledOnSomeEndpoint(AttributeId attributeId) {
  switch (attributeId) {
    case Attributes::ESACanGenerate::Id:
      return true;
    case Attributes::AbsMinPower::Id:
      return true;
    case Attributes::AbsMaxPower::Id:
      return true;
    case Attributes::GeneratedCommandList::Id:
      return true;
    case Attributes::AcceptedCommandList::Id:
      return true;
    case Attributes::AttributeList::Id:
      return true;
    case Attributes::FeatureMap::Id:
      return true;
    case Attributes::ClusterRevision::Id:
      return true;
    default:
      return false;
  }
}

// If a specific command is supported at all across all endpoint static instantiations
inline constexpr bool IsCommandEnabledOnSomeEndpoint(CommandId commandId) {
  switch (commandId) {
    case Commands::PowerAdjustRequest::Id:
      return true;
    case Commands::CancelPowerAdjustRequest::Id:
      return true;
    case Commands::StartTimeAdjustRequest::Id:
      return true;
    case Commands::PauseRequest::Id:
      return true;
    case Commands::ResumeRequest::Id:
      return true;
    case Commands::ModifyForecastRequest::Id:
      return true;
    case Commands::RequestConstraintBasedForecast::Id:
      return true;
    case Commands::CancelRequest::Id:
      return true;
    default:
      return false;
  }
}

} // namespace StaticApplicationConfig
} // namespace DeviceEnergyManagement
} // namespace Clusters
} // namespace app
} // namespace chip