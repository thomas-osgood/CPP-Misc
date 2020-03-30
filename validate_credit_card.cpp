/*
    Function to validate a credit card number using
    the Luhn Algorithm.
    
    Given a positive integer of up to 16 digits, return true if it is a valid credit card number, and false if it is not.

    Here is the algorithm:

        Double every other digit, scanning from right to left, starting from the second digit (from the right).

        Another way to think about it is: if there are an even number of digits, double every other digit starting with the first; if there are an odd number of digits, double every other digit starting with the second:

        1714 ==> [1*, 7, 1*, 4] ==> [2, 7, 2, 4]

        12345 ==> [1, 2*, 3, 4*, 5] ==> [1, 4, 3, 8, 5]

        891 ==> [8, 9*, 1] ==> [8, 18, 1]

        If a resulting number is greater than 9, replace it with the sum of its own digits (which is the same as subtracting 9 from it):

        [8, 18*, 1] ==> [8, (1+8), 1] ==> [8, 9, 1]

        or:

        [8, 18*, 1] ==> [8, (18-9), 1] ==> [8, 9, 1]

        Sum all of the final digits:

        [8, 9, 1] ==> 8 + 9 + 1 = 18

        Finally, take that sum and divide it by 10. If the remainder equals zero, the original credit card number is valid.

          18 (modulus) 10 ==> 8 , which is not equal to 0, so this is not a valid credit card number


*/
#include <string>
#include <iostream>
#include <sstream>

class Kata {
  public:
  static bool validate(long long int n);
};

bool Kata::validate(long long int n) {
  bool retVal = false;
  std::string n_str = std::to_string(n);
  int end = n_str.length();
  bool odd = end % 2;
  int i = 0;
  int current = 0;
  int sum = 0;
  
  /*
    Go Through String And Validate
  */
  for (i = 0; i < end; i++) {
    std::stringstream ss;
    ss << n_str[i];
    ss >> current;
    
    if (odd) {
      if ((i % 2) == 1) {
        current *= 2;
        if (current > 9) {
          current -= 9;
        }
      } else {
        current = current;
      }
    } else {
      if ((i % 2) == 0) {
        current *= 2;
        if (current > 9) {
          current -= 9;
        }
      } else {
        current = current;
      }
    }
    sum += current;
  }
  
  if ((sum % 10) == 0) {
    retVal = true;
  }
  
  return retVal;
}
