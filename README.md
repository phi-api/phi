# PHI: A modern C++ library to simplify parallelism

## Introduction

**PHI** is a modern C++ library aiming to simplify parallelism across multiple execution environments. It take advantages of previous experience with GrPPI developed previously and where many lessons were learnt. To achieve simplification it introduces an extra level of indirection between user code and existing parallel programming frameworks.

**PHI** basic design principles are:
 1. Higly adhere to principles of patterns for structured parallelism.
 2. Clear separation between the structure of computation and the execution of such computation.
 3. Support multiple execution models.

### Execution models

The list of execution models that PHI aims to support includes:

  * Sequential execution.
  * ISO C++ Threads.
  * OpenMP.
  * OneTBB.
  * FastFlow.
  * SkePU.
  * CUDA.
  * SYCL.

Some patterns may support hybrid execution models where different computations are served by different coexisiting models.

### Supported patterns

**PHI** aims to support three categories of patterns:

  * Data parallel patterns.
  * Task parallel patterns.
  * Stream parallel patterns.
  
## Install and use instructions

TODO.




