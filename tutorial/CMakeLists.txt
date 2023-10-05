set(LLVM_ROOT "../" CACHE PATH "root")

if (NOT EXISTS ${LLVM_ROOT}/include/llvm )
    message(FATAL_ERROR "LLVM_ROOT (${LLVM_ROOT}) is invalid")
endif()

list(APPEND CMAKE_PREFIX_PATH "${LLVM_ROOT}/share/llvm/cmake")
find_package(LLVM REQUIRED CONFIG)

list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(HandleLLVMOptions)
include(AddLLVM)

add_definitions ( $ { LLVM_DEFINITIONS })
include_directories ( $ { LLVM_INCLUDE_DIRS })
set (LLVM_RUNTIME_OUTPUT_INTDIR "${CMAKE_BINARY_DIR }/bin/${CMAKE_CFG_INT_DIR}")
set (LLVM_LIBRARY_OUTPUT_INTDIR "${CMAKE_BINARY_DIR }/lib/${CMAKE_CFG_INT_DIR}")

add_subdirectory(MBA)
