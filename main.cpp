#include <iostream>
using namespace std;
#include "student.h"
#include "roster.h"
#include <string>

int main()
{
    // course info and name
    cout << "Course: C867-Scripting and Programming - Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 010663654" << endl;
    cout << "Name: Chelsea Sellers" << endl;
    cout << endl;
    Roster roster;
    
    // input
    
    const string studentData[] =
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Chelsea,Sellers,csell93@wgu.edu,28,30,35,40,SOFTWARE"};
        
    // add students to roster
        for (int i = 0; i < 5; i++) {
            roster.parse(studentData[i]);
        }

    //printAll
    cout << "Students: " << endl;
        roster.printAll();
        cout << endl;
    
    //invalid emails
    cout << "Invalid Emails: "<< endl;
    roster.printInvalidEmails();
    cout << endl;
    
    //print by degree program
    cout <<"Student with Degree Type Software: " << endl;
    roster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << endl;
    
    //average days in course
    cout << "Average Days in Course: " << endl;
    for (int i=0; i < roster.size; i++) {
        roster.printAverageDaysInCourse(roster.classRosterArray[i]->getID());
    }
    cout << endl;
    cout << endl;
    
    
    //remove A3
    cout << "Removing Student A3" << endl;
    roster.remove("A3");
    cout << endl;
    
    
    //print all withiout A3
        roster.printAll();
        cout << endl;
    
    //attempt to remove A3 again (receive error)
    cout <<"Removing Student A3" <<endl;
    roster.remove("A3");

    
        return 0;
}
