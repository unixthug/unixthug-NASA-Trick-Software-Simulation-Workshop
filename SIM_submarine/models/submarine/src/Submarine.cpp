
// ==============================================================
// Project: Implement the member functions of the Submarine class.
// ==============================================================

/* Model Include files */
#include <iostream>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "trick/integrator_c_intf.h"
#include "../include/Submarine.hh"
#include "trick/exec_proto.h"

using namespace std;

/* default data job */
int Submarine::submarine_default_data() {
	outer_hull_outer_radius = 1.30;
	outer_hull_inner_radius = 1.25;
	inner_hull_outer_radius = 1.10;
	inner_hull_inner_radius = 1.00;
	hull_length = 3.0;
	ballast_tank_volume = 1.0;
	hard_ballast_mass = 0.0;
	hull_mass = 10000.0;
	payload_mass = 1500.0;
	Cd = 0.5;
	
	
	return 0;
}

/* initialization job */
int Submarine::submarine_init() {
	pos[0] = 0.0;
	pos[1] = 0.0;
	vel[0] = 0.0;
	vel[1] = 0.0;
	
	ballast_energy = 80000.0;
	//ballast_energy = pWater() * ballast_tank_volume;
	pump_power = 0.0;

	ballast_air_ratio = 0.0;
	water_pressure_pascals = 0.0;
	water_pressure_PSI = 0.0;
	pump_power_command = 0;

	return 0;
}

int Submarine::control() {
	pump_power = pump_power_command;
	if (pump_power > 5000.0) pump_power = 5000.0;
	if (pump_power < -5000.0) pump_power = -5000.0;
	return 0;
}

//Equation functions
double Submarine::vHull () {
	return M_PI * (inner_hull_outer_radius * inner_hull_outer_radius) * hull_length;
}


double Submarine::pWater() {
	if (pos[1] > outer_hull_outer_radius) { water_pressure_PSI = 0.0; water_pressure_pascals = 0.0; return 0.0; }
	//water_pressure_pascals = DENSITY_SALT_WATER * GRAVITY * -pos[1] + (101353.0 * CONVERSION_PASCALS_TO_PSI);
	//water_pressure_PSI = (DENSITY_SALT_WATER * GRAVITY * -pos[1] + (101353.0 * CONVERSION_PASCALS_TO_PSI)) * CONVERSION_PASCALS_TO_PSI * 10;
	water_pressure_pascals = DENSITY_SALT_WATER * GRAVITY * -pos[1] + 14.7/CONVERSION_PASCALS_TO_PSI;
	water_pressure_PSI = water_pressure_pascals * CONVERSION_PASCALS_TO_PSI;
	//cout << "Water Pressure (PSI) : " << water_pressure_PSI << endl;
	return water_pressure_pascals;
}


double Submarine::vHullDisp() {
	if (pos[1] >= inner_hull_outer_radius) {
		return 0;
	} else if (pos[1] < inner_hull_outer_radius && pos[1] > -inner_hull_outer_radius) {
		double v = vHull() / (1 + pow(M_E, -5.5 * -pos[1]));
		//cout << v << "/" << vHull() << endl;
		return v;
	} else {
		return vHull();
	}
}

double Submarine::vBallAir() {	
	double ballast_air_v = ballast_energy / pWater();
	//printf("Ballast Air:%.4f\n", ballast_air_v);
	if (ballast_air_v > ballast_tank_volume) {
		ballast_energy = pWater() * ballast_tank_volume;
		return ballast_tank_volume;
	} else {
		return ballast_air_v;
	}
}

double Submarine::vBallWater() {
	return ballast_tank_volume - vBallAir();
}

double Submarine::mBallWater() {
	return vBallWater() * DENSITY_SALT_WATER;
}

double Submarine::mTotal() {
	return (hull_mass + payload_mass) + hard_ballast_mass + mBallWater();
}

double Submarine::mTotDisp() {
	return (vHullDisp() + vBallAir()) * DENSITY_SALT_WATER;
}

double Submarine::csArea() {
	return outer_hull_outer_radius * 2 * hull_length;
}

double Submarine::gForce() {
	return mTotal() * -GRAVITY;
}

double Submarine::dForce() {
	return -0.5 * DENSITY_SALT_WATER * vel[1] * fabs(vel[1]) * Cd * csArea();
}

double Submarine::bForce() {
	return mTotDisp() * GRAVITY;
}

double Submarine::fTotal() {
	//cout << "Net forces (joules) : " << gForce() + bForce() + dForce() << endl;
	//printf("Gravity : %.4f\nBuoyancy: %.4f\nDrag: %.4f\n", gForce(), bForce(), dForce());
	return gForce() + bForce() + dForce();
}

int Submarine::submarine_shutdown() {
	double t = exec_get_sim_time();
	printf( "=============================\n");
	printf( " Submarine State at Shutdown \n");
	printf( "t = %g\n", t);
	printf( "pos = [%.9f, %.9f]\n", pos[0], pos[1]);
	printf( "vel = [%.9f, %.9f]\n", vel[0], vel[1]);
	printf( "=============================\n");
	return 0 ;
}



int Submarine::submarine_deriv() {
	acc[0] = 0.0;
	acc[1] = fTotal() / mTotal();
	 
	ballast_air_ratio = vBallAir() / ballast_tank_volume;	
	return 0;
}

int Submarine::submarine_integ() {
	int ipass;
	
	load_state(
		&pos[0] ,
		&pos[1] ,
		&vel[0] ,
		&vel[1] ,
		&ballast_energy ,
		NULL);

	load_deriv(
		&vel[0] ,
		&vel[1] ,
		&acc[0] ,
		&acc[1] ,
		&pump_power ,
		NULL);

	ipass = integrate();

	unload_state(
		&pos[0] ,
		&pos[1] ,
		&vel[0] ,
		&vel[1] ,
		&ballast_energy ,
		NULL);
	if (ballast_energy < 0.0) { ballast_energy = 0.0; }

	return(ipass);
}
