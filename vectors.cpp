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
#include <ctime>
#include <iostream>
#include <vector>

/* Declare MACROs */
#define KILO 1024
#define BYTE 8

/* Function Prototypes */
void printChar(char c, int n);

/* Declare Which Namespace To Use */
using namespace std;

/* Struct Definitions */
typedef struct {
	string firstName;
	string lastName;
	int age;
} Person;

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

/*
 * Function Name: printVector
 * Description:
 * 	Print info from Person vector.
 * Input(s):
 * 	vec - vector to print.
 * Return(s):
 * 	None
 */
void printVector(vector<Person> vec) {
	std::vector<Person>::iterator i;
	int a = 0;
	for (i = vec.begin(); i != vec.end(); i++, a++) {
		cout << "Person " << a+1 << " : " << endl;
		printChar('-',10);
		cout << vec[a].firstName << " " << vec[a].lastName << endl;
		cout << vec[a].age << " years old" << endl;
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
	vector<Person> people;
	int i = 0;
	int vec_size = 10;
	clock_t start, end;

	Person test;
	test.firstName = "Thomas";
	test.lastName = "Osgood";
	test.age = 30;

	people.push_back(test);

	/* begin timing */
	start = clock(); 
	
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

	cout << endl << "[*] Printing People VECTOR" << endl;
	printChar('-',30);
	cout << endl;
	printVector(people);
	
	/* end timing */
	end = clock(); 

	/* Display Timing Result */
	cout << endl << "Program took " << difftime(end,start)/CLOCKS_PER_SEC << " seconds to execute." << endl;
	
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
