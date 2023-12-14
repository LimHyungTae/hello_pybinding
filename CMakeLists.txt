project(hello)
cmake_minimum_required(VERSION 3.11)

find_package(pybind11 REQUIRED)
add_compile_options("-W" "-Wall")

pybind11_add_module(hello MODULE
  src/hello.cpp
  )

pybind11_add_module(image MODULE
  src/image.cpp
  )

pybind11_add_module(dico MODULE
  src/dico.cpp
  )
