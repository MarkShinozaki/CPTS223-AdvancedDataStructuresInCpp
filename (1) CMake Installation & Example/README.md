# Install cmake on WSL and Build Example

## How to Install cmake on WSL

- On your WSL, cmake is not installed by default.

- Use the command below to install cmake:
  
```sh
sudo apt install cmake
```

- Wait for the installation to complete.


# Example of Using cmake to Build a Project on WSL

### 1. **Clone the example repository:**

- git clone https://github.com/DataOceanLab/CPTS-223-Examples.git

### 2. **Navigate to new directory:**

- cd CPTS-223-Examples

### 3. **Go into the working directory:**
   
- cd cmake-example

### 4. **List all items under the working directory:**

- ls

### 5. **Create a new directory "build" in the working directory:**

- mkdir build

### 6. **Check whether the "build" directory was created successfully:**

- ls

### 7. **Run cmake to configure the project:**

- cmake -S . -B build

- `S`: The path to the source files. `.` represents the current directory, which is `~/CPTS-223-Examples/cmake-example`.
- `B`: The path to build the project, where the executable files will be found. Here we set the newly created directory "build" as the build path.

### 8. **Build the project:**

- `--build`: The command for building the project according to the configuration in `CMakeLists.txt`.
- The second "build" is the newly created directory "build".

### 9. **Go to the "build" directory to find the built executable `CPTS_223_Cmake_Example`.**


## Implementing a New Feature into the Project Using VS Code

### 1. Create an `adder.cpp` file to implement addition.

### 2. In `functions.h`, add the declaration of `adder`.

### 3. In `main.cpp`, use `adder` to compute `3 + 4`.

### 4. In `CMakeLists.txt`, add `adder.cpp` to the `add_executable` statement:

#### Original
- add_executable(CPTS_223_CMake_Example main.cpp factorial.cpp message.cpp)

#### New
- add_executable(CPTS_223_CMake_Example main.cpp factorial.cpp message.cpp adder.cpp)


### 5. Follow the previous steps to re-build the project:

- `mkdir build`
- `cmake -S . -B build`
- `cmake --build build`
- Run the executable
- Get the output

## How to Install cmake on MacOS Using Homebrew

### 1. Ensure cmake is not already installed.

### 2. Install cmake using Homebrew:

```
brew install cmake
```

### 3. After installation, verify that cmake is installed:

```
cmake --version
```

Check the following links for installing Homebrew on MacOS:
- [Installing Homebrew on MacOS](https://www.igeeksblog.com/how-to-install-homebrew-on-mac/)
- [OpenGL Compliation on Mac/Linux](https://cse.engineering.nyu.edu/cs653/OpenGLCompilationMacLinux8.pdf)










