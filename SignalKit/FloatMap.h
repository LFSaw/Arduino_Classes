/********
FloatMap.h - A mapping class for working with floats.
Uses fscale algorithm to do exponential/logarithmic mappings.
http://playground.arduino.cc/Main/Fscale

NTS:: Look at Mozzi Int_Map library / mozzi_fixmath.cpp and develop an exponential mapping 
toolkit using integer math that's faster!
https://www.arduino.cc/en/Math/H

Created by Jonathan Reus-Brodsky, July 29, 2016
Released into the public domain.

**/

#ifndef FloatMap_H
#define FloatMap_H

#include <Arduino.h>
#include <math.h>


class FloatMap {


public:
  // Public data members
  // NOTE: Make these volatile if they are being used within interrupts
  
  /** Constructor.
  @param in_min the minimum of the input range.
  @param in_max the maximum of the input range.
  @param out_min the minimum of the output range.
  @param out_max the maximum of the output range.
  @param curve the curve of the mapping (between -10 and 10, 0 is linear)
  */
  FloatMap(int in_min, int in_max, int out_min, int out_max, float curve);
  ~FloatMap();

  /** Process the next input value.
  @param n the next integer to process.
  @return the input integer mapped to the output range.
  */
  int operator()(int n);
  float fscale(float val);

  // NTS:: Inline the above functions for speed (look at IntMap)
  
private:
// NTS:: These should be consts! But initialization doesn't work..
  int _IN_MIN, _IN_MAX, _OUT_MIN, _OUT_MAX;
  int _IN_RANGE, _OUT_RANGE;
  float _CURVE;
  boolean _INV_FLAG;


};

#endif
