class SensorPressure
{

	int _pinSensor;
	float _vMin;
	float _vMax;
	float _pMin;
	float _pMax;
	float _error;
	float _ans;

	public:
	SensorPressure(int pinSensor, float vMin, float vMax, float pMin, float pMax, float error = 0)
	{
		_pinSensor = pinSensor;
		_vMin = vMin;
		_vMax = vMax;
		_pMin = pMin;
		_pMax = pMax;
		_error = error;

		pinMode(_pinSensor, INPUT);

	}

	float getVolts()
	{
		return analogRead(_pinSensor) * (5.0 / 1023.0);

	}

	float getPressure()
	{
		return map(getVolts(), _vMin, _vMax, _pMin, _pMax, _error);

	}

	float map(float vCurrent, float vMin, float vMax, float pMin, float pMax, float error)
	{
		/*
			( x - x1 ) / ( x2 - x1 ) 	= ( y - y1 ) / ( y2 - y1 )
			x - x1	         		= ( y - y1 ) / ( y2 - y1 ) * ( x2 - x1 )
			x             			= ( y - y1 ) / ( y2 - y1 ) * ( x2 - x1 ) + x1
			x             			= ( y - y1 ) * ( x2 - x1 ) / ( y2 - y1 ) + x1
		*/

		if (vCurrent < vMin) vCurrent = vMin;
		if (vCurrent > vMax) vCurrent = vMax;

		_ans = ( vCurrent - vMin ) * ( pMax - pMin ) / ( vMax - vMin ) + pMin + error;

		if( ans < pMin) ans = pMin;
		if( ans > pMax) ans = pMax;

		return ans;

	}
};

#define SENSOR_PRESSURE	A3 // pin sensor pressure

float SP_vMin = 0.47; 	// min volts without pressure
float SP_vMax = 4.4; 	// max volts in max pressure
float SP_pMin = 0.0;	// min pressure
float SP_pMax = 12.0;	// max pressure
float SP_error = 0.1;	// correction pressure

SensorPressure SP(SENSOR_PRESSURE, SP_vMin, SP_vMax, SP_pMin, SP_pMax, SP_error);
