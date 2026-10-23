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
// Application configuration for NetworkCommissioning based on EMBER configuration
#pragma once

#include <app/util/cluster-config.h>
#include <clusters/NetworkCommissioning/AttributeIds.h>
#include <clusters/NetworkCommissioning/CommandIds.h>
#include <clusters/NetworkCommissioning/Enums.h>

#include <array>

namespace chip {
namespace app {
namespace Clusters {
namespace NetworkCommissioning {
namespace StaticApplicationConfig {
namespace detail {
inline constexpr AttributeId kEndpoint0EnabledAttributes[] = {
    Attributes::MaxNetworks::Id,
    Attributes::Networks::Id,
    Attributes::ScanMaxTimeSeconds::Id,
    Attributes::ConnectMaxTimeSeconds::Id,
    Attributes::InterfaceEnabled::Id,
    Attributes::LastNetworkingStatus::Id,
    Attributes::LastNetworkID::Id,
    Attributes::LastConnectErrorValue::Id,
    Attributes::SupportedThreadFeatures::Id,
    Attributes::ThreadVersion::Id,
    Attributes::GeneratedCommandList::Id,
    Attributes::AcceptedCommandList::Id,
    Attributes::AttributeList::Id,
    Attributes::FeatureMap::Id,
    Attributes::ClusterRevision::Id,
};
inline constexpr CommandId kEndpoint0EnabledCommands[] = {
    Commands::ScanNetworks::Id,
    Commands::AddOrUpdateWiFiNetwork::Id,
    Commands::AddOrUpdateThreadNetwork::Id,
    Commands::RemoveNetwork::Id,
    Commands::ConnectNetwork::Id,
    Commands::ReorderNetwork::Id,
};
} // namespace detail

using FeatureBitmapType = Feature;

inline constexpr std::array<Clusters::StaticApplicationConfig::ClusterConfiguration<FeatureBitmapType>, 1 + 0> kFixedClusterConfig = { {
    {
        .endpointNumber = 0,
        .featureMap = BitFlags<FeatureBitmapType> {
        },
        .enabledAttributes =
            Span<const AttributeId>(detail::kEndpoint0EnabledAttributes),
        .enabledCommands =
            Span<const CommandId>(detail::kEndpoint0EnabledCommands),
    },
} };

// If a specific attribute is supported at all across all endpoint static instantiations
inline constexpr bool IsAttributeEnabledOnSomeEndpoint(AttributeId attributeId) {
  switch (attributeId) {
    case Attributes::MaxNetworks::Id:
      return true;
    case Attributes::Networks::Id:
      return true;
    case Attributes::ScanMaxTimeSeconds::Id:
      return true;
    case Attributes::ConnectMaxTimeSeconds::Id:
      return true;
    case Attributes::InterfaceEnabled::Id:
      return true;
    case Attributes::LastNetworkID::Id:
      return true;
    case Attributes::LastConnectErrorValue::Id:
      return true;
    case Attributes::ThreadVersion::Id:
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
    case Commands::ScanNetworks::Id:
      return true;
    case Commands::AddOrUpdateWiFiNetwork::Id:
      return true;
    case Commands::AddOrUpdateThreadNetwork::Id:
      return true;
    case Commands::RemoveNetwork::Id:
      return true;
    case Commands::ConnectNetwork::Id:
      return true;
    case Commands::ReorderNetwork::Id:
      return true;
    default:
      return false;
  }
}

} // namespace StaticApplicationConfig
} // namespace NetworkCommissioning
} // namespace Clusters
} // namespace app
} // namespace chip