#include <iostream>

#include "hello.hpp"


void test::Test::hello_world()
{
    std::cout << "Hello World !" << std::endl;
}

std::string test::Test::get_hello_world()
{
    return "Hello World !";
}

void test::Test::hello_name(const std::string &name)
{
    if (name == "Hello")
        std::cout << "ARRETE DE FAIRE CHIER ENGUERRAND" << std::endl;
    else
        std::cout << "Hello " << name << std::endl;
}

void test::Test::hello_list(const py::array_t<int> &names)
{
    // empty list

    py::buffer_info names_buf = names.request();
    int *names_ptr = static_cast<int *>(names_buf.ptr);
    for (long int i = 0; i < names_buf.shape[0]; i++)
        hello_name(std::to_string(names_ptr[i]));
}

struct MyClass
{
    std::string name;
    int age;
};

void test::Test::hello_obj(const Person &person)
{
    hello_name(person.name + " (" + std::to_string(person.age) + ")");
}

std::pair<std::string, std::string> test::Test::get_2_names()
{
    return {"Guillaume", "Enguerrand"};
}


PYBIND11_MODULE(hello, m)
{
    m.doc() = "An extraordinary package to greet people";
    py::class_<test::Test> test(m, "Test");
    test.def(
        "hello_world", test::Test::hello_world,
        "An extraordinary function to greet people")
    .def("get_hello_world", &test::Test::get_hello_world,
         "An extraordinary function to learn how to greet people")
    .def("hello_name", &test::Test::hello_name,
         "An extraordinary function to politely greet people")
    .def("hello_list", &test::Test::hello_list,
         "An extraordinary function to greet several people at a time")
    .def("hello_obj", &test::Test::hello_obj,
         "An extraordinary function to greet more precisely people")
    .def("get_2_names", &test::Test::get_2_names,
         "Get the name of 2 extraordinary persons (Thus has pseudo-lexicographic "
         "order higher than the other)")
        ;

    py::class_<test::Test::Person>(test, "Person")
        .def(py::init<const std::string &, const int &>())
        .def_readonly("name", &test::Test::Person::name)
        .def_readonly("age", &test::Test::Person::age);
}
