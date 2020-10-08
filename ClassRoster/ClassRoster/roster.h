#pragma once
#include <vector>
#include "student.h"

/**
* Roster class which contains student objects as a class roster.
* @author Steven Barton
**/

// Initial size for the array when the roster instance is created.
const int STARTSIZE = 10;

/**
* Roster class which contains student objects as a class roster.
* @author Steven Barton
**/
class roster
{
public:
	roster(); // Default constructor.
	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2,
		int daysInCourse3, DegreeProgram degreeProgram);
	void remove(std::string studentID);
	void printAll();
	void printAverageDaysInCourse(std::string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(degree degreeProgram);
	int length(); // Public helper function which returns the length(int size) of the class roster.
	student at(int index); // Public helper function allowing iteration through but not changing of the private roster array.

private:
	student* classRosterArray; // Pointer variable to allow for the creation of the array of students in the constructor.
	int size; // Tracks the current size of the roster (not the array).
	int arraySize; // Tracks the current size of the array (not the roster).
	void grow(); // Private helper function which allows the array to grow dynamically as students are added.
};

