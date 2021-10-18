# Add Valiant as a submodule
```
git submodule add https://github.com/google-coral/coralmicro valiant
git submodule update --init --recursive
```

# Minimal CMakeLists.txt
```
cmake_minimum_required(VERSION 3.13)
include(${CMAKE_SOURCE_DIR}/valiant/CMakeLists.txt)
project(valiant-app)
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