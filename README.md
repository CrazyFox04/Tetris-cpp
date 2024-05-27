# Tetris Project

This project is a Tetris game implementation in C++ using modern CMake. It consists of various modules such as model,
console view, QT view, tools, and controller, each responsible for different aspects of the game.

## Prerequisites

- CMake 3.27 or higher
- C++ compiler with C++20 support
- QT6 (optional, only needed for the QT view)

## Build

This project uses modern CMake to manage the build process.
The project is composed of <u>**5 libraries**</u> that can be built separately and a main executable that links all the
libraries together.

### <u style="color: red">First step</u> : Configure build directory

We need to create a build directory and configure the project using CMake.
It's in this directory that the build files will be generated and where the following other build commands need to be
executed.

```bash
mkdir build
cd build
cmake ..
```

### Build all

Now that the project is configured, we can build the project by running the following command in the build directory:

```bash
cmake --build .
```

### Build each library separately

If you want to build each library separately, you can do so by specifying the target name.
Please note that all target will not compile the library and not link it with the main executable.

As the build all command, it needs to be executed in the build directory.
> The libraries format are OS specific !

#### Model package

```bash
cmake --build . --target tetris_model 
```

#### Tools package

```bash
cmmake --build . --target tetris_tools
```

#### View package

```bash
cmake --build . --target tetris_view_console
```

```bash
cmake --build . --target tetris_view_qtApp
```

#### Controller package

```bash
cmake --build . --target tetris_controller
```

#### Main executable

```bash
cmake --build . --target tetris
```
The main executable will link all the libraries together. 
If you compile it with Qt, the main executable will automatically launch the QT view.
In this case, you can specify -c to launch the console view instead.

#### Test executable

```bash
cmake --build . --target tetris_test
```

## Run

### Main executable

After building the project, you can run the main executable by running the following command:

```bash
cd src/
./tetris
```
If you want to run the console view instead of the QT view, you can specify the -c option: `./tetris -c`

### Test executable

After building the project, you can run the test executable by running the following command:

```bash
cd test/
./tetris_test
```

## Documentation

Documentation for the project can be generated using Doxygen. Follow these steps to generate the documentation:

1) Ensure Doxygen is installed on your system.
2) Run the following commands from the root directory of the project :

```bash
cd build/
cmake --build . --target doc_doxygen
```

3) Open the generated documentation by opening the following file in a web browser.

> Note : The documentation is generated in __the "documentation/gen_doxygen/html" folder__ <u>in the root directory</u>
> of the project.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
