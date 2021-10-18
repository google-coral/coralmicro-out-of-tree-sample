cmake_minimum_required(VERSION 3.13)
include(${CMAKE_SOURCE_DIR}/valiant/CMakeLists.txt)
project(valiant-app)

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
