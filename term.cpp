//Cody Herberholz, CS202, Program #2
//term.cpp
//This file implements the Term and Node class. The Term class is an imformation
//manager for the term with functions that receive, give, and compare information.
//The Node class holds functions that deal with the BST as a node and also functions
//that deal with the LLL.
//


#include "term.h"
using namespace std;



//Constructor for Term that initializes its data members
Term::Term():year(0),term(0),credits(0),cs_credits(0),term_gpa(0),cs_gpa(0) {}



//Task:   Inserts year and term into their variables
//Input:  New year and term sent in from user
//Output: Returns one when successful
int Term::insert_date(int new_year, int new_term)
{
    year = new_year;
    term = new_term;

    return 1;
}



//Task:   Compares the term year with incoming year
//Input:  Year coming from user 
//Output: Returns option based on how the two years compare
int Term::compare_year(int match)
{
    int option = 0; //holds number based off of ==, < , >

    if(year == match)
        option = 1;

    else if(year > match)
        option = 2;

    else if(year < match)
        option = 3;

    return option;
}



//Task:   Compares the term with incoming term from user
//Input:  Term coming from user
//Output: Returns option based on how the two years compare
int Term::compare_term(int match)
{
    int choice = 0; //holds number based off of ==, < , >

    if(term < match)
        choice = 1;

    else if(term > match) 
        choice = 2;

    else if(term == match)
        choice = 3;

    return choice;
}



//Task:   Takes data from user and inserts it into protected variables
//Input:  Info from the user that needs to be inserted
//Output: Returns one upon success
int Term::insert_data(int cred, int cs_cred, int new_term_gpa, int new_cs_gpa)
{
    credits = cred;
    cs_credits = cs_cred;
    term_gpa = new_term_gpa;
    cs_gpa = new_cs_gpa;

    return 1;
}



//Task:   Gives the year
//Input:  None
//Output: Year
int Term::give_year()
{
    return year;
}



//Task:   Gives the term number
//Input:  None
//Output: Term
int Term::give_term()
{
    return term;
}



//Task:   Gives credits
//Input:  None
//Output: Credits
int Term::give_credits()
{
    return credits;
}



//Task:   Gives cs credits
//Input:  None
//Output: CS Credits
int Term::give_cs_credits()
{
    return cs_credits;
}



//Task:   Gives term gpa
//Input:  None
//Output: Term gpa
float Term::give_term_gpa()
{
    return term_gpa;
}



//Task:   Gives CS gpa
//Input:  None
//Output: CS gpa
float Term::give_cs_gpa()
{
    return cs_gpa;
}



//Constructor for the Node class which initializes all data members
Node::Node():head(0),left(0),right(0) {}



//Destructor which deallocates all courses in the LLL
Node::~Node()
{
    Course * current = NULL; //Used to travers the LLL

    while(head)
    {
        current = head->go_next();
        delete head;
        head = current;
    }
    
}



//Task:   Used to access private left pointer
//Input:  None
//Output: Returns address of left pointer
Node *& Node::go_left()
{

    return left;
}



//Task:   Used to access private left pointer
//Input:  None 
//Output: Returns address of right pointer
Node *& Node::go_right()
{

    return right;
}



//Task:   Adds course at head of LLL. Uses course prompt to determine which
//        type of class to add (cs, non_cs, elective)
//Input:  None
//Output: Return one upon completion of function
int Node::add_course()
{
    int selection = 0; //holds choice of what course to create
    Course * current = NULL; //Holds on to new node to insert at beginning

    if(!head)
    {
        selection = course_prompt();
        if(1 == selection)
            head = new Cs;
        else if(2 == selection)
            head = new Non_cs;
        else if(3 == selection)
            head = new Elective;
    }
    else
    {
        selection = course_prompt();
        if(1 == selection)
        {
            current = new Cs;
            current->go_next() = head;
            head = current;
        }
        else if(2 == selection)
        {
            current = new Non_cs;
            current->go_next() = head;
            head = current;
        }
        else if(3 == selection)
        {
            current = new Elective;
            current->go_next() = head;
            head = current;
        }

    }

    head->insert_data();

    return 1;
}



//Task:   Remove course from LLL, has a case for if head is to be removed or just
//        some other case. 
//Input:  None
//Output: Returns one upon success and zero for failure
int Node::remove_course()
{
    Course * current = head; //used to display options and traverse list later
    Course * remove = NULL; //holds node to be removed
    char temp_name[30] = {'\0'}; //holds course name to search for

    while(current)
    {
        current->display();
        current = current->go_next();
    }

    cout << "\nPlease enter in the name of the course you wish to delete: " << endl;
    cin.get(temp_name, 30, '\n');
    cin.ignore(100, '\n');

    char * name = new char[strlen(temp_name)+1];
    strcpy(name,temp_name);

    remove = retrieve(name);

    delete [] name;
    name = NULL;

    if(remove == head)
    {
        head = remove->go_next();
        delete remove;
        remove = NULL;
    }
    else
    {
        current = head;

        while(current->go_next() != remove)
            current = current->go_next();

        current->go_next() = remove->go_next();
        delete remove;
        remove = NULL;
    }

    if(!remove)
        return 1;

    return 0;
}



//Task:   Finds specific Course by traversing and comparing names
//Input:  Course name to be searched for
//Output: A pointer to the matched course
Course * Node::retrieve(char * match)
{
    Course * temp = head; //Used to travere LLL
    int found = 0; //shows if match was found or not

    while(temp && !found)
    {
        found = temp->compare_name(match);
        if(!found)
            temp = temp->go_next();
    }

    return temp;
}



//Task:   Prompts user to choose which class to create
//Input:  None
//Output: Returns number based off the choice of the user
int Node::course_prompt()
{
    int number = 0; //holds choice of user

    cout << "\n\n---COURSE SELECTION---" << endl;
    cout << "1)Computer Science " << endl;
    cout << "2)Required (excluding CS)" << endl;
    cout << "3)Electives " << endl;
    
    cout << "Please select a number: ";
    cin >> number;
    cin.ignore(100, '\n');

    return number;
}



//Task:   Grabs gpa from courses and uses dynamic cast to check for cs courses
//        to keep track of its info separately
//Input:  None
//Output: None
void Node::insert_gpa()
{
    Course * current = head; //Used to traverse LLL
    Cs * test = NULL; //Used to check if a pointer is a Cs class

    while(current)
    {
        if(current->give_gpa())
        {
            term_gpa += current->give_gpa();
            credits += current->give_credits();

            test = dynamic_cast<Cs*>(current);//Looks to see if current is a Cs class

            if(test)
            {
                //need to check for if gpa is less than 2.0 to signal needing to retake
                cs_gpa += current->give_gpa();
                cs_credits += current->give_credits();
            }
        }

        current = current->go_next();
    }
}



//Task:   Displays the term and shows which term, then calls upon course display
//Input:  None
//Output: Display of courses in a term
void Node::display() const
{
    Course * current = head; //used to traverse LLL

    if(1 == term)
        cout << "\n\n---FALL " << year << "---" << endl;
    else if(2 == term)
        cout << "\n\n---WINTER " << year << "---" << endl;
    else if(3 == term)
        cout << "\n\n---SPRING " << year << "---" << endl;
    else if(4 == term)
        cout << "\n\n---SUMMER " << year << "---" << endl;

    while(current)
    {
        current->display();
        current = current->go_next();
    }
}
