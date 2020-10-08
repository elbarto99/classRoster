#pragma once
#include <string>
#include "degree.h"

/**
* Student class creates an individual student.
* @author Steven Barton
**/
class student
{
public:
	// Constructor
	student(std::string ID, std::string first, std::string last, std::string email, int age, int days1, int days2, int days3, DegreeProgram program);
	// Default constructor
	student();
	// Accessor functions
	std::string getStudentId();
	std::string getFirstName();
	std::string getLastName();
	std::string getEmail();
	int getAge();
	std::string getDaysToComplete();
	DegreeProgram getDegreeProgram();
	// Mutator functions
	void setStudentId(std::string ID);
	void setFirstName(std::string first);
	void setLastName(std::string last);
	void setEmail(std::string email);
	void setAge(int age);
	void setDaysToComplete(int days1, int days2, int days3);
	void setDegreeProgram(DegreeProgram program);
	// Print function
	void printStudent();

	std::string studentId;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int studentAge;
	int daysToComplete[3];
	DegreeProgram degreeProg;

private:

};

