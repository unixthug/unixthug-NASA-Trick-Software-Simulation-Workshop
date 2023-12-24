#include <Python.h>
#if PY_VERSION_HEX >= 0x03000000
extern "C" {

PyObject * PyInit__maf042a8ac26a39366393033f022b7bed(void) ; /* /home/caci114/trick_sims/SIM_submarine/S_source.hh */
PyObject * PyInit__mf25fb9851ae0aec07f6f6b611d204e49(void) ; /* /home/caci114/trick_sims/SIM_submarine/models/submarine/include/Submarine.hh */
PyObject * PyInit__sim_services(void) ;
PyObject * PyInit__top(void) ;
PyObject * PyInit__swig_double(void) ;
PyObject * PyInit__swig_int(void) ;
PyObject * PyInit__swig_ref(void) ;

void init_swig_modules(void) {

    PyImport_AppendInittab("_mf25fb9851ae0aec07f6f6b611d204e49", PyInit__mf25fb9851ae0aec07f6f6b611d204e49) ;
    PyImport_AppendInittab("_maf042a8ac26a39366393033f022b7bed", PyInit__maf042a8ac26a39366393033f022b7bed) ;
    PyImport_AppendInittab("_sim_services", PyInit__sim_services) ;
    PyImport_AppendInittab("_top", PyInit__top) ;
    PyImport_AppendInittab("_swig_double", PyInit__swig_double) ;
    PyImport_AppendInittab("_swig_int", PyInit__swig_int) ;
    PyImport_AppendInittab("_swig_ref", PyInit__swig_ref) ;
    return ;
}

}
#else
extern "C" {

void init_maf042a8ac26a39366393033f022b7bed(void) ; /* /home/caci114/trick_sims/SIM_submarine/S_source.hh */
void init_mf25fb9851ae0aec07f6f6b611d204e49(void) ; /* /home/caci114/trick_sims/SIM_submarine/models/submarine/include/Submarine.hh */
void init_sim_services(void) ;
void init_top(void) ;
void init_swig_double(void) ;
void init_swig_int(void) ;
void init_swig_ref(void) ;

void init_swig_modules(void) {

    init_mf25fb9851ae0aec07f6f6b611d204e49() ;
    init_maf042a8ac26a39366393033f022b7bed() ;
    init_sim_services() ;
    init_top() ;
    init_swig_double() ;
    init_swig_int() ;
    init_swig_ref() ;
    return ;
}

}
#endif
