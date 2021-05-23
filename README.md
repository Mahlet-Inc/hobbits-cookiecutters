## Using hobbits cookiecutters

Prerequisites:

  1. CMake and C++ Toolchain
  2. Python
  3. Cookiecutter `pip install cookiecutter`
  4. Conan `pip install conan`

Creating and building an Operator plugin:

```
# Run cookiecutter to create the boilerplate code for the project
cookiecutter gh:Mahlet-Inc/hobbits-cookiecutters --directory operator

# Answer the prompts to name your plugin

# create a build directory
cd MyPlugin
mkdir build
cd build

# run Conan to get dependencies
conan install .. --build=missing

# build and install the plugin with CMake
cmake ..
cmake --build .
cmake --install .
```