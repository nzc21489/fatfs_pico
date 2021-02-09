cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(FatFs_test C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

set(INCLUDE_DIR
  ${PROJECT_SOURCE_DIR}/mmc_pico
  ${PROJECT_SOURCE_DIR}/fatfs
  ${PICO_SDK_PATH}
)

include_directories("${INCLUDE_DIR}")

add_subdirectory(example)
add_subdirectory(mmc_pico)
add_subdirectory(fatfs)
