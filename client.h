//Cody Herberholz, CS202, Program #2
//client.h



#include "term.h"



//This is a Red Black Tree
class Pine
{
    public:
        Pine();
        ~Pine();

        int insert(Node *& root, int new_year, int new_term);
        int retrieve();
        void display(Node * root) const;
        void remove_all(Node *& root);

    protected:
            Node * root;

};



class Client: public Pine
{
    public:
        Client();

        int prompt();
        int operation(); 
        void select_term(int & term_year, int & term);
        int receive_gpa(Node * root);
        int calc_gpa();
        int evaluate_progress();

    protected:
        float total_gpa;
        float total_cs_gpa;
        int total_cs_credits;
        int total_credits;
};
