#include <SensorPressure.h>

#define SENSOR_PRESSURE	A3 // pin sensor pressure

float SP_vMin = 0.47; 	// min volts without pressure
//float SP_vMax = 4.4; 	// max volts in max pressure
float SP_vMax = 4.7;   // max volts in max pressure
float SP_pMin = 0.0;	// min pressure
//float SP_pMax = 12.0;	// max pressure
float SP_pMax = 13.0;  // max pressure
float SP_error = 0.1;	// correction pressure

SensorPressure SensP(SENSOR_PRESSURE, SP_vMin, SP_vMax, SP_pMin, SP_pMax, SP_error);

void setup()
{
	//initialize serial
	Serial.begin(9600);

}

void loop()
{
	//print volts value in serial monitor
	Serial.println(SensP.getVolts());
	//print pressure value in serial monitor
	Serial.println(SensP.getPressure());
	//give it a second
	delay(1000);
	
}
