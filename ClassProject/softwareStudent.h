#pragma once
#include <string>
#include "student.h"
#include "degree.h"

class SoftwareStudent : public student {

public:

	SoftwareStudent();
	SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int numberOfDays[], Degree dType);


	Degree GetDegreeType();

	void print();

	~SoftwareStudent();
};
