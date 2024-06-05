#include "roster.h"
#include "student.h"
using namespace std;

Roster::Roster(){
    this->size=0;
}

//parse function definition
void Roster::parse(string studentData) {
    size_t rhs = studentData.find(",");
    string studentID = studentData.substr(0, rhs);
    
    size_t lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string firstName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lastName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs +1;
    rhs = studentData.find(",", lhs);
    string emailAddress = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int age = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));
    
    DegreeProgram degreeProgram = DegreeProgram::NETWORK;
    
    lhs = rhs + 1;
    string degreeString = studentData.substr(lhs);
    
    if (degreeString == "NETWORK") {
        degreeProgram = DegreeProgram::NETWORK;
    }
    else if (degreeString == "SECURITY") {
        degreeProgram = DegreeProgram::SECURITY;
    }
    else {
        degreeProgram = DegreeProgram::SOFTWARE;
    }
    
    this->add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    
}


//printAll function definition
void Roster::printAll(){
    cout << "ID\tFirst Name\tLast Name\tEmail\t\t\tAge\tDays in Course\tDegree Program\n";
    for (int i=0; i < this->size; i++) {
        this->classRosterArray[i]->print();
    }
}

//printInvalidEmails function definition
void Roster::printInvalidEmails(){
  for (int i = 0; i < this->size; i++) {
        
        string emailAddress = classRosterArray[i]->getEmail();
        if (emailAddress.find('@') == string::npos || emailAddress.find('.') == string::npos) {
            cout << emailAddress << endl;
        }
    }
    for (int i = 0; i < this->size; i++){
        string emailAddress = (classRosterArray[i]->getEmail());
        
        size_t space = emailAddress.find(" ");
        if (space != string::npos) {
            cout << emailAddress << endl;
        }
    }
}


//printAverageDaysInCourse function definition
void Roster::printAverageDaysInCourse(string ID){
            for (int i=0; i < this->size; i++) {
                if (this->classRosterArray[i]->getID() == ID) {
                    double* days = this->classRosterArray[i]->getNumDaysToComplete();
                    double average = (days[0] + days[1] + days [2]) / 3.0;
                    cout << average;
        }
    }
}
      
//printByDegree function definition
void Roster::printByDegreeProgram(DegreeProgram dp){
                bool foundstudent = false;
                for (int i=0; i< this->size; i++) {
                    Student* student = this->classRosterArray[i];
                    if (dp == student->getDegreeProgram()) {
                        student->print();
                        foundstudent = true;
       }
   }
    
}

//remove function definition
void Roster::remove(string ID){
    bool IDfound = false;
    for (int i = 0; i < this->size; i++) {
        if (this->classRosterArray[i]->getID() == ID) {
            IDfound = true;
            delete this->classRosterArray[i];
            this->classRosterArray[i] = this->classRosterArray[Index];
            this->Index--;
        }
    }
    if (!IDfound) {
        cout << "Student was not found" << endl;
    }
}

    
// add function definition
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
        double days[3];
        days[0] = daysInCourse1;
        days[1] = daysInCourse2;
        days[2] = daysInCourse3;
        Student *s = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
        this->classRosterArray[this->size] = s;
        this->size++;
        
}
    

//deconstructor definition
    Roster::~Roster() {
        for (int i=0; i < this->size; i++) {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
  }
}

