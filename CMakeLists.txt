cmake_minimum_required(VERSION 3.10)

project(simon)

set(BUTTONS_NUMBER 4 CACHE STRING "Number of buttons")
set(CROSS_COMPILE_ARM OFF CACHE BOOL "Cross-compile for ARM platform")

if(CROSS_COMPILE_ARM)
    set(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)
    set(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)
    set(CMAKE_SYSROOT /usr/bin/)
    set(OUTPUT_NAME arm_simon)
else()
    set(OUTPUT_NAME simon)
endif()

# Set the source directory
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/code")
file(GLOB SOURCE_FILES "${SOURCE_DIR}/*.cpp" "${SOURCE_DIR}/*.h")

add_executable(${OUTPUT_NAME} ${SOURCE_FILES})

target_compile_definitions(${OUTPUT_NAME} PRIVATE
    $<$<BOOL:${BUTTONS_NUMBER}>:BUTTONS_NUMBER=${BUTTONS_NUMBER}>
)

message(STATUS "BUTTONS_NUMBER: ${BUTTONS_NUMBER}")
message(STATUS "CROSS_COMPILE_ARM: ${CROSS_COMPILE_ARM}")

# Clear the cache
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/CMakeCache.txt" OR
   EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/CMakeFiles")
    execute_process(
        COMMAND "${CMAKE_COMMAND}" -E rm -rf CMakeCache.txt CMakeFiles
        RESULT_VARIABLE CLEAR_CACHE_RESULT
    )
    if(CLEAR_CACHE_RESULT EQUAL 0)
        set(BUTTONS_NUMBER 4 CACHE STRING "Number of buttons" FORCE)
        set(CROSS_COMPILE_ARM OFF CACHE BOOL "Cross-compile for ARM platform" FORCE)
    else()
        message(FATAL_ERROR "Failed to clear the CMake cache.")
    endif()
endif()
