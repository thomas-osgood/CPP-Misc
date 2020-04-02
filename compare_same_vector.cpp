/*
Given two arrays a and b write a function comp(a, b) (compSame(a, b) in Clojure) that checks whether the two arrays have the "same" elements, with the same multiplicities. "Same" means, here, that the elements in b are the elements in a squared, regardless of the order.
Examples
Valid arrays

a = [121, 144, 19, 161, 19, 144, 19, 11]  
b = [121, 14641, 20736, 361, 25921, 361, 20736, 361]

comp(a, b) returns true because in b 121 is the square of 11, 14641 is the square of 121, 20736 the square of 144, 361 the square of 19, 25921 the square of 161, and so on. It gets obvious if we write b's elements in terms of squares:

a = [121, 144, 19, 161, 19, 144, 19, 11] 
b = [11*11, 121*121, 144*144, 19*19, 161*161, 19*19, 144*144, 19*19]

Invalid arrays

If we change the first number to something else, comp may not return true anymore:

a = [121, 144, 19, 161, 19, 144, 19, 11]  
b = [132, 14641, 20736, 361, 25921, 361, 20736, 361]

comp(a,b) returns false because in b 132 is not the square of any number of a.

a = [121, 144, 19, 161, 19, 144, 19, 11]  
b = [121, 14641, 20736, 36100, 25921, 361, 20736, 361]

comp(a,b) returns false because in b 36100 is not the square of any number of a.
Remarks

a or b might be [] (all languages except R, Shell). a or b might be nil or null or None or nothing (except in Haskell, Elixir, C++, Rust, R, Shell, PureScript).

If a or b are nil (or null or None), the problem doesn't make sense so return false.

If a or b are empty then the result is self-evident.

a or b are empty or not empty lists.
*/
#import <vector>
#import <math.h>

using namespace std;

class Same {
    public :static bool comp(vector<int>, vector<int>);
};

/*
Function Name: comp
Description:
    Function to compare two vectors using the criteria
    listed above.  This is a function for the class
    'Same'
Input(s):
    a - integer vector
    b - integer vector
Return(s):
    true - bool. vectors meet criteria
    false - bool. vectors don't meet criteria.
*/
bool Same::comp(vector<int> a, vector<int> b) {
    /* Local Variables */
    bool retVal = true;
    bool stillGood = false;
    int asize = a.size();
    int bsize = b.size();
    int i = 0, cntSQ = 0, cntB = 0;
    int sq = 0;
    vector<int> sqvec;
    
    /* IF-ELSE Block For Calculation */
    if ((asize == 0) && (bsize == 0)) {
        return true;
    } else if (a.size() != b.size()) {
        retVal = false;
    } else {
        /* Loop To Generate Square Vector */
        for (i = 0; i < asize; i++) {
            sq = pow(a.at(i), 2);
            sqvec.push_back(sq);
        }
        
        /* Compare B Vector To Square Vector */
        for (i = 0; i < bsize; i++) {
            cntSQ = count(sqvec.begin(), sqvec.end(), b.at(i));
            cntB = count(b.begin(), b.end(), b.at(i));
            
            //cout << "Number: " << b.at(i) << " | CSQ: " << cntSQ << " | CB: " << cntB << endl;
            
            if (cntSQ == cntB) {
                stillGood = true;
            } else {
                stillGood = false;
                break;
            }
        }
        
        /* Set Return Value */
        if (stillGood) {
            retVal = true;
        } else {
            retVal = false;
        }
    }
    
    return retVal;
}

