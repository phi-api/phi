enable_testing()
add_executable(utest
    config.cpp
    map.cpp)

target_link_libraries(utest GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(utest)