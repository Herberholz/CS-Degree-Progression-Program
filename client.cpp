//Cody Herberholz, CS202, Program #2
//client.cpp
//Need to keep track of what CS core classes have been passed somehow


#include "client.h"
using namespace std;


//
Pine::Pine(): root(0),left_height(0),right_height(0) {}



//
Pine::~Pine()
{
    remove_all(root);
}



//Will check for year first and when both years equal check month
int Pine:: insert(Node *& root, int new_year, int new_term)
{
    int check_year = 0;
    int check_term = 0;

    if(!root) 
    {
        root = new Node;
        root->insert_date(new_year, new_term);
        root->add_course();
        return 1;

    }
    
    if(!root->go_left() && root->go_right())
        ++right_height;
    if(root->go_left() && !root->go_right())
        ++left_height;

    if('5' == right_height || '5' == left_height)
        rotation();

    check_year = root->compare_year(new_year);
    check_term = root->compare_term(new_term);

    if(1 == check_year)//If year is equal
    {
        if(1 == check_term) //If term is less than 
            return insert(root->go_left(), new_year, new_term);
        else if(2 == check_term) //If term is greater than
            return insert(root->go_right(), new_year, new_term);
        else if(3 == check_term) //If term is equal
            root->add_course();
    }

    else if(2 == check_year) //If year is less than
        return insert(root->go_left(), new_year, new_term);

    else if(3 == check_year) //If year is greater than
        return insert(root->go_right(), new_year, new_term);

     
    return 0;
}



//
int Pine::rotation()
{
    Node * temp = root;
    Node * prev = NULL;

    if('5' == right_height)
    {
        for(int i = 0; i < 2; ++i)
        {
            prev = temp;
            temp = temp->go_right();
        }
        if(prev->go_left())
        {
            Node * other = prev->go_left();
            temp->go_left() = other;
            other->go_right() = prev;
            other->go_left() = root;
            prev->go_right() = NULL;
            prev->go_left() = NULL;
            root->go_right() = NULL;
        }
        else
        {
            temp->go_left() = prev;
            prev->go_right() = NULL;
            prev->go_left() = root;
            root->go_right() = NULL;
        }
        right_height = 0;
    }
    if('5' == left_height)
    {
        for(int i = 0; i < 2; ++i)
        {
            prev = temp;
            temp = temp->go_left();
        }
        if(prev->go_right())
        {
            Node * other = prev->go_right();
            temp->go_right() = other;
            other->go_left() = prev;
            other->go_right() = root;
            prev->go_right() = NULL;
            prev->go_left() = NULL;
        }
        else
        {
            temp->go_right() = prev;
            prev->go_left() = NULL;
            prev->go_right() = root;
            root->go_left() = NULL;
        }
        left_height = 0;
    }

    return 1;
}



//
int Pine::remove(Node *& root, int rm_year, int rm_term)
{
    char letter;

    if(!root) return 0;

    if(root->give_year() == rm_year && root->give_term() == rm_term)
    {
        cout << "Remove Term(Enter T) or Course(Enter C)? ";
        cin >> letter;
        cin.ignore(100,'\n');

        if('C' == toupper(letter))
            root->remove_course();
        else
        {
            if(!root->go_left() && !root->go_right())
            {
                delete root;
                root = NULL;
                return 1;
            }
            else if(!root->go_left() && root->go_right())
            {
                Node * temp = root->go_right();
                delete root;
                root = temp;
                return 1;
            }
            else if(root->go_left() && !root->go_right())
            {
                Node * temp = root->go_left();
                delete root;
                root = temp;
                return 1;
            }
            else
            {
                Node * current = root->go_right();
                if(!current->go_left())
                {
                    int year = current->give_year();
                    int term = current->give_term();
                    int credits = current->give_credits();
                    int cs_credits = current->give_cs_credits();
                    int term_gpa = current->give_term_gpa();
                    int cs_gpa = current->give_cs_gpa();

                    root->insert_date(year, term);
                    root->insert_data(credits,cs_credits,term_gpa,cs_gpa);

                    Node * temp = current->go_right();
                    delete current;
                    root = temp;
                    return 1;
                }
                else
                {
                    Node * prev = NULL;

                    while(current->go_left())
                    {
                        prev = current;
                        current = current->go_left();
                    }

                    int year = current->give_year();
                    int term = current->give_term();
                    int credits = current->give_credits();
                    int cs_credits = current->give_cs_credits();
                    int term_gpa = current->give_term_gpa();
                    int cs_gpa = current->give_cs_gpa();

                    root->insert_date(year, term);
                    root->insert_data(credits,cs_credits,term_gpa,cs_gpa);


                    if(current->go_right())
                    {
                        Node * temp = current->go_right();
                        delete current;
                        prev->go_left() = temp;
                        return 1;
                    }
                    else
                    {
                        delete current;
                        current = NULL;
                        return 1;
                    }
                }
            }
        }
    }
    return remove(root->go_left(),rm_year,rm_term) + remove(root->go_right(),rm_year,rm_term);
}



