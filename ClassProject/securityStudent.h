#pragma once
#include <iostream>
#include "student.h"
#include "degree.h"

class SecurityStudent : public student {

public:

	SecurityStudent();
	SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int numberOfDays[], Degree dType);


	Degree GetDegreeType();

	void print();

	~SecurityStudent();
};