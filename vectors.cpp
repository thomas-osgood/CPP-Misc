/*
 * Created By: Thomas Osgood
 *
 * Description:
 * 	Basic demonstration of VECTORS in C++.
 *
 * To Compile:
 * 	g++ -o vectors vectors.cpp
 */

/* Required Includes */
#include <iostream>
#include <vector>

/* Declare Which Namespace To Use */
using namespace std;

/* Templates */
template <typename T>
/*
 * Function Name: printVector
 * Description:
 * 	Function to print the contents of a vector.
 * Input(s):
 * 	vec - vector to print.
 * Return(s):
 * 	None
 */
void printVector(T vec) {
	typename T::iterator i;
	int a = 0;
	for (i = vec.begin(); i != vec.end(); i++, a++) {
		cout << "value [" << a+1 << "] : " << vec[a] << endl;
	}
	return;
}

template <typename T>
/*
 * Function Name: inVector
 * Description:
 * 	Function to determine whether a value is in
 * 	the given vector.
 * Input(s):
 * 	v - vector to check.
 * 	k - key to look for.
 * Return(s):
 * 	true - value in vector
 * 	false - value not in vector
 */
bool inVector(T v, T k) {
	typename T::iterator i;
	int a = 0;
	for (i = v.begin(); i != v.end(); i++, a++) {
		if (v[a] == k) {
			return true;
		}
	}
	return false;
}

/* Function Prototypes */
void printChar(char c, int n);

/*
 * Function Name: Main
 * Description:
 * 	Main function. Called everytime the program
 * 	is run.
 * Input(s):
 * 	None
 * Return(s):
 * 	Exit Code - Integer indicating how program exits.
 */
int main(void) {
	/* Declare & Initialize Local Variables */
	vector<int> grades;
	vector<string> names;
	int i = 0;
	int vec_size = 10;

	/* Build Grades Vector */
	cout << "[*] Filling Up Grades VECTOR" << endl;
	printChar('-',30);
	for( i = 0; i < vec_size; i++) {
		grades.push_back(i);
	}

	/* Build Names Vector */
	cout << "[*] Filling Up Names VECTOR" << endl;
	printChar('-',30);
	names.push_back("Thomas");
	names.push_back("Jane");
	names.push_back("Bob");
	names.push_back("Amanda");

	/* Display Grades Vector */
	cout << endl << "[*] Printing Grades VECTOR" << endl;
	printChar('-',30);
	printVector(grades);

	/* Display Names Vector */
	cout << endl << "[*] Printing Names VECTOR" << endl;
	printChar('-',30);
	printVector(names);

	return 0;
}

/*
 * Function Name: printChar
 * Description:
 * 	Print a specified number of characters on one line.
 * Input(s):
 * 	c - character to print.
 * 	n - number of characters to print.
 * Return(s):
 * 	None
 */
void printChar(char c, int n) {
	int i = 0;
	
	if (n < 0) {
		n *= -1;
	}

	for(i = 0; i < n; i++) {
		cout << c;
	}
	cout << endl;

	return;
}
