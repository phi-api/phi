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

#include "phi/map.hpp"
#include "phi/dyn.hpp"

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

int main() {
  // Generate a sequence of random doubles
  [[maybe_unused]] constexpr int max = 10'000'000;

  std::random_device rd;
  std::uniform_real_distribution<double> gen{-100.0, 100.0};
  std::vector<double> values;
  std::ranges::generate_n(std::back_inserter(values), max, [&]() {
    return gen(rd);
  });

  using namespace std::chrono;

  phi::dynamic_execution ex;

  auto start = high_resolution_clock::now();

  auto mapping = phi::map([](auto x) {
    return 2 * x;
  });
  ex.run(mapping, values, values);

  auto stop     = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);

  std::cout << std::format("Time taken by function: {}\n", duration);

  std::ranges::copy_n(values.begin(), 10, std::ostream_iterator<double>(std::cout, " "));
}
