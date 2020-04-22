Minimal Example for pybind11 SegFault on GIL Release
====================================================


This is a minimal example for showing the segmentation fault happening when
using `pybind11::gil_scoped_release` in a pure C++ context (i.e. when no Python
interpreter is running).

A simple class `Foobar` is defined and Python bindings are created.  In the
class `pybind11::gil_scoped_release` is used to release the GIL in the
destructor.

When using the class from Python, everything is good.  When using it directly
in C++, the use of `pybind11::gil_scoped_release` leads to a segmentation
fault.


## Build

Assumes pybind11 is cloned to a subdirectory called `pybind11` in this
directory.

    mkdir build
    cd build
    cmake ..
    make


## Run

Python:

    $ python3 py_test.py
    Hello World


C++:

    $ build/cpp_test 
    Hello World
    [1]    10929 segmentation fault (core dumped)  build/cpp_test
