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

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "HC_SR04.h"

HC_SR04::HC_SR04(int p_TrigPIN, int p_EchoPIN){   
   setUpper_Limit_Range_cm(MAX_RANGE);
   setVelocity_of_sound(VELOCITY_OF_SOUND_IN_AIR_AT_20_C);   
   setTrigPIN(p_TrigPIN);
   setEchoPIN(p_EchoPIN);
   setTimeOut(2*getUpper_Limit_Range_cm()/(VELOCITY_OF_SOUND_IN_CM_PER_SECOND));
   pinMode(p_TrigPIN,OUTPUT);
   pinMode(p_EchoPIN,INPUT);   
}
HC_SR04::HC_SR04(int p_TrigPIN, int p_EchoPIN, int p_Upper_Limit_Range_cm){
   setUpper_Limit_Range_cm(p_Upper_Limit_Range_cm);
   setVelocity_of_sound(VELOCITY_OF_SOUND_IN_AIR_AT_20_C);
   setTrigPIN(p_TrigPIN);
   setEchoPIN(p_EchoPIN);
   setTimeOut(2*getUpper_Limit_Range_cm()/(VELOCITY_OF_SOUND_IN_CM_PER_SECOND));
   pinMode(p_TrigPIN,OUTPUT);
   pinMode(p_EchoPIN,INPUT);
}
int HC_SR04::getTrigPIN(){
	return TrigPIN;	
}
void HC_SR04::setTrigPIN(int p_TrigPIN){
	TrigPIN=p_TrigPIN;
}
int HC_SR04::getEchoPIN(){
	return EchoPIN;
}
void HC_SR04::setEchoPIN(int p_EchoPIN){
	EchoPIN=p_EchoPIN;
}
int HC_SR04::getUpper_Limit_Range_cm(){
	return Upper_Limit_Range_cm;
}
void HC_SR04::setUpper_Limit_Range_cm(int p_Upper_Limit_Range_cm){
	Upper_Limit_Range_cm=p_Upper_Limit_Range_cm;
}
long HC_SR04::getTimeOut(){
	return TimeOut;
}
void HC_SR04::setTimeOut(long p_TimeOut){
	TimeOut =p_TimeOut;
}
int HC_SR04::getVelocity_of_sound(){
	return velocity_of_sound;
}
void HC_SR04::setVelocity_of_sound(int p_velocity_of_sound){
	velocity_of_sound=p_velocity_of_sound;
}
void HC_SR04::sendTriggerPulse(){
	digitalWrite(TrigPIN, LOW);
	delayMicroseconds(MIN_MEASUREMENT_CYCLE);
	digitalWrite(TrigPIN, HIGH);
	delayMicroseconds(MIN_TRIG_PULSE_WIDTH);
	digitalWrite(TrigPIN, LOW);
}
long HC_SR04::evaluateEchoPulseDuration(){
	duration = pulseIn(EchoPIN,HIGH,getTimeOut());
	if ( duration == 0 ) {
		duration = 0 ;}
	return duration;
}
long HC_SR04::getDistance_in_cm(){
	sendTriggerPulse();
	long EchoPulseDuration=evaluateEchoPulseDuration();	
	long distance_in_cm = DISTANCE_IN_CM;  
	if (distance_in_cm > getUpper_Limit_Range_cm()){
		distance_in_cm=-1;
	}
	return distance_in_cm; 
}
long HC_SR04::getDistance_in_inch(){ 
	return getDistance_in_cm() * 2.54;
}