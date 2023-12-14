#pragma once

#include <string>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;


namespace test
{
    class Test
    {
    public:
        struct Person
        {
            const std::string name;
            const int age;
        };

        static void hello_world();
        static std::string get_hello_world();
        static void hello_name(const std::string &name);
        static void hello_list(const py::array_t<int> &names);
        static void hello_obj(const Person &person);
        static std::pair<std::string, std::string> get_2_names();
    };
};
