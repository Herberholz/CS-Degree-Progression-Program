//Cody Herberholz, CS202, Program #2
//term.h
//This file contains the classes Term and Node with Node derived from Term. Term 
//holds all the info necessary to keep track of term credentials. Node contains
//the functions neccessary of a BST Node but also contains the functions 
//neccessary of a LLL since it has access via head.



#include "course.h"



//This class holds all the credentials of what a term needs in terms of all 
//the classes taken during the term
class Term
{
    public:
        Term();
        int insert_date(int new_year, int new_term); //insert the year and term
        int compare_year(int match); //compare year with incoming year
        int compare_term(int match); //compare term with incoming term
        int insert_data(int cred, int cs_cred, int term_gpa, int cs_gpa);//insert info
        int give_year();
        int give_term();
        int give_credits();
        int give_cs_credits();
        float give_term_gpa();
        float give_cs_gpa();

    protected:
        int year; //holds the year of the term
        int term; //holds a number based off which term it is
        int credits; //holds credits of the term
        int cs_credits; //holds cs credits of the term
        float term_gpa; //holds term gpa
        float cs_gpa; //holds cs gpa of the term
         
};



//This class is a node of a BST and houses the functions needed to manage a 
//LLL. It can add, remove, retrieve, and display. Its additional functions 
//include a course prompt and insert gpa. 
class Node: public Term
{
    public:
        Node(); 
        ~Node();
        Node *& go_left(); //returns location of left pointer
        Node *& go_right(); //returns the location of right pointer
        int add_course(); //adds course to LLL
        int remove_course(); //remove course from LLL
        Course * retrieve(char * match); //retrieves course based off name 
        int course_prompt(); //Asks for course info
        void insert_gpa(); // insert gpa
        void display() const; //display LLL

    protected:
        Course * head; //pointer to a course
        Node * left; //pointer to a node
        Node * right; //pointer to a node
};
