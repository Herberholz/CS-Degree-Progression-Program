//Cody Herberholz, CS202, Program #2
//course.cpp



#include "course.h"
using namespace std;



//
Course::Course():next(0),credits(0),grade(0),name(0) {}



//
Course:: ~Course()
{
    delete [] name;
}



//
int Course::insert_data()
{
    char temp[50];

    cout << "\nPlease enter in the course name: ";
    cin.get(temp, 50, '\n');
    cin.ignore(100,'\n');

    name = new char[strlen(temp)+1];
    strcpy(name, temp);

    cout << "\nPlease enter in the credits earned: ";
    cin >> credits;
    cin.ignore(100, '\n');

    cout << "\nPlease enter your grade(EX: 0.0 - 4.0): ";
    cin >> grade;
    cin.ignore(100, '\n');
}



//
float Course::give_gpa()
{
    return grade;
}



//
int Course::give_credits()
{
    return credits;
}



//
Course *& Course::go_next()
{
    return next;
}



//
Cs::Cs() {}



//
void Cs::display() 
{
    cout << "\n  _________CS COURSE________" << endl;
    cout << " |Name: " << name << "|" << endl;
    cout << " |Grade: " << grade << "  \t\t|" << endl;
    cout << " |Credits: " << credits << "  \t\t|" << endl;
    cout << " |_______________________|" << endl;
}



//
Non_cs::Non_cs() {}



//
void Non_cs::display() 
{
    cout << "\n  _______NON-CS COURSE______" << endl;
    cout << " |Name: " << name << "\t|" << endl;
    cout << " |Grade: " << grade << "  \t\t|" << endl;
    cout << " |Credits: " << credits << "  \t\t|" << endl;
    cout << " |__________________________|" << endl;
}



//
Elective::Elective() {}



//
void Elective::display() 
{
    cout << "\n  _______ELECTIVE COURSE______" << endl;
    cout << " |Name: " << name << "|" << endl;
    cout << " |Grade: " << grade << "  \t\t|" << endl;
    cout << " |Credits: " << credits << "  \t\t|" << endl;
    cout << " |____________________________|" << endl;
}

