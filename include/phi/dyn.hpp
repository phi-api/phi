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

#ifndef PHI_DYN_HPP
#define PHI_DYN_HPP

// #include "phi/seq.hpp"
// #include "phi/omp.hpp"

class dynamic_execution {
  public:
  private:
    class execution_base {
      public:
        virtual ~execution_base() = default;
    };

  template <typename E>
  class execution : public execution_base {
    public:
      execution(const E & e) : e_{e} {}
      virtual ~execution() = default;
      E e_;
  };
};

#endif // PHI_DYN_HPP
