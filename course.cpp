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
    delete [] grade;
}



//
int Course::compare_name(char * match)
{
    if(strcmp(name,match) == 0)
        return 1;
    return 0;
}



//
int Course::insert_data()
{
    char temp[50];
    char letter[20];

    cout << "\nPlease enter in the course name: ";
    cin.get(temp, 50, '\n');
    cin.ignore(100,'\n');

    name = new char[strlen(temp)+1];
    strcpy(name, temp);

    cout << "\nPlease enter in the credits earned: ";
    cin >> credits;
    cin.ignore(100, '\n');

    cout << "\nPlease enter your grade(Ex: A or B+): ";
    cin.get(letter, 20, '\n');
    cin.ignore(100, '\n');

    grade = new char[strlen(letter)+1];
    strcpy(grade, letter);

    return 1;
}



//
float Course::give_gpa()
{
    float gpa = 0.0;

    if(strcmp(grade, "A") == 0)
        gpa = 4 * credits;

    else if(strcmp(grade, "A-") == 0)
        gpa = 3.67 * credits;

    else if(strcmp(grade, "B+") == 0)
        gpa = 3.33 * credits;

    else if(strcmp(grade, "B") == 0)
        gpa = 3.00 * credits;

    else if(strcmp(grade, "B-") == 0)
        gpa = 2.67 * credits;

    else if(strcmp(grade, "C+") == 0)
        gpa = 2.33 * credits;

    else if(strcmp(grade, "C") == 0)
        gpa = 2.00 * credits;

    else if(strcmp(grade, "C-") == 0)
        gpa = 1.67 * credits;

    else if(strcmp(grade, "D+") == 0)
        gpa = 1.33 * credits;

    else if(strcmp(grade, "D") == 0)
        gpa = 1.00 * credits;

    else if(strcmp(grade, "D-") == 0)
        gpa = 0.67 * credits;

    return gpa;
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

