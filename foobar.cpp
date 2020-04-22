#include <pybind11/pybind11.h>
#include <pybind11/embed.h>
#include <iostream>

class Foobar
{
public:
    ~Foobar()
    {
        pybind11::gil_scoped_release release;
    }

    void hello()
    {
        std::cout << "Hello World" << std::endl;
    }
};

PYBIND11_MODULE(py_foobar, m)
{
    pybind11::class_<Foobar>(m, "Foobar")
        .def(pybind11::init<>())
        .def("hello",
             &Foobar::hello,
             pybind11::call_guard<pybind11::gil_scoped_release>());
}
