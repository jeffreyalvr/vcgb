# vcgb

A boilerplate structure for creating OpenGL + GLFW projects using VSCode.

## Features

- Uses CMake for project configuration and build management.
- Includes GLFW as a Git submodule.
- Preconfigured `.vscode` folder with launch and build tasks for convenience.

## Getting Started

### Setup

1.  **Clone the repo including submodules:**

    ```bash
    git clone --recurse-submodules git@github.com:jeffreyalvr/vcgb.git
    ```

    >💡 If you cloned without `--recurse-submodules`, you can initialize and update submodules later:

    ```bash
    git submodule update --init --recursive
    ```

2.  **Install the following extensions:**

    a) [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools);
    b) [C/C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack);
    c) [CMake](https://marketplace.visualstudio.com/items?itemName=twxs.cmake);
    d) [Cmake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools).

3. **Configure and Build**

    > With VSCode open on the project, press `Ctrl + Shift + P` and:
    
    a) Select the desired CMake kit (e.g. Visual Studio 2022 Release x64).
    b) Run **CMake Configure** (only needed once or after modifying CMakeLists.txt).
    c) Run **CMake Build**.
    d) Press **F5** to launch the executable.

    _ℹ️ Tip: You can customize the launch behavior in '.vscode/launch.json'._

### Boilerplate Structure

```bash
vcgb/
├── .vscode/
│   └── launch.json          # VSCode launch config
├── external/
│   └── glfw/                # GLFW as a git submodule
├── src/
│   └── main.cpp             # Main application code
├── CMakeLists.txt           # Project build instructions
├── README.md                # Project documentation
└── LICENSE                  # Open-source license
```
