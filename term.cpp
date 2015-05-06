//Cody Herberholz, CS202, Program #2
//term.cpp



#include "term.h"
using namespace std;



//
Term::Term():year(0),term(0),credits(0),cs_credits(0),term_gpa(0),cs_gpa(0) {}



//
int Term::insert_date(int new_year, int new_term)
{
    year = new_year;
    term = new_term;
    return 1;
}



//
int Term::compare_year(int match)
{
    int option = 0;

    if(year == match)
        option = 1;

    else if(year < match)
        option = 2;

    else if(year > match)
        option = 3;

    return option;
}



//
int Term::compare_term(int match)
{
    int choice = 0;

    if(term < match)
        choice = 1;
    else if(term > match) 
        choice = 2;
    else if(term == match)
        choice = 3;

    return choice;
}



//
int Term::give_credits()
{
    return credits;
}



//
int Term::give_cs_credits()
{
    return cs_credits;
}



//
float Term::give_term_gpa()
{
    return term_gpa;
}



//
float Term::give_cs_gpa()
{
    return cs_gpa;
}



//
Node::Node():/*flag(0),*/head(0),left(0),right(0) {}



//
Node::~Node()
{
    Course * current = NULL;

    while(head)
    {
        current = head->go_next();
        delete head;
        head = current;
    }
    
}



//
Node::Node(const Term &)
{

}



//
Node *& Node::go_left()
{

    return left;
}



//
Node *& Node::go_right()
{

    return right;
}



//
int Node::add_course()
{
    int selection = 0;
    Course * current = NULL;

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



//
int Node::course_prompt()
{
    int number = 0;

    cout << "\n\n---COURSE SELECTION---" << endl;
    cout << "1)Computer Science " << endl;
    cout << "2)Required (excluding CS)" << endl;
    cout << "3)Electives " << endl;
    
    cout << "Please select a number: ";
    cin >> number;
    cin.ignore(100, '\n');

    return number;
}



//
void Node::insert_gpa()
{
    Course * current = head;
    Cs * test = NULL;
    int temp_cred = 0;
    int temp_gpa = 0;

    while(current)
    {
        temp_cred = current->give_credits();
        temp_gpa = current->give_gpa();

        credits += temp_cred;
        term_gpa += temp_cred * temp_gpa; //multiplies the grade point by credits
        
        test = dynamic_cast<Cs*>(current);//Looks to see if current is a Cs class

        if(test)
        {
            //need to check for if gpa is less than 2.0 to signal needing to retake
            cs_gpa += temp_cred * temp_gpa;
            cs_credits += temp_cred;
        }

        current = current->go_next();
    }
}



//
void Node::display() const
{
    Course * current = head;

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
