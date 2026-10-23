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
// Application configuration for OperationalCredentials based on EMBER configuration
#pragma once

#include <app/util/cluster-config.h>
#include <clusters/OperationalCredentials/AttributeIds.h>
#include <clusters/OperationalCredentials/CommandIds.h>
#include <clusters/OperationalCredentials/Enums.h>

#include <array>

namespace chip {
namespace app {
namespace Clusters {
namespace OperationalCredentials {
namespace StaticApplicationConfig {
namespace detail {
inline constexpr AttributeId kEndpoint0EnabledAttributes[] = {
    Attributes::NOCs::Id,
    Attributes::Fabrics::Id,
    Attributes::SupportedFabrics::Id,
    Attributes::CommissionedFabrics::Id,
    Attributes::TrustedRootCertificates::Id,
    Attributes::CurrentFabricIndex::Id,
    Attributes::GeneratedCommandList::Id,
    Attributes::AcceptedCommandList::Id,
    Attributes::AttributeList::Id,
    Attributes::FeatureMap::Id,
    Attributes::ClusterRevision::Id,
};
inline constexpr CommandId kEndpoint0EnabledCommands[] = {
    Commands::AttestationRequest::Id,
    Commands::CertificateChainRequest::Id,
    Commands::CSRRequest::Id,
    Commands::AddNOC::Id,
    Commands::UpdateNOC::Id,
    Commands::UpdateFabricLabel::Id,
    Commands::RemoveFabric::Id,
    Commands::AddTrustedRootCertificate::Id,
    Commands::SetVIDVerificationStatement::Id,
    Commands::SignVIDVerificationRequest::Id,
};
} // namespace detail

using FeatureBitmapType = Clusters::StaticApplicationConfig::NoFeatureFlagsDefined;

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
    case Attributes::NOCs::Id:
      return true;
    case Attributes::Fabrics::Id:
      return true;
    case Attributes::SupportedFabrics::Id:
      return true;
    case Attributes::CommissionedFabrics::Id:
      return true;
    case Attributes::TrustedRootCertificates::Id:
      return true;
    case Attributes::CurrentFabricIndex::Id:
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
    case Commands::AttestationRequest::Id:
      return true;
    case Commands::CertificateChainRequest::Id:
      return true;
    case Commands::CSRRequest::Id:
      return true;
    case Commands::AddNOC::Id:
      return true;
    case Commands::UpdateNOC::Id:
      return true;
    case Commands::UpdateFabricLabel::Id:
      return true;
    case Commands::RemoveFabric::Id:
      return true;
    case Commands::AddTrustedRootCertificate::Id:
      return true;
    case Commands::SetVIDVerificationStatement::Id:
      return true;
    case Commands::SignVIDVerificationRequest::Id:
      return true;
    default:
      return false;
  }
}

} // namespace StaticApplicationConfig
} // namespace OperationalCredentials
} // namespace Clusters
} // namespace app
} // namespace chip