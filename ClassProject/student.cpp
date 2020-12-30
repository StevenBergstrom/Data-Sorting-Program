#pragma once
#include <iostream>
#include "student.h"
using namespace std;


student::student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < numberOfDaysArray; i++) this->numberOfDays[i] = 0;
}

student::student(string ID, string first, string last, string email, int a, int numberOfDays[]) {
	this->studentID = ID;
	this->firstName = first;
	this->lastName = last;
	this->emailAddress = email;
	this->age = a;
	for (int i = 0; i < numberOfDaysArray; i++) this->numberOfDays[i] = numberOfDays[i];
}

string student::GetStudentID() {
	return studentID;
}


string student::GetFirstName() {
	return firstName;
}

string student::GetLastName() {
	return lastName;
}

string student::GetEmailAddress() {
	return emailAddress;
}

int student::GetAge() {
	return age;
}

int* student::GetNumberOfDays() {
	return numberOfDays;
}


void student::SetStudentID(string ID) {
	this->studentID = ID;
}
void student::SetFirstName(string first) {
	this->firstName = first;
}
void student::SetLastName(string last) {
	this->lastName = last;
}
void student::SetEmailAddress(string email) {
	this->emailAddress = email;
}
void student::SetAge(int a) {
	this->age = a;
}
void student::SetNumberOfDays(int numberOfDays[]) {
	for (int i = 0; i < numberOfDaysArray; i++)
		this->numberOfDays[i] = numberOfDays[i];
}



student::~student() {

}
