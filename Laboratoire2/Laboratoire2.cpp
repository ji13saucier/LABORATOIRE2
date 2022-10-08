#include <Python.h>
#pragma comment(lib, "Strmiids.lib")
#include <stdio.h>
#include <conio.h>
#include <dshow.h>
#include <iostream>
#include "Controle.h"
#include <codecvt>

using namespace std;

//PyObject* random(PyObject* self, PyObject* args)
//
//{
//
//    /* initialize random seed: */
//
//    srand(time(NULL));
//
//    int random = rand() % 10;
//
//    PyObject* python_val = Py_BuildValue("i", random);
//
//    return python_val;
//
//}

PyObject* lecteur(PyObject* self, PyObject* args)
{
       
        char selectionControle = 'a';
        const char* path = NULL;
        PyArg_ParseTuple(args, "s", &path);

        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        std::wstring wide = converter.from_bytes(path);
        LPCWSTR result = wide.c_str();
      
        PyObject* python_val = Py_BuildValue("i", 1);

        Controle* control = new Controle(result);

                while (selectionControle != 'q' && selectionControle != 'Q') {

                    selectionControle = _getch();
                    switch (selectionControle) {

                    case 'A':
                    case 'a':
                        control->AvanceRapide();
                        break;

                    case 'P':
                    case 'p':

                        if (control->GetEtat() == ETAT_ENCOURS)
                        {
                            control->Pause();
                        }
                        else if (control->GetEtat() == ETAT_PAUSE)
                        {
                            control->Play();
                        }
                        
                        break;
                    case 'R':
                    case 'r':
                        control->RetourOrigine();
                        //pControl->Stop();
                        //pGraph->RenderFile(result, NULL);
                       // pControl->Run();


                        break;
                    default:
                        break;
                    }
                }
            
     
        

                control->~Controle();
        return python_val;
    
}




 static PyMethodDef methods[] = {

 //{ "random", (PyCFunction)random, METH_NOARGS,

  //"Generate random number betweeen 0-9" },

     {"lecteur", (PyCFunction)lecteur, METH_VARARGS, "read a video"},

 { NULL, NULL, 0, NULL }

 };

 static struct PyModuleDef Laboratoire2 = {
    
    PyModuleDef_HEAD_INIT, 
    "Laboratoire2",
    "Essais de laboratoire 2",
    -1,
    methods
 
 };

 PyMODINIT_FUNC PyInit_Laboratoire2()
 {
     return PyModule_Create(&Laboratoire2);
 }
   


