#include <iostream>
#include "networkStudent.h"

NetworkStudent::NetworkStudent():student() {
	degreeType = NETWORK;
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int numberOfDays[], Degree dType)
	:student(studentID, firstName, lastName, emailAddress, age, numberOfDays) {
	degreeType = NETWORK;
}

Degree NetworkStudent::GetDegreeType() {
	return NETWORK;
}

void NetworkStudent::print() {
	cout << left << "ID: " << GetStudentID() << "\t";
	cout << left << "First Name: " << GetFirstName() << "\t";
	cout << left << "Last Name: " << GetLastName() << "\t";
	cout << left << "Age: " << GetAge() << "\t";
	cout << left << "daysInCourse: {" << GetNumberOfDays()[0] << "," << GetNumberOfDays()[1] << "," << GetNumberOfDays()[2] << "}" << "\t";
	cout << "Degree Program : NETWORK" << endl;
}

NetworkStudent::~NetworkStudent() {
	student::~student();
}