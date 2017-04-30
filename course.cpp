//Cody Herberholz, CS202, Program #2
//course.cpp
//This file implements the Course Abstract Base Class and its derived classes
//Cs, Non_CS, and Elective. The purpose of these classes are to hold the info
//neccessary for a course which will be linked together by a Linear Linked 
//List



#include "course.h"
using namespace std;



//Course Constructor which initializes all its data members
Course::Course():next(0),credits(0),grade(0),name(0) {}



//Course Destructor which deallocates name and grade
Course:: ~Course()
{
    delete [] name;
    delete [] grade;
}



//Task:   Compares incoming name with current name
//Input:  Match char pointer which is a name
//Output: Returns one if it was a match and zero if not
int Course::compare_name(char * match)
{
    if(strcmp(name,match) == 0)
        return 1;
    return 0;
}



//Task:   Asks user for course name, credits, and grade and stores them
//Input:  Takes in user input from buffer to store 
//Output: Returns one upon success
int Course::insert_data()
{
    char temp[50] = {'\0'}; //Temporarily holds name
    char letter[20] = {'\0'}; //Temporarily holds grade

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



//Task:   Takes letter grade and converts it into grade points for a single 
//        and then multiplies that by the number of credits and returning it
//Input:  None
//Output: Returns gpa
float Course::give_gpa()
{
    float gpa = 0.0; //Holds result of Grade Point * credits

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



//Task:   Gives credits to other class
//Input:  None
//Output: Returns credits
int Course::give_credits()
{
    return credits;
}



//Task:   Gives the address of next to whoever is asking
//Input:  None
//Output: Returns address of next
Course *& Course::go_next()
{
    return next;
}



//Constructor of the Cs Class
Cs::Cs() {}



//Task:  Displays the Course with relevant information to user
//Input: None
//Ouput: Displays course info
void Cs::display() 
{
    cout << "\n  _________CS_COURSE________" << endl;
    cout << " |Name: " << name << "|" << endl;
    cout << " |Grade: " << grade << "  \t\t|" << endl;
    cout << " |Credits: " << credits << "  \t\t|" << endl;
    cout << " |_______________________|" << endl;
}



//Constructor of Non_cs class
Non_cs::Non_cs() {}



//Task:   Displays all relevant information for the non_cs course
//Input:  None
//Output: Displays course info
void Non_cs::display() 
{
    cout << "\n  _______NON_CS_COURSE______" << endl;
    cout << " |Name: " << name << "\t|" << endl;
    cout << " |Grade: " << grade << "  \t\t|" << endl;
    cout << " |Credits: " << credits << "  \t\t|" << endl;
    cout << " |__________________________|" << endl;
}



//Constructor of the Elective class 
Elective::Elective() {}



//Task:   Displays all relevant information for the Elective course
//Input:  None
//Output: Displays course info
void Elective::display() 
{
    cout << "\n  _______ELECTIVE_COURSE______" << endl;
    cout << " |Name: " << name << "|" << endl;
    cout << " |Grade: " << grade << "  \t\t|" << endl;
    cout << " |Credits: " << credits << "  \t\t|" << endl;
    cout << " |____________________________|" << endl;
}

