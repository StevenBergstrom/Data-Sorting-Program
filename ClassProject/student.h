#pragma once
#include <string>
#include "degree.h"
using namespace std;

class student {

public:

	const static int numberOfDaysArray = 3;

protected:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int numberOfDays[numberOfDaysArray];
	Degree degreeType;

public:

	student();

	student(string ID, string first, string last, string email, int a, int num[]);

	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	int GetAge();
	int* GetNumberOfDays();
	virtual Degree GetDegreeType() = 0;

	void SetStudentID(string ID);
	void SetFirstName(string first);
	void SetLastName(string last);
	void SetEmailAddress(string email);
	void SetAge(int a);
	void SetNumberOfDays(int numberOfDays[]);

	virtual void print() = 0;

	~student();

};
