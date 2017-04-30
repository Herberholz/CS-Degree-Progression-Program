//Cody Herberholz, CS202, Program #2
//course.h
//This file contains the Course Abstract Base Class and then derived from it we 
//have the CS, Non_cs, and Elective classes. The display has been set as a pure
//virtual function in Course with each class having a unique display. It also 
//contains a virtual destructor in order to dealocate the correct memory. the 
//three derived classes signify the different types of courses. 



#include <iostream>
#include <cctype>
#include <cstring>



//This is the Abstract Base Class. The purpose of this class is to contain all
//the information of a course. It can take in a name to compare to its own, insert
//course info, give its information to another class, and display.
class Course
{
    public:
        Course();
        virtual ~Course();

        int compare_name(char * match);//Compares incoming name with current name
        int insert_data(); //inserts course info
        float give_gpa(); //gives gpa
        int give_credits(); //gives credits
        virtual void display() = 0; //pure virtual display
        Course *& go_next(); //returns address of next

    protected:
        Course * next; //pointer to next course
        int credits; //course credits
        char * grade; //grade of course
        char * name; //name of course
        
};



//This class stipulates a specific Course that is a CS Course which has a virtual 
//display function
class Cs: public Course
{
    public:
        Cs();
        void display();

    protected:

};



//This class stipulates a specific Course that is a Non_cs Course which has a virtual
//display function
class Non_cs: public Course
{
    public:
        Non_cs();
        void display();

    protected:

};



//This class stipulates a specific Course that is an Elective Course which has 
//a virtual display function
class Elective: public Course
{
    public:
        Elective();
        void display();

    protected:

};

