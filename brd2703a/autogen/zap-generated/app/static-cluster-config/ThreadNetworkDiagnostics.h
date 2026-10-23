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
// Application configuration for ThreadNetworkDiagnostics based on EMBER configuration
#pragma once

#include <app/util/cluster-config.h>
#include <clusters/ThreadNetworkDiagnostics/AttributeIds.h>
#include <clusters/ThreadNetworkDiagnostics/CommandIds.h>
#include <clusters/ThreadNetworkDiagnostics/Enums.h>

#include <array>

namespace chip {
namespace app {
namespace Clusters {
namespace ThreadNetworkDiagnostics {
namespace StaticApplicationConfig {
namespace detail {
inline constexpr AttributeId kEndpoint0EnabledAttributes[] = {
    Attributes::Channel::Id,
    Attributes::RoutingRole::Id,
    Attributes::NetworkName::Id,
    Attributes::PanId::Id,
    Attributes::ExtendedPanId::Id,
    Attributes::MeshLocalPrefix::Id,
    Attributes::OverrunCount::Id,
    Attributes::NeighborTable::Id,
    Attributes::RouteTable::Id,
    Attributes::PartitionId::Id,
    Attributes::Weighting::Id,
    Attributes::DataVersion::Id,
    Attributes::StableDataVersion::Id,
    Attributes::LeaderRouterId::Id,
    Attributes::DetachedRoleCount::Id,
    Attributes::ChildRoleCount::Id,
    Attributes::RouterRoleCount::Id,
    Attributes::LeaderRoleCount::Id,
    Attributes::AttachAttemptCount::Id,
    Attributes::PartitionIdChangeCount::Id,
    Attributes::BetterPartitionAttachAttemptCount::Id,
    Attributes::ParentChangeCount::Id,
    Attributes::TxTotalCount::Id,
    Attributes::TxUnicastCount::Id,
    Attributes::TxBroadcastCount::Id,
    Attributes::TxAckRequestedCount::Id,
    Attributes::TxAckedCount::Id,
    Attributes::TxNoAckRequestedCount::Id,
    Attributes::TxDataCount::Id,
    Attributes::TxDataPollCount::Id,
    Attributes::TxBeaconCount::Id,
    Attributes::TxBeaconRequestCount::Id,
    Attributes::TxOtherCount::Id,
    Attributes::TxRetryCount::Id,
    Attributes::TxDirectMaxRetryExpiryCount::Id,
    Attributes::TxIndirectMaxRetryExpiryCount::Id,
    Attributes::TxErrCcaCount::Id,
    Attributes::TxErrAbortCount::Id,
    Attributes::TxErrBusyChannelCount::Id,
    Attributes::RxTotalCount::Id,
    Attributes::RxUnicastCount::Id,
    Attributes::RxBroadcastCount::Id,
    Attributes::RxDataCount::Id,
    Attributes::RxDataPollCount::Id,
    Attributes::RxBeaconCount::Id,
    Attributes::RxBeaconRequestCount::Id,
    Attributes::RxOtherCount::Id,
    Attributes::RxAddressFilteredCount::Id,
    Attributes::RxDestAddrFilteredCount::Id,
    Attributes::RxDuplicatedCount::Id,
    Attributes::RxErrNoFrameCount::Id,
    Attributes::RxErrUnknownNeighborCount::Id,
    Attributes::RxErrInvalidSrcAddrCount::Id,
    Attributes::RxErrSecCount::Id,
    Attributes::RxErrFcsCount::Id,
    Attributes::RxErrOtherCount::Id,
    Attributes::ActiveTimestamp::Id,
    Attributes::PendingTimestamp::Id,
    Attributes::Delay::Id,
    Attributes::SecurityPolicy::Id,
    Attributes::ChannelPage0Mask::Id,
    Attributes::OperationalDatasetComponents::Id,
    Attributes::ActiveNetworkFaultsList::Id,
    Attributes::FeatureMap::Id,
    Attributes::ClusterRevision::Id,
};
inline constexpr CommandId kEndpoint0EnabledCommands[] = {
    Commands::ResetCounts::Id,
};
} // namespace detail

using FeatureBitmapType = Feature;

inline constexpr std::array<Clusters::StaticApplicationConfig::ClusterConfiguration<FeatureBitmapType>, 1 + 0> kFixedClusterConfig = { {
    {
        .endpointNumber = 0,
        .featureMap = BitFlags<FeatureBitmapType> {
            FeatureBitmapType::kPacketCounts, // feature bit 0x1
            FeatureBitmapType::kErrorCounts, // feature bit 0x2
            FeatureBitmapType::kMLECounts, // feature bit 0x4
            FeatureBitmapType::kMACCounts, // feature bit 0x8
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
    case Attributes::Channel::Id:
      return true;
    case Attributes::NetworkName::Id:
      return true;
    case Attributes::PanId::Id:
      return true;
    case Attributes::ExtendedPanId::Id:
      return true;
    case Attributes::MeshLocalPrefix::Id:
      return true;
    case Attributes::OverrunCount::Id:
      return true;
    case Attributes::NeighborTable::Id:
      return true;
    case Attributes::RouteTable::Id:
      return true;
    case Attributes::PartitionId::Id:
      return true;
    case Attributes::Weighting::Id:
      return true;
    case Attributes::DataVersion::Id:
      return true;
    case Attributes::StableDataVersion::Id:
      return true;
    case Attributes::LeaderRouterId::Id:
      return true;
    case Attributes::DetachedRoleCount::Id:
      return true;
    case Attributes::ChildRoleCount::Id:
      return true;
    case Attributes::RouterRoleCount::Id:
      return true;
    case Attributes::LeaderRoleCount::Id:
      return true;
    case Attributes::AttachAttemptCount::Id:
      return true;
    case Attributes::PartitionIdChangeCount::Id:
      return true;
    case Attributes::BetterPartitionAttachAttemptCount::Id:
      return true;
    case Attributes::ParentChangeCount::Id:
      return true;
    case Attributes::TxTotalCount::Id:
      return true;
    case Attributes::TxUnicastCount::Id:
      return true;
    case Attributes::TxBroadcastCount::Id:
      return true;
    case Attributes::TxAckRequestedCount::Id:
      return true;
    case Attributes::TxAckedCount::Id:
      return true;
    case Attributes::TxNoAckRequestedCount::Id:
      return true;
    case Attributes::TxDataCount::Id:
      return true;
    case Attributes::TxDataPollCount::Id:
      return true;
    case Attributes::TxBeaconCount::Id:
      return true;
    case Attributes::TxBeaconRequestCount::Id:
      return true;
    case Attributes::TxOtherCount::Id:
      return true;
    case Attributes::TxRetryCount::Id:
      return true;
    case Attributes::TxDirectMaxRetryExpiryCount::Id:
      return true;
    case Attributes::TxIndirectMaxRetryExpiryCount::Id:
      return true;
    case Attributes::TxErrCcaCount::Id:
      return true;
    case Attributes::TxErrAbortCount::Id:
      return true;
    case Attributes::TxErrBusyChannelCount::Id:
      return true;
    case Attributes::RxTotalCount::Id:
      return true;
    case Attributes::RxUnicastCount::Id:
      return true;
    case Attributes::RxBroadcastCount::Id:
      return true;
    case Attributes::RxDataCount::Id:
      return true;
    case Attributes::RxDataPollCount::Id:
      return true;
    case Attributes::RxBeaconCount::Id:
      return true;
    case Attributes::RxBeaconRequestCount::Id:
      return true;
    case Attributes::RxOtherCount::Id:
      return true;
    case Attributes::RxAddressFilteredCount::Id:
      return true;
    case Attributes::RxDestAddrFilteredCount::Id:
      return true;
    case Attributes::RxDuplicatedCount::Id:
      return true;
    case Attributes::RxErrNoFrameCount::Id:
      return true;
    case Attributes::RxErrUnknownNeighborCount::Id:
      return true;
    case Attributes::RxErrInvalidSrcAddrCount::Id:
      return true;
    case Attributes::RxErrSecCount::Id:
      return true;
    case Attributes::RxErrFcsCount::Id:
      return true;
    case Attributes::RxErrOtherCount::Id:
      return true;
    case Attributes::ActiveTimestamp::Id:
      return true;
    case Attributes::PendingTimestamp::Id:
      return true;
    case Attributes::Delay::Id:
      return true;
    case Attributes::ChannelPage0Mask::Id:
      return true;
    case Attributes::ActiveNetworkFaultsList::Id:
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
    case Commands::ResetCounts::Id:
      return true;
    default:
      return false;
  }
}

} // namespace StaticApplicationConfig
} // namespace ThreadNetworkDiagnostics
} // namespace Clusters
} // namespace app
} // namespace chip