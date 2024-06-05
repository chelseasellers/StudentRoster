#include "student.h"

/*constructor definition*/
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, double numDaysToComplete[], DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age=age;
    for (int i = 0; i < 3; i++) {
        this->numDaysToComplete[i] = numDaysToComplete[i];
    }
    this->degreeProgram=degreeProgram;
}




//getter function definitions

string Student::getID(){
    return this->studentID;
}
string Student::getFirstName() {
    return this->firstName;
}
string Student::getLastName() {
    return this->lastName;
}
string Student::getEmail() {
    return this->emailAddress;
}
int Student::getAge() {
    return this->age;
}
double* Student::getNumDaysToComplete() {
    return this->numDaysToComplete;
}
DegreeProgram Student::getDegreeProgram() {
    return this->degreeProgram;
}

//setter function definitions

void Student::setID(string studentID) {
    this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}
void Student::setLastName(string lastName) {
    this->lastName = lastName;
}
void Student::setEmail(string emailAddress) {
    this->emailAddress = emailAddress;
}
void Student::setAge(int age) {
    this->age = age;
}
void Student::setNumDays(double* numDaysToComplete[]) {
    for (int i = 0; i < 3; i++) {
        this->numDaysToComplete[i] = *numDaysToComplete[i];
    }
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram=degreeProgram;
}

void Student::print()
{
  cout << this->getID() << '\t';
    cout << this->getFirstName() << '\t';
    cout << this->getLastName() << '\t';
    cout << this->getEmail() << '\t';
    cout << this->getAge() << '\t';
    cout << '{';
    cout << this->numDaysToComplete[0] << ", ";
    cout << this->numDaysToComplete[1] << ", ";
    cout << this->numDaysToComplete[2] << "}";
    if (this->degreeProgram == DegreeProgram::SECURITY) {
        cout << " Security" << endl;
    }
    else if (this->degreeProgram == DegreeProgram::NETWORK) {
        cout << " Network" << endl;
    }
    else {
        cout << " Software" << endl;
    }
    
    }
   

