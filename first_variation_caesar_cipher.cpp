/*
The action of a Caesar cipher is to replace each plaintext letter (plaintext letters are from 'a' to 'z' or from 'A' to 'Z') with a different one a fixed number of places up or down the alphabet.

This program performs a variation of the Caesar shift. The shift increases by 1 for each character (on each iteration).

If the shift is initially 1, the first character of the message to be encoded will be shifted by 1, the second character will be shifted by 2, etc...
Coding: Parameters and return of function "movingShift"

param s: a string to be coded

param shift: an integer giving the initial shift

The function "movingShift" first codes the entire string and then returns an array of strings containing the coded string in 5 parts (five parts because, to avoid more risks, the coded message will be given to five runners, one piece for each runner).

If possible the message will be equally divided by message length between the five runners. If this is not possible, parts 1 to 5 will have subsequently non-increasing lengths, such that parts 1 to 4 are at least as long as when evenly divided, but at most 1 longer. If the last part is the empty string this empty string must be shown in the resulting array.

For example, if the coded message has a length of 17 the five parts will have lengths of 4, 4, 4, 4, 1. The parts 1, 2, 3, 4 are evenly split and the last part of length 1 is shorter. If the length is 16 the parts will be of lengths 4, 4, 4, 4, 0. Parts 1, 2, 3, 4 are evenly split and the fifth runner will stay at home since his part is the empty string. If the length is 11, equal parts would be of length 2.2, hence parts will be of lengths 3, 3, 3, 2, 0.

You will also implement a "demovingShift" function with two parameters
Decoding: parameters and return of function "demovingShift"

    an array of strings: s (possibly resulting from "movingShift", with 5 strings)

    an int shift

"demovingShift" returns a string.
Example:

u = "I should have known that you would have a perfect answer for me!!!"

movingShift(u, 1) returns :

v = ["J vltasl rlhr ", "zdfog odxr ypw", " atasl rlhr p ", "gwkzzyq zntyhv", " lvz wp!!!"]

(quotes added in order to see the strings and the spaces, your program won't write these quotes, see Example Test Cases)

and demovingShift(v, 1) returns u. #Ref:

Caesar Cipher : http://en.wikipedia.org/wiki/Caesar_cipher
*/

class CaesarCipher
{
  public:
    static std::vector<std::string> movingShift(const std::string &s, int shift);
    static std::string demovingShift(std::vector<std::string> &s, int shift);
};

using namespace std;

vector<string> CaesarCipher::movingShift(const string &s, int shift) {
  int i = 0, x = 0, l = s.length();
  
  // 'Encrypt' Vars
  int cl = 0, la = (int)'a', lz = (int)'z', ca = (int)'A', cz = (int)'Z', cshift = shift;
  
  // 'Breakup' Vars
  int overflow = l % 5, div = l / 5;
  int cp = 0, sp = 0;
  string nstr;
  
  // Return Value
  vector<string> retVal;
  
  // Cipher String
  string cstr;
  
  // Turn Entire String To Caesar Cipher First (Before Breakup)
  for (i = 0; i < l; i++) {
    cl = s[i];
    if ((cl >= la) && (cl <= lz)) {
      cl = (((cl - la) + cshift) % 26) + la;
      cstr.append(1,(char)cl);
    } else if ((cl >= ca) && (cl <= cz)) {
      cl = (((cl - ca) + cshift) % 26) + ca;
      cstr.append(1,(char)cl);
    } else {
      cstr.append(1,(char)cl);
    }
    cshift++;
  }
  
  // Breakup String And Place In Vector
  if (overflow == 0) {
    for (x = 0; x < 5; x++) {
      sp = cp + div;
      while (cp != sp) {
        nstr.append(1,cstr[cp]);
        cp++;
      }
      retVal.push_back(nstr);
      nstr = "";
    }
  } else {
    for (x = 0; x < 4; x++) {
      sp = cp + div + 1;
      while (cp != sp) {
        nstr.append(1,cstr[cp]);
        cp++;
      }
      retVal.push_back(nstr);
      nstr = "";
    }
    
    for (x = cp; x < l; x++) {
      nstr.append(1, cstr[x]);
    }
    retVal.push_back(nstr);
  }
  
  // Return Broken Up Cipher
  return retVal;
}

string CaesarCipher::demovingShift(vector<string> &s, int shift) {
  // Return Var
  string retVal;
  
  // 'Encrypt' Vars
  int cl = 0, la = (int)'a', lz = (int)'z', ca = (int)'A', cz = (int)'Z', cshift = shift, ishift = 0;
  bool t1 = false, t2 = false;
  
  // Loop Vars
  int i = 0;
  
  // Intermediaries
  int l = 0;
  string cstr;  
  
  // Compress Cipher Into One String
  for (i = 0; i < 5; i++) {
    cstr += s.at(i);
  }
  
  // Full Cipher Length
  l = cstr.length();
  
  // 'Decrypt' Cipher
  for (i = 0; i < l; i++) {
    cl = (int)cstr[i];
    ishift = 26 - (cshift % 26);
    t1 = ((cl >= la) && (cl <= lz));
    t2 = ((cl >= ca) && (cl <= cz));
    
    if (t1) {
      cl = (((cl - la) + ishift) % 26) + la;
      retVal.append(1,(char)cl);
    } else if (t2) {
      cl = (((cl - ca) + ishift) % 26) + ca;
      retVal.append(1,(char)cl);
    } else {
      retVal.append(1,(char)cl);
    }
    cshift++;
  }
  
  // Return Plaintext
  return retVal;
}
