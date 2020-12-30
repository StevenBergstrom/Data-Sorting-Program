#include <iostream>
#include "softwareStudent.h"

SoftwareStudent::SoftwareStudent():student() {
	degreeType = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int numberOfDays[], Degree dType)
	:student(studentID, firstName, lastName, emailAddress, age, numberOfDays) {
	degreeType = SOFTWARE;
}

Degree SoftwareStudent::GetDegreeType() {
	return SOFTWARE;
}

void SoftwareStudent::print() {
	cout << left << "ID: " << GetStudentID() << "\t";
	cout << left << "First Name: " << GetFirstName() << "\t";
	cout << left << "Last Name: " << GetLastName() << "\t";
	cout << left << "Age: " << GetAge() << "\t";
	cout << left << "daysInCourse: {" << GetNumberOfDays()[0] << "," << GetNumberOfDays()[1] << "," << GetNumberOfDays()[2] << "}" << "\t";
	cout << "Degree Program: SOFTWARE" << endl;
}

SoftwareStudent::~SoftwareStudent() {
	student::~student();
}