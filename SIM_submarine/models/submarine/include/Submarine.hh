/************************************************************************
PURPOSE: (Simulate a submarine.)
LIBRARY DEPENDENCIES:
    ((submarine/src/Submarine.o))
**************************************************************************/
#ifndef SUBMARINE_HH
#define SUBMARINE_HH

// Density of salt water = 1023.6 kg/m^3
#define DENSITY_SALT_WATER 1023.6
// Acceleration of gravity = 9.80665 m/s^2
#define GRAVITY 9.80665
//
#define CONVERSION_PASCALS_TO_PSI 1.4504e-4

class Submarine {
    public:

    // Parameters
    double outer_hull_outer_radius; /* *i m Outer Hull Outer Radius */
    double outer_hull_inner_radius;	/* *i m Outer Hull Inner Radius */
    double inner_hull_outer_radius;	/* *i m Inner Hull Outer Radius */
    double inner_hull_inner_radius;	/* *i m Inner Hull Inner Radius */
    double hull_length; 			/* *i m Hull Length */
    double ballast_tank_volume; 	/* *i m3 Ballast Tank Volume */
    double hard_ballast_mass;		/* *i kg Hard Ballast Mass */
    double hull_mass;				/* *i kg Hull Mass */
    double payload_mass;			/* *i kg Payload Mass */
    double Cd;						/* -- Coefficient of Drag */

    // State Variables (Uncalculated Variables)
	double pos[2];					/* m xy - position */
	double vel[2];					/* m/s xy - velocity */
    double ballast_energy;  // joules
    double pump_power;      // watts

    // Calculated Variables
	double acc[2];					/* m/s2 xy - acceleration */

    // Control Variable
    double ballast_air_ratio;     // To the GUI. 	
    double water_pressure_pascals;					
    double water_pressure_PSI;    // To the GUI.	
    int    pump_power_command;    // From the GUI.	

    // Methods

    // =============================================
    // Project: Add member function prototypes here.
    // =============================================
	
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
#endif
