
//class adult thats inherited by

#ifndef Adult_h
#define Adult_h
#include "Person.h"
#include <iostream>
using namespace std;

class Adult: public Person { //class Adult inherits class Person

protected: //data member

    string occupation;

public:

    Adult(); //base constructor
    Adult(string Lname, string Fname, string gender, int generation, int age, string occupation);
    Adult(const Adult&); //copy constructor of Adult
    ~Adult();

    //the get & set accessing functions

    void setOccupation(string occupation);
    string getOccupation() const;

    //end of accessing functions

    void print() const; //print function for this class of type virtual

};


#endif

