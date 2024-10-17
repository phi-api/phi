
// Copyright (c) 2024.  Universidad Carlos III de Madrid
//
// Licensed under the Apache License, Version 2.0 (the "License");  you may not use
// this file except in compliance with the License.
//
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software distributed under
// the License is distributed on an "AS IS" BASIS,  WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied.  See the License for the
// specific language governing permissions and  limitations under the License.

#ifndef PHI_CONFIG_HPP
#define PHI_CONFIG_HPP

#include <format>
#include <string>

namespace phi {

  enum class execution_policy : int8_t { sequential, omp };

  /// \brief Converts an execution policy to a string
  /// @param policy The execution policy
  /// @returns The string representation of the execution policy
  /// @exception std::invalid_argument if the policy is not valid
  inline std::string to_string(execution_policy policy) {
    switch (policy) {
      case execution_policy::sequential:
        return "seq";
      case execution_policy::omp:
        return "omp";
    }
    throw std::invalid_argument{std::format("Invalid policiy value: {}", static_cast<int>(policy))};
  }

  /// \brief Converts a string to an execution policy
  /// @param policy_name The string representation of the execution policy
  /// @returns The execution policy enumerator
  /// @exception std::invalid_argument if the string does not represent a valid policy
  inline execution_policy to_execution_policy(std::string_view policy_name) {
    if (policy_name == "default") { return execution_policy::sequential; }
    if (policy_name == "seq") { return execution_policy::sequential; }
    if (policy_name == "omp") { return execution_policy::omp; }
    throw std::invalid_argument{std::format("Invalid policy value: {}", policy_name)};
  }

  /// \brief Phi configuration.
  /// A configuration reads environment variables to set configuration parameters for the library.
  /// If a corresponding environment variable is not set, the default value is used.
  ///
  /// The following configuration parameters are supported:
  /// - PHI_EXECUTION: The execution policy to use.
  class configuration {
    public:
      configuration() : policy_{to_execution_policy(get_environment_value(policy_env_var))} { }

      [[nodiscard]] execution_policy get_policy() const { return policy_; }

    private:
      static std::string get_environment_value(std::string_view const name) {
        // NOLINTNEXTLINE(bugprone-suspicious-stringview-data-usage)
        if (auto const * result = std::getenv(name.data()); result != nullptr) { return result; }
        return "default";
      }

    private:
      execution_policy policy_{execution_policy::sequential};
      static constexpr std::string_view policy_env_var{"PHI_EXECUTION"};
  };

}  // namespace phi

#endif  // PHI_CONFIG_HPP
