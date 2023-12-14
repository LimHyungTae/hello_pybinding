#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;


namespace image
{
    void to_red(py::array &img);
}
