#ifndef roster_h
#define roster_h
#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>
using namespace std;

class Roster{
public:
    Student* classRosterArray[5];
    int size;
    int Index;
    Roster();
    void parse(string studentData);
    ~Roster();
    
    
    void printAll(); // tab-separated list of student data in this format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security.
    void printInvalidEmails(); // a valid email must include an at (@), a period (.), and no spaces.
    void printAverageDaysInCourse(string ID);
    void printByDegreeProgram(DegreeProgram);
    void remove(string ID);
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    
private:
    
};
    
#endif /* roster_h */
