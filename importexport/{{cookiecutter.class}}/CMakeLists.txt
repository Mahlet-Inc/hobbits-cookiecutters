
cmake_minimum_required(VERSION 3.12)
project("{{ cookiecutter.class }}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(BUILD_SHARED_LIBS ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
include(conan_qt_executables_variables)

if (SET_QT_DEBUG)
    add_compile_definitions(QT_NO_DEBUG=0)
else()
    add_compile_definitions(QT_NO_DEBUG=1)
endif()

set(SRCFILES
    {{ cookiecutter.class_file }}.cpp
    {{ cookiecutter.import_editor_file }}.cpp
    {{ cookiecutter.export_editor_file }}.cpp)
set(RCFILES
    {{ cookiecutter.import_editor_file }}.ui
    {{ cookiecutter.export_editor_file }}.ui)
set(HDRFILES
    {{ cookiecutter.class_file }}.h
    {{ cookiecutter.import_editor_file }}.h
    {{ cookiecutter.export_editor_file }}.h) # this is not necessary for building, but groups the files better in IDEs

add_library("{{ cookiecutter.class }}" "${SRCFILES}" "${RCFILES}" "${HDRFILES}")
target_link_libraries("{{ cookiecutter.class }}" ${CONAN_LIBS})

install(TARGETS "{{ cookiecutter.class }}"
        DESTINATION "~/.local/share/hobbits/plugins/importerexporters")