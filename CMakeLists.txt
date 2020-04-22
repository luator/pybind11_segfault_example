cmake_minimum_required(VERSION 3.1)
project(pybind11_test)

add_subdirectory(pybind11)

include_directories(pybind11/include ${PYTHON_INCLUDE_DIRS})

add_executable(cpp_test main.cpp foobar.cpp)
target_link_libraries(cpp_test ${pybind11_LIBRARIES} ${PYTHON_LIBRARIES})

pybind11_add_module(py_foobar foobar.cpp)
