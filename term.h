//Cody Herberholz, CS202, Program #2
//term.h



#include "course.h"



//enum color [RED, BLACK];



//
class Term
{
    public:
        Term();

        int insert_date(int new_year, int new_term);
        int compare_year(int match);
        int compare_term(int match);
        int insert_data(int cred, int cs_cred, int term_gpa, int cs_gpa);
        int give_year();
        int give_term();
        int give_credits();
        int give_cs_credits();
        float give_term_gpa();
        float give_cs_gpa();

    protected:
        int year; //holds the year of the term
        int term; //holds a number based off which term it is
        int credits;
        int cs_credits;
        float term_gpa;
        float cs_gpa;
         
};



class Node: public Term
{
    public:
        Node(); //?????DO I NEED THIS??????????????
        ~Node();
        Node(const Term &);

        Node *& go_left();
        Node *& go_right();
        int add_course();
        int remove_course();
        Course * retrieve(char * match);
        int course_prompt();
        void insert_gpa();
        void display() const;
//        void connect_left(Node * connection);
//        void connect_right(Node * connection);

    protected:
//        color flag;
        Course * head;
        Node * left;
        Node * right;
};
