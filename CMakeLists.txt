cmake_minimum_required(VERSION 3.16)
project(Udemy_Design_Patters)

set(CMAKE_CXX_STANDARD 14)
set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework serialization)
include_directories (${Boost_INCLUDE_DIRS})

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

set(SOURCE_FILES main.cpp)

add_executable(Udemy_Design_Patterns ${SOURCE_FILES})
target_link_libraries (Udemy_Design_Patterns gtest gtest_main ${Boost_LIBRARIES})
