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
// Application configuration for OperationalState based on EMBER configuration
#pragma once

#include <app/util/cluster-config.h>
#include <clusters/OperationalState/AttributeIds.h>
#include <clusters/OperationalState/CommandIds.h>
#include <clusters/OperationalState/Enums.h>

#include <array>

namespace chip {
namespace app {
namespace Clusters {
namespace OperationalState {
namespace StaticApplicationConfig {
namespace detail {
inline constexpr AttributeId kEndpoint1EnabledAttributes[] = {
    Attributes::PhaseList::Id,
    Attributes::CurrentPhase::Id,
    Attributes::CountdownTime::Id,
    Attributes::OperationalStateList::Id,
    Attributes::OperationalState::Id,
    Attributes::OperationalError::Id,
    Attributes::GeneratedCommandList::Id,
    Attributes::AcceptedCommandList::Id,
    Attributes::AttributeList::Id,
    Attributes::FeatureMap::Id,
    Attributes::ClusterRevision::Id,
};
inline constexpr CommandId kEndpoint1EnabledCommands[] = {
    Commands::Pause::Id,
    Commands::Stop::Id,
    Commands::Start::Id,
    Commands::Resume::Id,
};
} // namespace detail

using FeatureBitmapType = Clusters::StaticApplicationConfig::NoFeatureFlagsDefined;

inline constexpr std::array<Clusters::StaticApplicationConfig::ClusterConfiguration<FeatureBitmapType>, 1 + 0> kFixedClusterConfig = { {
    {
        .endpointNumber = 1,
        .featureMap = BitFlags<FeatureBitmapType> {
        },
        .enabledAttributes =
            Span<const AttributeId>(detail::kEndpoint1EnabledAttributes),
        .enabledCommands =
            Span<const CommandId>(detail::kEndpoint1EnabledCommands),
    },
} };

// If a specific attribute is supported at all across all endpoint static instantiations
inline constexpr bool IsAttributeEnabledOnSomeEndpoint(AttributeId attributeId) {
  switch (attributeId) {
    case Attributes::PhaseList::Id:
      return true;
    case Attributes::CurrentPhase::Id:
      return true;
    case Attributes::CountdownTime::Id:
      return true;
    case Attributes::OperationalStateList::Id:
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
    case Commands::Pause::Id:
      return true;
    case Commands::Stop::Id:
      return true;
    case Commands::Start::Id:
      return true;
    case Commands::Resume::Id:
      return true;
    default:
      return false;
  }
}

} // namespace StaticApplicationConfig
} // namespace OperationalState
} // namespace Clusters
} // namespace app
} // namespace chip