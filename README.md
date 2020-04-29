## Arduino Pressure Sensor

![PRESSURE SENSOR](https://ae01.alicdn.com/kf/HTB1AsTlrr1YBuNjSszhq6AUsFXaS/5-0-1-2.jpg)
```c++
#define SENSOR_PRESSURE	A3 // pin sensor pressure

float SP_vMin = 0.47; 	// min volts without pressure
float SP_vMax = 4.4; 	// max volts in max pressure
float SP_pMin = 0.0;	// min pressure
float SP_pMax = 12.0;	// max pressure
float SP_error = 0.1;	// correction pressure

SensorPressure SP(SENSOR_PRESSURE, SP_vMin, SP_vMax, SP_pMin, SP_pMax, SP_error);
```
