/****
NTS:: Look at Mozzi Int_Map library and develop an exponential mapping 
toolkit using integer math.
****/

#include "FloatMap.h"

FloatMap::FloatMap(int in_min, int in_max, int out_min, int out_max, float curve)
  {
    _IN_MIN = in_min; _IN_MAX = in_max; _OUT_MIN = out_min; _OUT_MAX = out_max;
    // condition curve parameter
    // limit range
    if (curve > 10) curve = 10;
    if (curve < -10) curve = -10;
    curve = (curve * -.1) ; // - invert and scale - this seems more intuitive - postive numbers give more weight to high end on output 
    curve = pow(10, curve); // convert linear scale into lograthimic exponent for other pow function
    _CURVE = curve;
    // Zero Reference the values
    _IN_RANGE = _IN_MAX - _IN_MIN;
    if (_OUT_MAX > _OUT_MIN) {
      _OUT_RANGE = _OUT_MAX - _OUT_MIN;
      _INV_FLAG = 0;
    } else {
      _OUT_RANGE = _OUT_MIN - _OUT_MAX; 
      _INV_FLAG = 1;
    };

  }

FloatMap::~FloatMap() {
  // Do stuff
}

int FloatMap::operator()(int n) {
    return (int) fscale((float)n);
  }



float FloatMap::fscale(float inputValue) {
  float zeroRefCurVal = 0;
  float normalizedCurVal = 0;
  float rangedValue = 0;

  // Check for out of range inputValues
  if (inputValue < _IN_MIN) {
    inputValue = _IN_MIN;
  }
  if (inputValue > _IN_MAX) {
    inputValue = _IN_MAX;
  }

  zeroRefCurVal = inputValue - _IN_MIN;
  normalizedCurVal  =  zeroRefCurVal / _IN_RANGE; // normalize to 0 - 1 float

  // Check for originalMin > originalMax  - the math for all other cases i.e. negative numbers seems to work out fine 
  if (_IN_MIN > _IN_MAX ) return 0;

  if(_INV_FLAG == 0) {
    rangedValue = (pow(normalizedCurVal, _CURVE) * _OUT_RANGE) + _OUT_MIN;
  } else { // invert the ranges
    rangedValue =  _OUT_MIN - (pow(normalizedCurVal, _CURVE) * _OUT_RANGE); 
  }
  return rangedValue;
}
