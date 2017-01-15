// HC_SR04 - Arduino Library for HC-SR04 Ultrasonic Ranging Module.
// Simple example of usage with serial monitor
// Fiorenzo D'Errico 15.01.2017
// Rev.1 (01/2017)

#include <HC_SR04.h>

HC_SR04 module1(9,10); // (Trig PIN,Echo PIN)

void setup() {
  Serial.begin(9600); 
}

void loop()
{  
  long distance= module1.getDistance_in_cm();
  Serial.print(distance);
  Serial.println(" cm" );
  delay(100);
<<<<<<< HEAD
}
=======
}
>>>>>>> origin/master
