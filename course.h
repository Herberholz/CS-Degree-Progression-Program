//Cody Herberholz, CS202, Program #2
//course.h



#include <iostream>
#include <cctype>
#include <cstring>



//This is the Abstract Base Class
class Course
{
    public:
        Course();
        virtual ~Course();

        int insert_data();
        float give_gpa();
        int give_credits();
        virtual void display() = 0;
        Course *& go_next();

    protected:
        Course * next;
        int credits;
        float grade;
        char * name;
        
};



//
class Cs: public Course
{
    public:
        Cs();
        void display();

    protected:

};



//
class Non_cs: public Course
{
    public:
        Non_cs();
        void display();

    protected:

};



//
class Elective: public Course
{
    public:
        Elective();
        void display();

    protected:

};

