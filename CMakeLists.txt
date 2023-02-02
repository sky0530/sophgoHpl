
project(sophgoHpl LANGUAGES CXX)
cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

set(CMAKE_C_COMPILER "g++")

option(HPL_BLAS_DIR "Path to CPU BLAS library" ${CMAKE_CURRENT_SOURCE_DIR}/tpl/openblas)
option(HPL_MPI_DIR  "Path to MPI library" ${CMAKE_CURRENT_SOURCE_DIR}/tpl/openmpi)

# Dependencies
include(cmake/Dependencies.cmake)

# Build flags
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# HPL sources
file(GLOB_RECURSE sophgoHplSource RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cc")
file(GLOB_RECURSE sophgoHplInc RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "include/*.h")
# message(sophgoHplSource="${sophgoHplSource}")

file(GLOB_RECURSE sophgoHplDeviceSource RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "test/*.cc")
# message(sophgoHplDeviceSource="${sophgoHplDeviceSource}")

list(APPEND CMAKE_HOST_FLAGS "")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  list(APPEND CMAKE_HOST_FLAGS "-O0;-g")
else()
  list(APPEND CMAKE_HOST_FLAGS "-O3;-march=native")
endif()

# add_library(hplSrc ${sophgoHplSource} ${sophgoHplInc} )
# set_target_properties(hplSrc PROPERTIES LINKER_LANGUAGE CXX)

# list(REMOVE_ITEM sophgoHplDeviceSource test/HPL_pddriver.c)
# message(sophgoHplDeviceSource="${sophgoHplDeviceSource}")

# add_library(hplTest ${sophgoHplDeviceSource} ${sophgoHplInc} )
# set_target_properties(hplTest PROPERTIES LINKER_LANGUAGE CXX)

add_executable(${PROJECT_NAME} ${sophgoHplSource} ${sophgoHplDeviceSource})
# add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/test/HPL_pddriver.cc)
# add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/test/hello_world.cc)
# message(sophgoHplDeviceSource="${CMAKE_CURRENT_SOURCE_DIR}/test/HPL_pddriver.c")
# target_link_libraries(${PROJECT_NAME} PRIVATE hplSrc hplTest)

target_compile_options(${PROJECT_NAME} PRIVATE ${CMAKE_HOST_FLAGS})


target_include_directories(${PROJECT_NAME}
                           PRIVATE
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                           $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>)

# target_include_directories(${PROJECT_NAME}
#                            PRIVATE
#                            /home/weijun/mpich-3.2.1/src/include/)

# MPI
target_link_libraries(${PROJECT_NAME} PRIVATE MPI::MPI_CXX)

# OpenMP
target_link_libraries(${PROJECT_NAME} PRIVATE OpenMP::OpenMP_CXX)

# Target link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE BLAS::BLAS)
# target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/tpl/blis/lib/libblis.a)
# target_link_libraries(${PROJECT_NAME} PRIVATE /usr/local/lib/blas_LINUX.a)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_link_options(${PROJECT_NAME} PRIVATE "-fopenmp")