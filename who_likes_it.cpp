/*
    Pass in a string vector of names and have the 
    function spit back out who likes it (if anyone)
    in a specific format.
    
    If there are more than three people in the names
    vector, the format will be:
        adam, bob, and x others like it
    
    If the names vector is empty the return will be:
        no one likes this
    
    And so on...
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

std::string likes(const std::vector<std::string> &names)
{
    /* Set Up Local Variables */
    int others = 0;
    int n = names.size();
    std::ostringstream sStream;
    std::string returnVal;
    
    /* Go Through All Possible Cases */
    if (n == 0) {
      sStream << "no one likes this";
    } else if (n == 1) {
      // 1 Person Likes It
      sStream << *names.begin() << " likes this";
    } else if( n > 1 && n < 4) {
        if (n == 2) {
          // 2 People Like It
          std::string name1, name2;
          name1 = names.at(0);
          name2 = names.at(1);
          sStream << name1 << " and " << name2 << " like this";
        } else {
           // 3 People Like It
          std::string name1, name2, name3;
          name1 = names.at(0);
          name2 = names.at(1);
          name3 = names.at(2);
          sStream << name1 << ", " << name2 << " and " << name3 << " like this";
        }
    } else {
        // More Than 3 People Like It
        others = n - 2;
        std::string name1, name2;
        name1 = names.at(0);
        name2 = names.at(1);
        sStream << name1 << ", " << name2 << " and " << others << " others like this";
    }
    
    returnVal = sStream.str();
    return returnVal;
}

// Main Function For Testing 'likes'
int main(void) {
	vector<string> names;
	names.push_back("Bob");
	names.push_back("Amanda");

	cout << likes(names) << endl;

	return 0;
}
