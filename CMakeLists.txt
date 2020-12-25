cmake_minimum_required(VERSION 3.14)

project(rapidcheck_experiment LANGUAGES CXX VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_VERBOSE_MAKEFILE on)

set(installDir ${CMAKE_CURRENT_BINARY_DIR}/install)
include(ExternalProject)
ExternalProject_Add(RapidCheck
  URL        https://github.com/emil-e/rapidcheck/archive/master.tar.gz
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=${installDir}
             -DCMAKE_PREFIX_PATH:PATH=${installDir}
)
add_library(RapidCheck::rapidcheck STATIC IMPORTED)
set_target_properties(RapidCheck::rapidcheck PROPERTIES
  IMPORTED_LOCATION   ${installDir}/lib/librapidcheck.a
)
include_directories(${installDir}/include)

add_subdirectory(source)
