#include <Python.h>

static PyObject* random(PyObject* self, PyObject* args)

{

    /* initialize random seed: */

    srand(time(NULL));

    int random = rand() % 10;

    PyObject* python_val = Py_BuildValue("i", random);

    return python_val;

}





 static PyMethodDef methods[] = {

 { "random", random, METH_NOARGS,

  "Generate random number betweeen 0-9" },

 { NULL, NULL, 0, NULL }

 };

 static struct PyModuleDef cModPyDem = {
    
    PyModuleDef_HEAD_INIT, 
    "cModPyDem",
    NULL,
    1,
    methods
 
 };

 PyMODINIT_FUNC PyInit_cModPyDem(void)
 {
     return PyModule_Create(&cModPyDem);
 }
    //PyObject* m = Py_InitModule("my_math", methods);


