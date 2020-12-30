#include <iostream>
#include "SecurityStudent.h"

SecurityStudent::SecurityStudent():student() {
	degreeType = SECURITY;
}

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int numberOfDays[], Degree dType)
	:student(studentID, firstName, lastName, emailAddress, age, numberOfDays) {
	degreeType = SECURITY;
}

Degree SecurityStudent::GetDegreeType() {
	return SECURITY;
}

void SecurityStudent::print() {
	cout << left << "ID: " << GetStudentID() << "\t";
	cout << left << "First Name: " << GetFirstName() << "\t";
	cout << left << "Last Name: " << GetLastName() << "\t";
	cout << left << "Age: " << GetAge() << "\t";
	cout << left << "daysInCourse: {" << GetNumberOfDays()[0] << "," << GetNumberOfDays()[1] << "," << GetNumberOfDays()[2] << "}" << "\t";
	cout << "Degree Program: SECURITY" << endl;
}

SecurityStudent::~SecurityStudent() {
	student::~student();
}