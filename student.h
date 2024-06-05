#include <iostream>
#include <string>
#include "degree.h"
using namespace std;
#ifndef student_h
#define student_h


//create student class

class Student {
    
  public:
    
//constructor declaration
    
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, double numDaysToComplete[], DegreeProgram degreeProgram);
    
//getter function declarations
    
    string getID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    double* getNumDaysToComplete();
    DegreeProgram getDegreeProgram();
    
//setter function declarations
    
    void setID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string emailAddress);
    void setAge(int age);
    void setNumDays(double* numDaysToComplete[]);
    void setDegreeProgram(DegreeProgram degreeProgram);
    void print(); // to print specific student data
    
private:
    //private data members
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    double numDaysToComplete[3];
    DegreeProgram degreeProgram;
    
};

#endif /* student_h */
