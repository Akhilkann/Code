cmake_minimum_required(VERSION 3.13)
project(MyProject)

set(CMAKE_CXX_STANDARD 14)

#add_subdirectory(usr/src/googletest) # Assuming googletest is a subdirectory

include_directories(usr/src/googletest/googletest/include)
include_directories(usr/src/googletest/googlemock/include)

add_executable(my_test my_test.cpp)
target_link_libraries(my_test gtest gtest_main)


