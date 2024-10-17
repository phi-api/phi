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

#ifndef PHI_MAP_HPP
#define PHI_MAP_HPP

#include <utility>

namespace phi {

template <typename Transformer>
struct map {
  Transformer transformer_;

  decltype(auto) operator()(auto && ... args) {
    return transformer_(std::forward<decltype(args)>(args)...);
  }
};

}

#endif // PHI_MAP_HPP
