/*
    Narcissistic Number Problem
    A Narcissistic Number is a number which is the sum of its own digits, 
    each raised to the power of the number of digits in a given base.
    This only deals with base 10 numbers.
*/

#include <string>
#include <cmath>
#include <stdlib.h>

using namespace std;

bool narcissistic( int value ){
  bool retVal = false;
  string num = to_string(value);
  string s_res = "";
  int s_len = num.length();
  int i = 0;
  int res = 0;
  int c_val = 0;
  
  if (value = 0) {
    return false;
  }
  
  for (i = 0; i < s_len; i++) {
    c_val = stoi(num.substr(i,1));
    res += pow(c_val, s_len);
  }
  
  s_res = to_string(res);
  
  if ((s_res.length() == s_len) and (res == stoi(num))) {
    retVal = true;
  }
  
  return retVal;
}
