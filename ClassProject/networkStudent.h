#pragma once
#include <iostream>
#include "student.h"
#include "degree.h"

class NetworkStudent : public student {

public:
	NetworkStudent();
	NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int numberOfDays[], Degree dType);


	Degree GetDegreeType();

	void print();

	~NetworkStudent();
};
