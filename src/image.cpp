#include <iostream>

#include "image.hpp"

using pxl = uint32_t;


pxl rgba_to_hex(const pxl &red, const pxl &green,
                const pxl &blue, const pxl &transparency)
{
    return red << 24 | green << 16 | blue << 8 | transparency;
}

void image::to_red(py::array &img)
{
    py::buffer_info buf = img.request();
    pxl *buf_ptr = static_cast<pxl *>(buf.ptr);

    for (long int i = 0; i < buf.shape[0]; i++)
        for (long int j = 0; j < buf.shape[1]; j++)
            buf_ptr[i * buf.shape[1] + j] = rgba_to_hex(255, 0, 0, 255);
}



PYBIND11_MODULE(image, m)
{
    m.doc() = "A simple cpp image package";
    m.def("to_red", image::to_red, "Making an image buffer red");
}
