#include "student.h"
#include "roster.h"
#include "softwareStudent.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include <iostream>
using namespace std;

Roster::Roster() {
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;

}

Roster::Roster(int capacity) {
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new student*[capacity];

}

student * Roster::studentIndex(int index) {

	return  classRosterArray[index];
}

void Roster::parseData(string data) {

	if (lastIndex < capacity) {
		lastIndex++;
		Degree degreeType;
  		 		
		int right = data.find(",");
		string studentID = data.substr(0, right);

		int left = right + 1;
		right = data.find(",", left);
		string firstName = data.substr(left, right - left);

		left = right + 1;
		right = data.find(",", left);
		string lastName = data.substr(left, right - left);

		left = right + 1;
		right = data.find(",", left);
		string emailAddress = data.substr(left, right - left);

		left = right + 1;
		right = data.find(",", left);
		int age = stoi(data.substr(left, right - left));


		left = right + 1;
		right = data.find(",", left);
		int dIC1 = stoi(data.substr(left, right - left));

		left = right + 1;
		right = data.find(",", left);
		int dIC2 = stoi(data.substr(left, right - left));

		left = right + 1;
		right = data.find(",", left);
		int dIC3 = stoi(data.substr(left, right - left));


		if (data.back() == 'E') degreeType = SOFTWARE;
		else if (data.back() == 'Y') degreeType = SECURITY;
		else if (data.back() == 'K') degreeType = NETWORK;
		else
		{
			cerr << "Invalid degree type\n";
			exit(-1);
		}


		add(studentID, firstName, lastName, emailAddress, age, dIC1, dIC2, dIC3, degreeType);
	}
	else
	{
	cerr << "ERROR! LIST HAS EXCEEDED MAXIMUM CAPACITY!\n EXITING NOW!";
	exit(-1);
	}

};

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree deg)
{

	int daysArray[student::numberOfDaysArray];
	daysArray[0] = daysInCourse1;
	daysArray[1] = daysInCourse2;
	daysArray[2] = daysInCourse3;
	if (deg == SOFTWARE) {
		classRosterArray[lastIndex] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysArray, deg);
	}
	else if (deg == SECURITY) {
		classRosterArray[lastIndex] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysArray, deg);
	}
	else if (deg == NETWORK) {
		classRosterArray[lastIndex] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysArray, deg);
	}

};

void Roster::printAll() {
	for (int i = 0; i <= this->lastIndex; i++)
	{
		(this->classRosterArray)[i]->print();
		cout << endl;
	}
}

void Roster::remove(string studentID) {
	for (int i = 0; i <= lastIndex; i++) 
	{
		if (this->classRosterArray[i]->GetStudentID() == studentID) {
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			cout << studentID << " was removed" << endl;
			lastIndex--;
			return;
		}
	}
		cout << "student " << studentID << " not found"; 
}

void Roster::printDaysInCourse(string studentID) {
	bool found = false;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->GetStudentID() == studentID)
		{
			found = true;
			int* n = classRosterArray[i]->GetNumberOfDays();
			cout <<  "average number of days for " << studentID << " is " << (n[0] + n[1] + n[2]) / 3 << endl;
		}
	}
	if (!found) cout << "student was not found " << endl;
}

void Roster::printInvalidEmails() {
	cout << "these are the invalid emails" << endl;
	

	for (int i = 0; i <= lastIndex; i++)
	{
		string email = classRosterArray[i]->GetEmailAddress();
		if (email.find('.') != string::npos)
		{
			if (email.find('@') != string::npos)
			{
				if (email.find(' ') != string::npos)
				{
					cout << email << " is invalid" << endl;
				}
			}
			else cout << email << " is invalid" << endl;
		}
		else cout << email << " is invalid" << endl;
	}
};

void Roster::printByDegreeProgram(int degreeProgram) {

	cout << "these are the students in SOFTWARE " << endl;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->GetDegreeType() == degreeProgram) {
			this->classRosterArray[i]->print();
			cout << endl;
		}
	}
};

Roster::~Roster() {

	for (int i = 0; i <= lastIndex; i++)
	{
		delete this->classRosterArray[i];
	}
	delete classRosterArray;
}




int main() {

	cout << "Scripting and Programming  Applications  C867" << endl;
	cout << "C++" << endl;
	cout << "001231776" << endl;
	cout << "Steven C. Bergstrom" << endl;

	int students = 5;

	const string studentData[5] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,steven,bergstrom,sbergs7@wgu.edu,25,20,21,22,SOFTWARE"
	};



	Roster* classRoster = new Roster(5);

	for (int i = 0; i < students; i++) {
		classRoster->parseData(studentData[i]);
	}
	
	cout << "printing the roster" << endl;

	classRoster->printAll();

	cout << "printing invalid emails" << endl;

	classRoster->printInvalidEmails();

	cout << "print average number of days" << endl;

	for (int i = 0; i < students; i++) {
		classRoster->printDaysInCourse(classRoster->studentIndex(i)->GetStudentID());
	}

	cout << "print SOFTWARE students" << endl;

	classRoster->printByDegreeProgram(SOFTWARE);

	cout << "removing A3" << endl;
	
	classRoster->remove("A3");

	cout << "trying to remove A3 again" << endl;

	classRoster->remove("A3");
	
	classRoster->~Roster();

	return 0;
}