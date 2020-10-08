#include "student.h"
#include "degree.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

/**
* Student object which builds each student in the roster.
* @author Steven Barton
**/

/**
* Loaded constructor to create a student object
**/
student::student(string ID, string first, string last, string email, int age, int days1, int days2, int days3, DegreeProgram program) {
	studentId = ID;
	firstName = first;
	lastName = last;
	emailAddress = email;
	studentAge = age;
	daysToComplete[0] = days1;
	daysToComplete[1] = days2;
	daysToComplete[2] = days3;
	degreeProg = program;
}


/**
* Default constructor
**/
student::student() {
	student::setStudentId("-1");
}


/**
* Accessor for student id
**/
string student::getStudentId() {
	return studentId;
}


/**
* Accessor for first name
**/
string student::getFirstName() {
	return firstName;
}


/**
* Accessor for last name
**/
string student::getLastName() {
	return lastName;
}


/**
* Accessor for email address
**/
string student::getEmail() {
	return emailAddress;
}


/**
* Accessor for student age
**/
int student::getAge() {
	return studentAge;
}


/**
* Accessor for days to complete array
**/
string student::getDaysToComplete() {

	string daysReturn = "{";

	for (int i = 0; i < 3; i++) {
		if (i < 2) {
			daysReturn = daysReturn + to_string(daysToComplete[i]) + ", ";
		}
		else {
			daysReturn = daysReturn + to_string(daysToComplete[i]) + "}";
		}
	}

	return daysReturn;
}


/**
* Accessor for student degree program
**/
DegreeProgram student::getDegreeProgram() {

	return degreeProg;
}


/**
* Mutator for student ID
**/
void student::setStudentId(string ID) {
	studentId = ID;
	return;
}


/**
* Mutator for first name
**/
void student::setFirstName(string first) {
	firstName = first;
	return;
}


/**
* Mutator for last name
**/
void student::setLastName(string last) {
	lastName = last;
	return;
}


/**
* Mutator for email
**/
void student::setEmail(string email) {
	emailAddress = email;
	return;
}


/**
* Mutator for age
**/
void student::setAge(int age) {
	studentAge = age;
	return;
}


/**
* Mutator for days to complete values
**/
void student::setDaysToComplete(int days1, int days2, int days3) {
	daysToComplete[0] = days1;
	daysToComplete[1] = days2;
	daysToComplete[2] = days3;
	return;
}


/**
* Mutator for degree program
**/
void student::setDegreeProgram(DegreeProgram program) {
	degreeProg = program;
	return;
}


/**
* Function to print student info
**/
void student::printStudent() {

	// Block of code follows to get the degree program and parse it into a string value for printing
	string degreePrint;

	DegreeProgram degreeToPrint = student::getDegreeProgram();

	if (degreeToPrint.degreeProg == SOFTWARE) {
		degreePrint = "Software";
	}
	else if (degreeToPrint.degreeProg == NETWORK) {
		degreePrint = "Network";
	}
	else {
		degreePrint = "Security";
	}

	// Block of code to print each get method (getDegreeProgram called above) output
	cout << student::getStudentId() << '\t';
	cout << "First Name: " << student::getFirstName() << '\t';
	cout << "Last Name: " << student::getLastName() << '\t';
	cout << "Age: " << student::getAge() << '\t';
	cout << "daysInCourse: " << student::getDaysToComplete() << '\t';
	cout << "Degree Program: " << degreePrint << endl;

	return;
}
