//Cody Herberholz, CS202, Program #2
//client.h
//This file contains the main BST data structure and manager class derived from the 
//BST implements an algorithm to rotate nodes once either height on the left or right 
//side gets to a certain size. This helps rebalance the tree and avoids a LLL
//situation. It can insert, rotate, remove, display, and remove all.
//The manager class provides an interface with the user and allows them to 
//interact with the BST unknowingly by inserting and removing. The can also 
//display and show progress towards acceptance into the CS Program.



#include "term.h"



//This is a Binary Search Tree with an algorithm to rotate nodes move a new 
//node to root's possition. Each node in this tree contains a term with a LLL of
//courses within each term. This tree can insert, rotate, remove, and remove all.
class Pine
{
    public:
        Pine();
        ~Pine();
        int insert(Node *& root, int new_year, int new_term); //Insert node
        void rotation(); //rotate nodes
        int remove(Node *& root, int rm_year, int rm_term); //remove nodes
        void display(Node * root) const; //display all nodes
        void remove_all(Node *& root); //remove all nodes

    protected:
            Node * root; //Holds the root of the tree
            int left_height; //Holds the height of the left side
            int right_height; //Holds the height of the right side
};



//This class acts as an interface for the user and manages the whole program
//overall. It gives a prompt to the user, has a function that controls the flow
//of the program, selects a term to insert, recieves gpa and credits from each
//term, calculates the gpa from data received, and evaluates user's progress 
//towards acceptance into the CS program. 
class Client: public Pine
{
    public:
        Client();
        int prompt(); //Gives user options to perform
        int operation(); //Controls flow of program
        void select_term(int & term_year, int & term); //Select term/year 
        int receive_gpa(Node * root); //Receive gpa from each term
        int calc_gpa(); //Calculate gpa received
        int evaluate_progress(); //evaluate user progress

    protected:
        float total_gpa; //Total of overall GPA
        float total_cs_gpa; //Total of overall CS GPA
        int total_cs_credits; //Total of overall CS credits
        int total_credits; //Total of overall credits
};

