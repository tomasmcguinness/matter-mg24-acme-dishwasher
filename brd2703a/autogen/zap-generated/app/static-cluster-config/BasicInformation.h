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
// Application configuration for BasicInformation based on EMBER configuration
#pragma once

#include <app/util/cluster-config.h>
#include <clusters/BasicInformation/AttributeIds.h>
#include <clusters/BasicInformation/CommandIds.h>
#include <clusters/BasicInformation/Enums.h>

#include <array>

namespace chip {
namespace app {
namespace Clusters {
namespace BasicInformation {
namespace StaticApplicationConfig {
namespace detail {
inline constexpr AttributeId kEndpoint0EnabledAttributes[] = {
    Attributes::DataModelRevision::Id,
    Attributes::VendorName::Id,
    Attributes::VendorID::Id,
    Attributes::ProductName::Id,
    Attributes::ProductID::Id,
    Attributes::NodeLabel::Id,
    Attributes::Location::Id,
    Attributes::HardwareVersion::Id,
    Attributes::HardwareVersionString::Id,
    Attributes::SoftwareVersion::Id,
    Attributes::SoftwareVersionString::Id,
    Attributes::ManufacturingDate::Id,
    Attributes::PartNumber::Id,
    Attributes::ProductURL::Id,
    Attributes::ProductLabel::Id,
    Attributes::SerialNumber::Id,
    Attributes::LocalConfigDisabled::Id,
    Attributes::UniqueID::Id,
    Attributes::CapabilityMinima::Id,
    Attributes::SpecificationVersion::Id,
    Attributes::MaxPathsPerInvoke::Id,
    Attributes::ConfigurationVersion::Id,
    Attributes::FeatureMap::Id,
    Attributes::ClusterRevision::Id,
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
            Span<const CommandId>(),
    },
} };

// If a specific attribute is supported at all across all endpoint static instantiations
inline constexpr bool IsAttributeEnabledOnSomeEndpoint(AttributeId attributeId) {
  switch (attributeId) {
    case Attributes::DataModelRevision::Id:
      return true;
    case Attributes::VendorName::Id:
      return true;
    case Attributes::VendorID::Id:
      return true;
    case Attributes::ProductName::Id:
      return true;
    case Attributes::ProductID::Id:
      return true;
    case Attributes::NodeLabel::Id:
      return true;
    case Attributes::Location::Id:
      return true;
    case Attributes::HardwareVersion::Id:
      return true;
    case Attributes::HardwareVersionString::Id:
      return true;
    case Attributes::SoftwareVersion::Id:
      return true;
    case Attributes::SoftwareVersionString::Id:
      return true;
    case Attributes::ManufacturingDate::Id:
      return true;
    case Attributes::PartNumber::Id:
      return true;
    case Attributes::ProductURL::Id:
      return true;
    case Attributes::ProductLabel::Id:
      return true;
    case Attributes::SerialNumber::Id:
      return true;
    case Attributes::LocalConfigDisabled::Id:
      return true;
    case Attributes::UniqueID::Id:
      return true;
    case Attributes::SpecificationVersion::Id:
      return true;
    case Attributes::MaxPathsPerInvoke::Id:
      return true;
    case Attributes::ConfigurationVersion::Id:
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
    default:
      return false;
  }
}

} // namespace StaticApplicationConfig
} // namespace BasicInformation
} // namespace Clusters
} // namespace app
} // namespace chip