//
void Pine::display(Node * root) const
{
    if(!root) return;

    root->display();
    display(root->go_left());
//    root->display();
    display(root->go_right());
}



//
void Pine::remove_all(Node *& root)
{
    if(!root) return;
    remove_all(root->go_left());
    remove_all(root->go_right());

    delete root;
    root = NULL;
}


//
Client::Client():total_gpa(0),total_cs_gpa(0),total_cs_credits(0),total_credits(0) {}



//
int Client::prompt()
{
    int choice = 0;

    cout << "\n\n---Menu---" << endl;
    cout << "1) Add A Course" << endl;
    cout << "2) Remove A Term/Course" << endl;
    cout << "3) Evaluate CS Program Progression" << endl;
    cout << "4) Display Current Program Requirements" << endl;
    cout << "5) Quit" << endl;

    cout << "\nPlease Choose A Number: ";
    cin >> choice;
    cin.ignore(100, '\n');

    if(choice > 5 || choice <= 0)
        prompt();

    return choice;
}



//
int Client::operation()
{
    int option = 0;
    int term_year = 0;
    int term = 0; //Fall,Winter,Spring,Summer
    int rm_year = 0;
    int rm_term = 0;

    cout << "\n\nWelcome to my program! The purpose of this program is to help"
            "evaluate your progress in the CS Program." << endl;

    do
    {
        option = prompt();

        switch(option)
        {
            case 1:
                select_term(term_year, term);
                insert(root, term_year, term);
                break;
            case 2:
                select_term(rm_year, rm_term);
                remove(root, rm_year, rm_term);
                break;
            case 3:
                display(root);
                break;
            case 4:
                if(root)
                {
                    root->insert_gpa();
                    receive_gpa(root);
                    calc_gpa();
                    evaluate_progress();
                }
                else
                    cout << "Please add some classes first! " << endl;
                break;
            case 5:
                cout << "\nGoodbye! " << endl;
        }
    }
    while(option != 5);

    return 0;
}



//Chose term
void Client::select_term(int & term_year, int & term)
{
    cout << "\nWhat year was your course taken(EX: 2015)? " << endl;
    cin >> term_year;
    cin.ignore(100, '\n');

    do
    {
        cout << "\nPlease choose which term(using #): " << endl;
        cout << "1) Fall" << endl;
        cout << "2) Winter" << endl;
        cout << "3) Spring" << endl;
        cout << "4) Summer" << endl << endl;

        cin >> term;
        cin.ignore(100, '\n');
    }
    while(term > 4 || term <= 0);

}



//
int Client::receive_gpa(Node * root)
{
    if(!root) return 0;

    total_gpa += root->give_term_gpa();
    total_credits += root->give_credits();
    total_cs_credits += root->give_cs_credits();
    total_cs_gpa += root->give_cs_gpa();

    return receive_gpa(root->go_left()) + receive_gpa(root->go_right());

}



//
int Client::calc_gpa()
{
    float overall_gpa = 0;
    float overall_cs_gpa = 0;

    overall_gpa = total_gpa / total_credits;
    overall_cs_gpa = total_cs_gpa / total_cs_credits;

    cout << "\n\n---GPA---" << endl;
    cout << "Total: " << overall_gpa << endl;
    cout << "CS: " << overall_cs_gpa << endl;

    if(overall_gpa < 2.0 || overall_cs_gpa < 2.0)
        cout << "\nWarning...Must work on improving academic standing." << endl;
    else
        cout << "\nGood Academic Standing" << endl;

    return 1;
}



//
int Client::evaluate_progress()
{
    if(total_credits < 90)
        cout << "\nYou have " << total_credits << " which does not meet the reqirements"
             << " to be accepted into the CS Program" << endl;
    

    return 1;
}
