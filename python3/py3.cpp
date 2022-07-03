#include <Python.h>

// small changes of
// https://medium.com/@wansac/the-python-c-api-a-brief-introduction-7926ea0ef488

int main() {
  // Py_Initialize must be called before any other
  // Python C/API functions
  Py_Initialize();

  // Equivalent of "import platform" in Python
  PyObject *platform_module = PyImport_ImportModule("os");
  if (!platform_module) {
    // The import failed.
    // Double check spelling in import call and confirm
    // you can import platform in Python on system.
    printf("\nCould not import platform module.\n");
    return 0;
  }

  PyObject *system_function = PyObject_GetAttrString(platform_module, "getenv");
  if (system_function && PyCallable_Check(system_function)) {

    // Prepare args
    PyObject *pArgs = PyTuple_New(1);
    PyObject *pValue = PyUnicode_FromString("PWD");
    PyTuple_SetItem(pArgs, 0, pValue);

    // Call os.getenv('PWD')
    PyObject *system_obj = PyObject_CallObject(system_function, pArgs);

    // Print result
    const char *system_str = PyUnicode_AsUTF8(system_obj);
    printf("\nos.getenv('PWD'): %s \n\n", system_str);

    // Decrement reference counts for objects we are
    // done using to allow garbage collection to dispose of them
    Py_XDECREF(system_function);
    Py_XDECREF(system_obj);
    Py_XDECREF(pArgs);
  } else {
    // Something has gone wrong.
    // Double check spelling in PyObject_GetAttrString and try
    // calling platform.system() in Python.
    printf("\nCould not call platform.system() function.\n");
  }

  return 0;
}
