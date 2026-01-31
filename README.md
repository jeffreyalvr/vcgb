# vcgb

A boilerplate structure for creating OpenGL + GLAD + GLFW projects using VSCode.  
_vcgb stands for VSCode GLFW/glad Boilerplate._

### Important

By default I am using Visual Studio 2022 Community Compiler Toolchain (MSVC kit) to run in VSCode.

If you don’t have Visual Studio installed, you can use other compilers like MinGW-w64 or CLang/GCC.

Ensure that you select the appropriate CMake kit in VSCode to match your installed compiler (see in Setup #3 step A), then configure, build, and run the project as usual.

## Features

- Uses CMake for project configuration and build management.
- Includes GLFW as a Git submodule.
- Includes GLAD 4.6 as a normal module.
- Preconfigured `.vscode` folder with launch and build tasks for convenience.

## Getting Started

### Setup

1.  **Clone the repo including submodules:**

    ```bash
    git clone --recurse-submodules git@github.com:jeffreyalvr/vcgb.git
    ```

    > 💡 If you cloned without `--recurse-submodules`, you can initialize and update submodules later:

    ```bash
    git submodule update --init --recursive
    ```

    > 💡 GLAD is already included as a normal module in `external/`.
    > If you want to use a different version or OpenGL loader, you can safely delete the `glad/` folder and replace it.
    > Of course, you'd need to modify `CMakeLists.txt` to match your changes.

2.  **Install the following extensions:**

    a) [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools);  
    b) [C/C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack);  
    c) [CMake](https://marketplace.visualstudio.com/items?itemName=twxs.cmake);  
    d) [Cmake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools).

3.  **Configure and Build**

    > With VSCode open on the project, press `Ctrl + Shift + P` and:

    a) Select the desired CMake kit (in this case, we use MVSC, which is named Visual Studio 2022 Release);  
    b) Run **CMake Configure** (only needed once or after modifying CMakeLists.txt);  
    c) Run **CMake Build**;  
    d) Press Ctrl+Shift+P or Cmd+Shift+P and type **CMake Run Without Debugging** (you can get the shortcut or modify it later).

    _ℹ️ Tip: You can customize the launch behavior in '.vscode/launch.json'._
    _MacOS uses the same configuration as Linux._

### Boilerplate Structure

```bash
vcgb/
├── .vscode/
│   └── launch.json          # VSCode launch config
├── external/
│   ├── glfw/                # GLFW as a git submodule
│   └── glad/                # GLAD (using OpenGL 4.6) as a normal module
├── src/
│   ├── Window.cpp           # Window source file
│   └── Window.h             # Window header file
├── CMakeLists.txt           # Project build instructions
├── README.md                # Project documentation
├── LICENSE                  # Open-source license
└── main.cpp                 # Main application code
```
