#ifndef SensorPressure_h
#define SensorPressure_h

#include "Arduino.h"

/*
 * This is an OpenSSL-compatible implementation of the RSA Data Security,
 * Inc. MD5 Message-Digest Algorithm (RFC 1321).
 *
 * Written by Solar Designer <solar at openwall.com> in 2001, and placed
 * in the public domain.  There's absolutely no warranty.
 *
 * This differs from John John's older public domain implementation in
 * that no 32-bit integer data type is required, there's no compile-time
 * endianness configuration, and the function prototypes match OpenSSL's.
 * The primary goals are portability and ease of use.
 *
 * This implementation is meant to be fast, but not as fast as possible.
 * Some known optimizations are not included to reduce source code size
 * and avoid compile-time configuration.
 */

/*
 * Updated by John John for arduino
 * <mail@mail.net>
 */

class SensorPressure
{
public:
	SensorPressure(int pinSensor, float vMin, float vMax, float pMin, float pMax, float error);
	float getVolts();
	float getPressure();
	float map(float vCurrent, float vMin, float vMax, float pMin, float pMax, float error);
private:
	int _pinSensor;
	float _vMin;
	float _vMax;
	float _pMin;
	float _pMax;
	float _error;
	float _ans;
	
};

#endif //SensorPressure_h
