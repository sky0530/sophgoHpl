# Git
find_package(Git REQUIRED)

#Look for a BLAS lib
# For some reason cmake doesn't let us manually specify a search path in FindBLAS,
# so let's add our own libraries
get_filename_component(HPL_BLAS_DIR ${HPL_BLAS_DIR} ABSOLUTE)

# Look for BLIS in the provided path
find_library(BLAS_LIBRARIES NAMES blis
             PATHS ${HPL_BLAS_DIR}
             NO_DEFAULT_PATH)

if (NOT BLAS_LIBRARIES)
  # If we dont find BLIS, look for openblas
  find_library(BLAS_LIBRARIES NAMES openblas
               PATHS ${HPL_BLAS_DIR}
               NO_DEFAULT_PATH)
endif()
if (NOT BLAS_LIBRARIES)
  # If we dont find BLIS or openBLAS, look for MKL
  find_library(BLAS_LIBRARIES NAMES mkl_core
               PATHS ${HPL_BLAS_DIR}
               NO_DEFAULT_PATH)
  find_library(BLAS_SEQ_LIBRARIES NAMES mkl_sequential
               PATHS ${HPL_BLAS_DIR}
               NO_DEFAULT_PATH)
  find_library(BLAS_LP64_LIBRARIES NAMES mkl_intel_lp64
               PATHS ${HPL_BLAS_DIR}
               NO_DEFAULT_PATH)
endif()

if (BLAS_LIBRARIES)
  message(STATUS "Found BLAS: ${BLAS_LIBRARIES}")
else()
  # If we still havent found a blas library, maybe cmake will?
  find_package(BLAS REQUIRED)
endif()
# add_library(BLAS::BLAS IMPORTED INTERFACE)
# set_property(TARGET BLAS::BLAS PROPERTY INTERFACE_LINK_LIBRARIES  "${BLAS_LP64_LIBRARIES};${BLAS_SEQ_LIBRARIES};${BLAS_LIBRARIES}")

# Find OpenMP package
find_package(OpenMP)
if (NOT OPENMP_FOUND)
  message("-- OpenMP not found. Compiling WITHOUT OpenMP support.")
else()
  option(HPL_OPENMP "Compile WITH OpenMP support." ON)
endif()

# MPI
set(MPI_HOME ${HPL_MPI_DIR})
find_package(MPI REQUIRED)

# # Find HIP package
# find_package(HIP REQUIRED)
