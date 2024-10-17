
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

#ifndef PHI_OMP_HPP
#define PHI_OMP_HPP

#include <ranges>

#include <gsl/gsl>

namespace phi {
  class omp_execution {
    public:
      template <typename Transformer, std::ranges::input_range inout_range>
        requires std::ranges::output_range<inout_range, std::ranges::range_value_t<inout_range>>
      void run(map<Transformer> mapper, inout_range & inout) {
        auto const size = std::size(inout);
#pragma omp parallel for
        for (std::size_t i = 0; i < size; ++i) { inout[i] = mapper(inout[i]); };
      }

      template <typename Transformer, std::ranges::input_range in_range,
                std::ranges::output_range<std::ranges::range_value_t<in_range>> out_range>
      void run(map<Transformer> mapper, in_range in, out_range out) {
        Expects(std::size(in) == std::size(out));

        auto const size = std::size(in);
#pragma omp parallel for
        for (std::size_t i = 0; i < size; ++i) { out[i] = mapper(in[i]); }
      }
  };
}  // namespace phi

#endif  // PHI_OMP_HPP
