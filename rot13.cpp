/*
ROT13 is a simple letter substitution cipher that replaces a letter with the letter 13 letters after it in the alphabet. ROT13 is an example of the Caesar cipher.

Create a function that takes a string and returns the string ciphered with Rot13. If there are numbers or special characters included in the string, they should be returned as they are. Only letters from the latin/english alphabet should be shifted, like in the original Rot13 "implementation".
*/
#include <string>
using namespace std;

/*
    Strategy:
        Loop through the entire string, converting every character to an
        integer value.  Then compare the integer value to the ranges
        between 'a' and 'z', and 'A' and 'Z'.  If the character falls within
        one of those ranges, manipulate the character and append the new
        character to the return string; otherwise append the existing
        character to the return string.
*/

string rot13(string msg)
{
  /* Init Local Variables */
  int i = 0, end = msg.length(), current = 0;
  int la = (int)'a', lz = (int)'z', ca = (int)'A', cz = (int)'Z';
  char newVal;
  string retVal;
  
  /* Loop Through String */
  for (i = 0; i < end; i++) {
      current = (int)msg[i];
      if ((current >= la) && (current <= lz)) {
          /* Handle Lowercase Letters */
          newVal = (((current - la) + 13) % 26) + la;
          retVal += newVal;
      } else if ((current >= ca) && (current <= cz)) {
          /* Handle Uppercase Letters */
          newVal = (((current - ca) + 13) % 26) + ca;
          retVal += newVal;
      } else {
          /* Handle Everything Else */
          retVal += msg[i];
      }
  }
  
  /* Return Cypher */
  return retVal;
}
