# Add Valiant as a submodule
```
git submodule add https://github.com/google-coral/coralmicro valiant
git submodule update --init --recursive
```

# Minimal CMakeLists.txt
```
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
```

Afterwards, the `add_executable_{m4,m7}` and `add_library_{m4,m7}` functions are available for use.

# Building the sample
```
cmake -B build .
make -C build -j$(nproc)
```

# Flash device with the sample
```
valiant/scripts/flashtool.py --build_dir build --elf_path build/valiant-app.stripped
```
