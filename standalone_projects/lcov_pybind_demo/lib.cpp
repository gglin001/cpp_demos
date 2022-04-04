#include <pybind11/pybind11.h>

int add(int i, int j) { return i + j; }

int sub(int i, int j) { return i - j; }

int mul(int i, int j) { return i * j; }

namespace py = pybind11;

PYBIND11_MODULE(lib, m) {
  m.def("add", &add);

  m.def("sub", &sub);

  m.def("mul", &mul);
}
