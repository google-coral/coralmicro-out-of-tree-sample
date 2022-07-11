cmake_minimum_required(VERSION 3.13)

# Toolchain must be set before project() call.
if (NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_LIST_DIR}/valiant/cmake/toolchain-arm-none-eabi-gcc.cmake)
endif()

project(valiant-app)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(valiant)
add_subdirectory(valiant)

add_executable_m7(valiant-app
        hello_world_cm7.cc
        M4_EXECUTABLE
        valiant-app-m4
        DATA
        hello_world_cm7.cc
)

target_link_libraries(valiant-app
        libs_base-m7_freertos
        libs_testconv1
)

add_executable_m4(valiant-app-m4
        hello_world_cm4.cc
)

target_link_libraries(valiant-app-m4
        libs_base-m4_freertos
)
