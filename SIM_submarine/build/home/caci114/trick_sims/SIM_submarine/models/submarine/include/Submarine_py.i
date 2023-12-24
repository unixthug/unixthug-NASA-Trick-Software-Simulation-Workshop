%module mf25fb9851ae0aec07f6f6b611d204e49

%include "trick/swig/trick_swig.i"


%insert("begin") %{
#include <Python.h>
#include <cstddef>
%}

%{
#include "/home/caci114/trick_sims/SIM_submarine/models/submarine/include/Submarine.hh"
%}

%trick_swig_class_typemap(Submarine, Submarine)



#ifndef SUBMARINE_HH
#define SUBMARINE_HH


#define DENSITY_SALT_WATER 1023.6

#define GRAVITY 9.80665

#define CONVERSION_PASCALS_TO_PSI 1.4504e-4

class Submarine {
#if SWIG_VERSION > 0x040000
%pythoncode %{
    __setattr__ = _swig_setattr_nondynamic_instance_variable(object.__setattr__)
%}
#endif

    public:

    
    double outer_hull_outer_radius; 

    double outer_hull_inner_radius;	

    double inner_hull_outer_radius;	

    double inner_hull_inner_radius;	

    double hull_length; 			

    double ballast_tank_volume; 	

    double hard_ballast_mass;		

    double hull_mass;				

    double payload_mass;			

    double Cd;						


    
	double pos[2];					

	double vel[2];					

    double ballast_energy;  
    double pump_power;      

    
	double acc[2];					


    
    double ballast_air_ratio;     
    double water_pressure_pascals;					
    double water_pressure_PSI;    
    int    pump_power_command;    

    

    
    
    
	
	int submarine_default_data() ;
	int submarine_init() ;
	int submarine_shutdown() ;
	int submarine_integ() ;
	int submarine_deriv() ;
	
	int control() ;	
	double vHull() ;
	double pWater() ;
	double vHullDisp() ;
	double vBallAir() ;
	double vBallWater() ;
	double mBallWater() ;
	double mTotal() ;
	double mTotDisp() ;
	double csArea() ;
	double gForce() ;
	double dForce() ;
	double bForce() ;
	double fTotal() ;

};
#define TRICK_SWIG_DEFINED_Submarine
#endif

#ifdef TRICK_SWIG_DEFINED_Submarine
%trick_cast_as(Submarine, Submarine)
#endif
