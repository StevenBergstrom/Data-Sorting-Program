#pragma once
#include <string>
#include <iostream>
#include "student.h"
#include "softwareStudent.h"
#include "securityStudent.h"
#include "networkStudent.h"

class Roster {

private:
	int lastIndex;
	int capacity;
	student** classRosterArray;

public:

	Roster();
	Roster(int capacity);


	student* studentIndex(int index);
	void parseData(string studentData);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree deg);
	void remove(string studentID);
	void printAll();
	void printDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(int degreeProgram);
	~Roster();


};