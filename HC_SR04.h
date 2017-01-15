<<<<<<< HEAD
// HC_SR04 - Arduino Library for HC-SR04 Ultrasonic Ranging Module
// Fiorenzo D'Errico 15.01.2017
// LICENSE:
// This code is licensed under Creative Commons Share Alike 
// and Attribution by F.D'Errico

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
class HC_SR04
{
  public:
    HC_SR04(int p_TrigPIN, int p_EchoPIN);
	HC_SR04(int p_TrigPIN, int p_EchoPIN, int p_Upper_Limit_Range_cm);
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
	
	//Functionals
	void sendTriggerPulse();
	long evaluateEchoPulseDuration();
    long getDistance_in_cm();
	long getDistance_in_inch();
	
  private:
    int TrigPIN;
    int EchoPIN;
	int Upper_Limit_Range_cm;
	int velocity_of_sound;
	long TimeOut;
    long duration,distance_cm,distance_inc;
};

=======
<<<<<<< HEAD
// HC_SR04 - Arduino Library for HC-SR04 Ultrasonic Ranging Module
// Fiorenzo D'Errico 15.01.2017
// LICENSE:
// This code is licensed under Creative Commons Share Alike 
// and Attribution by F.D'Errico

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
class HC_SR04
{
  public:
    HC_SR04(int p_TrigPIN, int p_EchoPIN);
	HC_SR04(int p_TrigPIN, int p_EchoPIN, int p_Upper_Limit_Range_cm);
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
	
	//Functionals
	void sendTriggerPulse();
	long evaluateEchoPulseDuration();
    long getDistance_in_cm();
	long getDistance_in_inch();
	
  private:
    int TrigPIN;
    int EchoPIN;
	int Upper_Limit_Range_cm;
	int velocity_of_sound;
	long TimeOut;
    long duration,distance_cm,distance_inc;
};

=======
// HC_SR04 - Arduino Library for HC-SR04 Ultrasonic Ranging Module
// Fiorenzo D'Errico 15.01.2017
// LICENSE:
// This code is licensed under Creative Commons Share Alike 
// and Attribution by F.D'Errico

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
class HC_SR04
{
  public:
    HC_SR04(int p_TrigPIN, int p_EchoPIN);
	HC_SR04(int p_TrigPIN, int p_EchoPIN, int p_Upper_Limit_Range_cm);
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
	
	//Functionals
	void sendTriggerPulse();
	long evaluateEchoPulseDuration();
    long getDistance_in_cm();
	long getDistance_in_inch();
	
  private:
    int TrigPIN;
    int EchoPIN;
	int Upper_Limit_Range_cm;
	int velocity_of_sound;
	long TimeOut;
    long duration,distance_cm,distance_inc;
};

>>>>>>> origin/master
>>>>>>> origin/master
#endif