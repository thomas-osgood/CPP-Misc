/*
Given the triangle of consecutive odd numbers:

             1
          3     5
       7     9    11
   13    15    17    19
21    23    25    27    29
...

Calculate the row sums of this triangle from the row index (starting at index 1) e.g.:

rowSumOddNumbers(1); // 1
rowSumOddNumbers(2); // 3 + 5 = 8
*/
#include <iostream>

using namespace std;

int nthOdd(int index) {
  int num = 2 * index - 1;
  return num;
}

long long rowSumOddNumbers(unsigned n){
  int num_odds = 0, i = 0;
  long long sum = 0;
  
  // Calculate Total Number Of Odds In Triangle
  for (i = n; i > 0; i--) {
    num_odds += i;
  }
  
  int last_odd = (num_odds * 2) - 1;
  
  // Sum Total Of Row
  for ( i = num_odds; i > (num_odds - n); i-- ) {
    sum += nthOdd(i);
  }
  
  return sum;
}

// Testing Function
int main(void) {
    int num_rows = 5;
    cout << "Sum of " << num_rows <<"th row is: " << rowSumOddNumbers(num_rows) << endl;
    return 0;
}
