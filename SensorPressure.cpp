#include "SensorPressure.h"

SensorPressure::SensorPressure(int pinSensor, float vMin, float vMax, float pMin, float pMax, float error = 0)
{
	_pinSensor = pinSensor;
	_vMin = vMin;
	_vMax = vMax;
	_pMin = pMin;
	_pMax = pMax;
	_error = error;

	pinMode(_pinSensor, INPUT);
	
}

float SensorPressure::getVolts()
{
	return analogRead(_pinSensor) * (5.0 / 1023.0);

}

float SensorPressure::getPressure()
{
	return map(getVolts(), _vMin, _vMax, _pMin, _pMax, _error);

}

float SensorPressure::map(float vCurrent, float vMin, float vMax, float pMin, float pMax, float error)
{
	/*
		( x - x1 ) / ( x2 - x1 ) 	= ( y - y1 ) / ( y2 - y1 )
		( x - x1 )          		= ( y - y1 ) / ( y2 - y1 ) * ( x2 - x1 )
		x             			= ( y - y1 ) / ( y2 - y1 ) * ( x2 - x1 ) + x1
		x             			= ( y - y1 ) * ( x2 - x1 ) / ( y2 - y1 ) + x1
	*/

	if (vCurrent < vMin) vCurrent = vMin;
	if (vCurrent > vMax) vCurrent = vMax;

	_ans = ( vCurrent - vMin ) * ( pMax - pMin ) / ( vMax - vMin ) + pMin + error;

	if( _ans < pMin) _ans = pMin;
	if( _ans > pMax) _ans = pMax;

	return _ans;

}
