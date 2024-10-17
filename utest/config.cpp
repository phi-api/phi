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

#include <gtest/gtest.h>
#include "phi/config.hpp"

TEST(policy, to_string_seq) {
  phi::execution_policy policy = phi::execution_policy::sequential;
  std::string result = phi::to_string(policy);
  EXPECT_EQ(result, "seq");
}

TEST(policy, to_string_omp) {
  phi::execution_policy policy = phi::execution_policy::omp;
  std::string result = phi::to_string(policy);
  EXPECT_EQ(result, "omp");
}

TEST(policy, to_string_invalid) {
  phi::execution_policy policy{-1}; // NOLINT
  EXPECT_THROW(phi::to_string(policy), std::invalid_argument);
}

TEST(policy, to_execution_policy_seq) {
  std::string policy_name = "seq";
  phi::execution_policy result = phi::to_execution_policy(policy_name);
  EXPECT_EQ(result, phi::execution_policy::sequential);
}

TEST(policy, to_execution_policy_omp) {
  std::string policy_name = "omp";
  phi::execution_policy result = phi::to_execution_policy(policy_name);
  EXPECT_EQ(result, phi::execution_policy::omp);
}

TEST(policy, to_execution_policy_invalid) {
  std::string policy_name = "invalid";
  EXPECT_THROW(phi::to_execution_policy(policy_name), std::invalid_argument);
}

TEST(configuration, default_policy) {
  phi::configuration config;
  EXPECT_EQ(config.get_policy(), phi::execution_policy::sequential);
}

TEST(configuration, env_policy_seq) {
  setenv("PHI_EXECUTION", "seq", 1);
  phi::configuration config;
  EXPECT_EQ(config.get_policy(), phi::execution_policy::sequential);
}

TEST(configuration, env_policy_omp) {
  setenv("PHI_EXECUTION", "omp", 1);
  phi::configuration config;
  EXPECT_EQ(config.get_policy(), phi::execution_policy::omp);
}