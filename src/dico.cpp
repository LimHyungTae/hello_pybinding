#include "dico.hpp"


std::string dico::get_string(const py::dict &dict)
{
    return dict["string"].cast<std::string>();
}


PYBIND11_MODULE(dico, m)
{
    m.doc() = "A (really) simple cpp dictionary package";
    m.def("get_string", dico::get_string, "Collecting the `string` key of a dictionary");
}
