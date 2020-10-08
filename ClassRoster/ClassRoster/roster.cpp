#include "roster.h"
#include "student.h"
#include <iostream>
using namespace std;

/**
* Default constructor for the roster object.  Initiates to the initial size with student IDs for empty indices set as -1. 
**/
roster::roster() {
	classRosterArray = new student[STARTSIZE];
	size = 0;
	arraySize = STARTSIZE;
}


/**
* Add function to add a student to the student roster.
**/
void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2,
	int daysInCourse3, DegreeProgram degreeProgram) {

	// If the number of students is approaching the size of the array, call grow().
	if (size == arraySize - 1) {
		roster::grow();
	}

	student studentIn(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);

	classRosterArray[size] = studentIn;

	size++;
	
	return;

}


/**
* Remove function removes the student entry with matching student ID.
**/
void roster::remove(string studentID) {
	// True if studentID found
	bool studentRemoved = false;
	// Placeholder array insert position
	int pos = 0;

	student* copyArray = new student[arraySize];

	for (int i = 0; i < size; i++) {
		// Iterate through each value in the array
		if (studentID == classRosterArray[i].getStudentId()) {
			// If the student ID is found, set the value as removed and move on
			studentRemoved = true;
			continue;
		}
		else {
			// If the student ID is not found, copy the student into the placeholder array and increment the insert position
			copyArray[pos] = classRosterArray[i];
			pos++;
		}
	}

	if (studentRemoved) {
		// If studentID was found, we need to decrement size, and copy the values from the placeholder back in up to new size
		size--;
		for (int i = 0; i < size; i++) {
			classRosterArray[i] = copyArray[i];
		}
	}

	// If studentID not found, it was not in the array
	if (!studentRemoved) {
		cout << "Student ID does not exist!" << endl;
	}

	return;
}


/**
* Function to print all student entries in tab delimited format
**/
void roster::printAll() {

	student refStudent = classRosterArray[0];

	for (int i = 0; i < size; i++) {

		refStudent = classRosterArray[i];

		refStudent.printStudent();
	}

	return;
}


/**
* Function to print the average of days in course for the provided student.
**/
void roster::printAverageDaysInCourse(string studentID) {
	int averageDays = 0;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i].getStudentId() == studentID) {
			for (int j = 0; j < 3; j++) {
				averageDays = averageDays + classRosterArray[i].daysToComplete[j];
			}
			break;
		}
	}

	averageDays = averageDays / 3;

	cout << averageDays;

	return;
}


/**
* Function prints invalid emails. Invalid emails include those that do not include '@' and '.' and that include ' '.
**/
void roster::printInvalidEmails() {
	string email;
	int atCount;

	for (int i = 0; i < size; i++) {

		// Collect the email for the current student in the roster
		email.clear();
		email = classRosterArray[i].getEmail();

		// Reset the count for @ chars
		atCount = 0;

		for (int j = 0; j < email.size(); j++) {
			if (atCount > 1) {
				// if we have more than one @, print the email and break
				cout << email << endl;
				break;
			}
			else if (email.at(j) == ' ') {
				// print the email and break since it has a space in it
				cout << email << endl;
				break;
			}
			else if (j == (email.size() - 4) && email.at(j) != '.') {
				// if the char at length - 4 is not a period, print the email and break
				cout << email << endl;
				break;
			}
			else if (email.at(j) == '@') {
				// if the @ char is present here, increment
				atCount++;
			}
		}

		if (atCount == 0) {
			// if there is no @ characters, print 
			cout << email << endl;
		}
	}

	return;
}


/**
* Function which prints each student with the assigned degree program.
**/
void roster::printByDegreeProgram(degree degreeProgram) {

	student refStudent;
	degree refDegree = degreeProgram;
	degree studentDegree;

	for (int i = 0; i < size; i++) {

		refStudent = classRosterArray[i];

		studentDegree = refStudent.getDegreeProgram().degreeProg;

		if (refDegree == studentDegree) {
			refStudent.printStudent();
		}

	}

	return;
}


/**
* Function to return the current size of the student roster.
**/
int roster::length() {
	return size;
}


/**
* Function to increase the array size.
**/
void roster::grow() {

	// Increase the size indicator for the array.
	arraySize *= 2;

	// Create placeholder array of new size.
	student* tempArray = new student[arraySize];

	// Copy values over.
	for (int i = 0; i < size; i++) {
		tempArray[i] = classRosterArray[i];
	}

	// Point the initial array var to the placeholder memory location.
	delete[] classRosterArray;
	classRosterArray = tempArray;

	return;
}


/**
* Public function to allow for array access. Receives int input for an index, returns the student at the index.
* If the index is out of bounds returns a blank student with student id -1.
**/
student roster::at(int index) {
	if (index >= size) {
		cout << "Index out of bounds" << endl;
		return student();
	}

	return classRosterArray[index];
}