cmake_minimum_required(VERSION 3.16)
project(Udemy_Design_Patters)

set(CMAKE_CXX_STANDARD 14)
set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS})

add_executable(Udemy_Design_Patters builder.cpp Person.cpp Person.h PersonBuilder.hpp PersonBuilder.cpp PersonJobBuilder.h PersonAddressBuilder.h)
target_link_libraries (Udemy_Design_Patters ${Boost_LIBRARIES})
