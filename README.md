<a id="library"></a>
# HC_SR04
## DESCRIPTION:  
Arduino Library for HC-SR04 Ultrasonic Ranging Module.   
- Library uses interrupts for measuring sound reflection times.  
- Library uses only SI measurement units and imperial units.    
- Sound speed in meters is set to: 	```standard approximated value at 20°C 340m/s```

<a id="license"></a>
## LICENSE:
This program is release according to Creative Commons Share Alike License and Attribution by F.D'Errico.

<a id="credentials"></a>
## CREDENTIALS:  
Author: Fiorenzo D'Errico 

GitHub: https://github.com/fderrico/HC_SR04.git 

<a id="interface"></a>
## Interface
- [HC_SR04()](#HC_SR04)
- [getDistance_in_cm()](#getDistance_in_cm)
- [getDistance_in_inch()](#getDistance_in_inch)

<a id="HC_SR04"></a>
## HC_SR04()

#### Description
Overloaded constructor setting up configuration parameters for library and measurement. They all are stored in the private variables.  

#### Syntax    
HC_SR04(int p_TrigPIN, int p_EchoPIN, int p_Upper_Limit_Range_cm); 

HC_SR04(int p_TrigPIN, int p_EchoPIN);

#### PARAMETERS:
- **p_TrigPIN**    Arduino digital pin number where "Trigger" pin of HC-SR04 will be connected
- **p_EchoPIN**      Arduino digital pin number where "Trigger" pin of HC-SR04 will be connected
- **p_Upper_Limit_Range_cm**  maximal accepted measured distance in cm. ```(Default Value = 400 cm)```

#### RETURN: 
Instance object of the ultrasonic measurement module HC-SR04.

#### Example
``` cpp
HC_SR04 module1(9,10);  // module1 connected on digital pins 9 (Trigger PIN) and 10 (Echo PIN)
HC_SR04 module1(9, 10, 100);     // as above but limited to 100 cm measuring range
```
[Back to interface](#interface)

<a id="getDistance_in_cm"></a>
## getDistance_in_cm()

#### Description
The method measures distance from the sensor a reflecting obstacle based on measuring ultrasonic pulses sequence time sent to it and returned back.

#### Syntax    
long getDistance_in_cm();

#### Parameters
None

#### Return
Distance in centimeters

#### See also

[HC_SR04()](#HC_SR04)

[getDistance_in_inch](#getDistance_in_inch)

[Back to interface](#interface)

<a id="getDistance_in_inch"></a>
## getDistance_in_inch()

#### Description
The method measures distance from the sensor a reflecting obstacle based  on measuring ultrasonic pulses sequence time sent to it and returned back.

#### Syntax    
long getDistance_in_inch();

#### Parameters
None

#### Return 
Distance in inches

#### See also
[HC_SR04()](#HC_SR04)

[getDistance_in_cm](#getDistance_in_cm)

[Back to interface](#interface)
