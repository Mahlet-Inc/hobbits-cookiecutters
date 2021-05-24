# Hobbits Cookiecutters

This collection of cookiecutters simplifies the process of building plugins for
[Hobbits](https://github.com/Mahlet-Inc/hobbits). Cookiecutters are templates
that are meant to be used with the tool 
[Cookiecutter](https://cookiecutter.readthedocs.io/en/stable/README.html)).


## Using Python Plugin Cookiecutters

Available python plugin cookiecutter directories are `python-operator`,
`python-analyzer`, `python-display`, `python-exporter`, and `python-importer`

Prerequisites:
  1. Python
  2. Cookiecutter `pip install cookiecutter`


Creating and building an Operator plugin:

```
# Run cookiecutter to create the boilerplate code for the plugin
cookiecutter gh:Mahlet-Inc/hobbits-cookiecutters --directory python-operator

# Answer the prompts to name your plugin

# Place the generated folder into the python_operators folder where hobbits
# looks for plugins
mv py-operator ~/.local/share/hobbits/plugins/python_operators/

# plugin paths can be set in hobbits via the Edit->Preferences menu in the
# "Plugin Loader" section
```


## Using C++ Plugin Cookiecutters

Available C++ plugin cookiecutter directories are `operator`, `analyzer`,
`display`, `importerexporter`

Prerequisites:

  1. CMake, C++ Toolchain, and Ninja Build
  2. Python
  3. Cookiecutter `pip install cookiecutter`
  4. Conan `pip install conan`
  5. Conan remote with hobbits stuff
     ```
     conan remote add hobbits https://helloadam.jfrog.io/artifactory/api/conan/conan
     ```

Creating and building an Operator plugin:

```
# Run cookiecutter to create the boilerplate code for the plugin project
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

# you can also manually install the resulting library into any of the folders
# that you have configured Hobbits to look for plugins. plugin paths can be set
# in the Hobbits GUI via the Edit->Preferences menu in the "Plugin Loader"
# section
```