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
#include <phi/map.hpp>

TEST(map, one_param) {
  phi::map mapper{[](int x) {
    return ++x;
  }};
  EXPECT_EQ(mapper(1), 2);
}

TEST(map, two_params) {
  phi::map mapper{[](int x, int y) {
    return x + y;
  }};
  EXPECT_EQ(mapper(1, 2), 3);
}

TEST(map, tree_params) {
  phi::map mapper{[](int x, int y, int z) {
    return x + y + z;
  }};
  EXPECT_EQ(mapper(1, 2, 3), 6);
}

TEST(map)
