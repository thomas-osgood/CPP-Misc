/*
RGBToHex String

Take an RGB value (255, 125, 35) and convert it to
a hexidecimal value.
*/

#include <iomanip>
#include<iostream>
#include<string>

class RGBToHex
{
  public:
  static std::string rgb(int r, int g, int b);
};

std::string RGBToHex::rgb(int r, int g, int b) {
  std::stringstream retVal, retVal2;
  std::stringstream rV, gV, bV;
  std::string ret;
  int nR, nG, nB, i = 0;
  
  if (r < 0)
    nR = 0;
  else if (r > 255)
    nR = 255;
  else
    nR = r;
  
  if (g < 0)
    nG = 0;
  else if (g > 255)
    nG = 255;
  else
    nG = g;
    
  if (b < 0)
    nB = 0;
  else if (b > 255)
    nB = 255;
  else
    nB = b;
  
  rV << std::setw(2) << std::setfill('0') << std::hex << nR;
  gV << std::setw(2) << std::setfill('0') << std::hex << nG;
  bV << std::setw(2) << std::setfill('0') << std::hex << nB;
  
  retVal << rV.str() << gV.str() << bV.str();
  ret = retVal.str();
  
  std::transform(ret.begin(), ret.end(), ret.begin(), ::toupper);
  
  return ret;
}

