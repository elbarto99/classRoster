#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "roster.h"
#include "degree.h"
using namespace std;

/**
* Main method to launch the classRoster program and complete assignment output.
* @author Steven Barton
**/
int main() {
	// Assignment input array:
	const string studentData[] =
	{ "Al,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
	"AS,Steven,Barton,sbart48@wgu.edu,36,13,34,28,SOFTWARE" };

	// Printing the assignment header with student info:
	cout << "Scripting and Programming - Applications - C867, C++, Student ID #XXXXXXXXXXX, Steven J. Barton" << endl << endl;

	// Creating the base roster instance:
	roster classRoster;

	// Creating the string variables to recieve istream input:
	string studentID;
	string firstName;
	string lastName;
	string email;
	string age;
	string days1;
	string days2;
	string days3;
	string degreeProgramString;

	/*
	* Necessary instance variables have been created, the class roster will be constructed below.
	*/
	
	// Loop through the array to extract each student
	for (int i = 0; i < 5; i++) {
		// Create a new degree program object to pass values to students
		DegreeProgram degreeProgramObj;
		// Create a new stream for each string in the array
		istringstream studentsIn(studentData[i]);

		// Extract student data to string vars via the stream
		getline(studentsIn, studentID, ',');
		getline(studentsIn, firstName, ',');
		getline(studentsIn, lastName, ',');
		getline(studentsIn, email, ',');
		getline(studentsIn, age, ',');
		getline(studentsIn, days1, ',');
		getline(studentsIn, days2, ',');
		getline(studentsIn, days3, ',');
		getline(studentsIn, degreeProgramString, ',');

		// Parse int values into their types
		int studentAge;
		int daysToComplete1;
		int daysToComplete2;
		int daysToComplete3;

		istringstream intParse(age);
		intParse >> studentAge;

		istringstream intParse2(days1);
		intParse2 >> daysToComplete1;

		istringstream intParse3(days2);
		intParse3 >> daysToComplete2;

		istringstream intParse4(days3);
		intParse4 >> daysToComplete3;

		// Parse string input for degree into a DegreeProgram value
		if (degreeProgramString == "SECURITY") {
			degreeProgramObj.degreeProg = SECURITY;
		}
		else if (degreeProgramString == "NETWORK") {
			degreeProgramObj.degreeProg = NETWORK;
		}
		else if (degreeProgramString == "SOFTWARE") {
			degreeProgramObj.degreeProg = SOFTWARE;
		}

		// Create a student object and add it to the roster (the roster creates a student in the add function)
		classRoster.add(studentID, firstName, lastName, email, studentAge, daysToComplete1, daysToComplete2, daysToComplete3
			, degreeProgramObj);
	}

	/* 
	* The class roster is complete here, the function output follows below.
	*/

	cout << "roster::printAll() function output:" << endl;
	classRoster.printAll();
	cout << endl;


	cout << "roster::printInvalidEmails() function output:" << endl;
	classRoster.printInvalidEmails();
	cout << endl;


	cout << "roster::printAverageDaysInCourse() function output:" << endl;
	string student;
	for (int i = 0; i < classRoster.length(); i++) {
		student = classRoster.at(i).getStudentId();
		cout << student << ": \t";
		classRoster.printAverageDaysInCourse(student);
		cout << endl;
	}
	cout << endl;


	cout << "roster::printByDegreeProgram(SOFTWARE) function output:" << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;


	cout << "roster::remove(A3) function call..." << endl;
	classRoster.remove("A3");


	cout << "roster::printAll() function output:" << endl;
	classRoster.printAll();
	cout << endl;


	cout << "roster::remove(A3) function call..." << endl;
	classRoster.remove("A3");
	cout << endl << "Complete..." << endl;


	return 0;
}
