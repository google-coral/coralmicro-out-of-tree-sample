# Example OOT project for Dev Board Micro

This is a "Hello World" out-of-tree project for [Coral Dev Board Micro]
(https://coral.ai/products/dev-board-micro). This serves as a starting point for your own Dev Board
Micro projects.

No code changes are required to get started. Just follow the steps below to clone this project and
all its submodules. Then build it and flash it to your Dev Board Micro.

Alternatively, you can build your project inside the `coralmicro` tree, as described in the
guide to [build apps with FreeRTOS](https://coral.ai/docs/dev-board-micro/freertos/).

**Note:** `coralmicro` with all its submodules needs about 2.5 GB.


## 1. Set up the project

1. Clone this repo:

    ```bash
    git clone https://github.com/google-coral/coralmicro-out-of-tree-sample
    ```

2. Initialize the `coralmicro` submodule:

    ```bash
    cd out-of-tree-sample

    git submodule add https://github.com/google-coral/coralmicro coralmicro

    git submodule update --init --recursive
    ```


## 2. Build the project

```bash
cmake -B out -S .

make -C out -j4
```

To maximize your CPU usage, replace `-j4` with either `-j$(nproc)` on Linux or
`-j$(sysctl -n hw.ncpu)` on Mac.


## 3. Flash it to your board

```bash
python3 coralmicro/scripts/flashtool.py --build_dir out --elf_path out/coralmicro-app
```

Anytime you make changes to the code, rebuild it with the `make` command and flash it again.

**Note:** In addition to specifying the path to your project's ELF file with `elf_path`, it's
necessary to specify the build output directory with `build_dir` because flashtool needs to get
the ELFLoader (bootloader) program from there.

If you followed the guide to [get started with the Dev Board
Micro](https://coral.ai/docs/dev-board-micro/get-started/), then both the `build_dir` and `elf_path`
arguments are probably new to you. That's because when flashing in-tree examples and apps (as we do
in that guide), the `build_dir` is ommitted because the flashtool uses the local `build` directory
by default. Similarly, in-tree examples and apps don't need to specify the ELF file with `elf_path`
because those files are built in the same build directory—we can instead specify just the project
name with `--example` (or `-e`) and `--app` (or `-a`) when flashing these in-tree projects.
