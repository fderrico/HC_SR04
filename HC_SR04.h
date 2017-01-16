/*
  NAME:
  HC_SR04

  DESCRIPTION:
  Arduino Library for HC-SR04 Ultrasonic Ranging Module. 
  - Library uses interrupts for measuring sound reflection times.
  - Library uses only SI measurement units and imperial units.  
  - Sound speed in meters is set to standard approximated value at 20°C 340m/s

  LICENSE:
  This program is release according to Creative Commons Share Alike License and Attribution by F.D'Errico

  CREDENTIALS:
  Author: Fiorenzo D'Errico
  GitHub: https://github.com/fderrico/HC_SR04.git  
 */
#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#define MAX_RANGE 400 //data sheet MAX Range = 400 cm 
#define MIN_RANGE 2	//data sheet Min range = 2 cm
#define TEST_DISTANCE high_level_time*velocity_of_sound/2
#define VELOCITY_OF_SOUND_IN_AIR_AT_20_C 340
#define VELOCITY_OF_SOUND_IN_CM_PER_SECOND velocity_of_sound*100
#define MIN_TRIG_PULSE_WIDTH 10 //data sheet minimum width of trigger pulse (10 us)
#define MIN_MEASUREMENT_CYCLE 60 //data sheet minimum measurement cycle (60 us)
#define DISTANCE_IN_CM EchoPulseDuration/58 //data sheet distance evaluated in centimeters
#define DISTANCE_IN_INCH EchoPulseDuration/148 //data sheet distance evaluated in centimeters

class HC_SR04{

  public:
//-------------------------------------------------------------------------
// Public methods
//-------------------------------------------------------------------------

/*
Constructor with configuration parameters

DESCRIPTION:
Setting up configuration parameters for library and measurement. They all
are stored in the private variables.  

PARAMETERS:
p_TrigPIN  				- 	Arduino digital pin number where "Trigger" pin of HC-SR04 
							will be connected
p_EchoPIN     			- 	Arduino digital pin number where "Trigger" pin of HC-SR04 
							will be connected
p_Upper_Limit_Range_cm 	- 	maximal accepted measured distance from the sensor 
							to obstacle in centimeters. (Default Value = 400 cm)
RETURN: object
*/
	HC_SR04(int p_TrigPIN, int p_EchoPIN, int p_Upper_Limit_Range_cm);
/*
  Overloaded constructor with p_Upper_Limit_Range_cm set to Default Value 400cm.
*/	
	HC_SR04(int p_TrigPIN, int p_EchoPIN);

 /*
  Measure distance in centimeters from the sensor to a reflecting obstacle.

  DESCRIPTION:
  The method measures distance from the sensor a reflecting obstacle based
  on measuring ultrasonic pulses sequence time sent to it and returned back.
  
  PARAMETERS: none

  RETURN: Distance in centimeters
*/    
	long getDistance_in_cm();
 /*
  Measure distance in inches from the sensor to a reflecting obstacle.

  DESCRIPTION:
  The method measures distance from the sensor a reflecting obstacle based
  on measuring ultrasonic pulses sequence time sent to it and returned back.
  
  PARAMETERS: none

  RETURN: Distance in inches
*/    
	long getDistance_in_inch();	
	
	//Accessors
	int getTrigPIN();
	void setTrigPIN(int p_TrigPIN);
	
	int getEchoPIN();
	void setEchoPIN(int p_EchoPIN);
	
	int getUpper_Limit_Range_cm();
	void setUpper_Limit_Range_cm(int p_Upper_Limit_Range_cm);
	
	long getTimeOut();
	void setTimeOut(long p_TimeOut);
	
	int getVelocity_of_sound();
	void setVelocity_of_sound(int p_velocity_of_sound);	 
	
  private:
//----------------------
//- Private attributes - 
//----------------------
    int TrigPIN;
    int EchoPIN;
	int Upper_Limit_Range_cm;
	int velocity_of_sound;
	long TimeOut;
    long duration,distance_cm,distance_inc;

//----------------------
//- Private operations - 
//----------------------	
	void sendTriggerPulse();
	long evaluateEchoPulseDuration();   
};
#endif