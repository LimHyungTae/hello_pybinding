#pragma once

#include <pybind11/pybind11.h>

namespace py = pybind11;


namespace dico
{
    std::string get_string(const py::dict &dict);
}
