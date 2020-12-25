cmake_minimum_required(VERSION 3.14)

project(rapidcheck_experiment LANGUAGES CXX VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_VERBOSE_MAKEFILE on)

set(installDir ${CMAKE_CURRENT_BINARY_DIR}/install)

include(ExternalProject)
ExternalProject_Add(GoogleTest
  GIT_REPOSITORY    https://github.com/google/googletest.git
  # This is a commit after release-1.10.0 for which
  # gmock understands noexcept function qualifiers
  # and for which usage of std::result_of has been
  # discontinued.
  # (copied from https://github.com/facebookexperimental/libunifex/blob/37bdf85852ec1674aeb7468d0d19072c9a3e44bf/cmake/CMakeLists.txt.in)
  GIT_TAG           61f010d703b32de9bfb20ab90ece38ab2f25977f
  CMAKE_ARGS        -DCMAKE_INSTALL_PREFIX:PATH=${installDir}
)
add_library(gtest STATIC IMPORTED)
add_library(gtest_main STATIC IMPORTED)
set_target_properties(gtest PROPERTIES
  IMPORTED_LOCATION ${installDir}/lib/libgtest.a
)
set_target_properties(gtest_main PROPERTIES
  IMPORTED_LOCATION ${installDir}/lib/libgtest_main.a
)

#ExternalProject_Add(RapidCheck
#  URL               https://github.com/emil-e/rapidcheck/archive/master.tar.gz
#  CMAKE_ARGS        -DCMAKE_INSTALL_PREFIX:PATH=${installDir}
#)
#add_library(RapidCheck::rapidcheck STATIC IMPORTED)
#set_target_properties(RapidCheck::rapidcheck PROPERTIES
#  IMPORTED_LOCATION ${installDir}/lib/librapidcheck.a
#)
include_directories(${installDir}/include)

add_subdirectory(source)
