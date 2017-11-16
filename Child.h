//class inherits Person class

#ifndef Child_h
#define Child_h
#include "Person.h"
#include <iostream>
using namespace std;


class Child: public Person{ //child inherits class Person

protected:  //data members

    int levelEducation=0; //this represents the grade at which the child is at in their education

public:

    Child(); //default constructor
    Child(string Lname, string Fname, string gender, int generation, int age, int levelEducation);
    Child(const Child&); //copy constructor of class Child
    ~Child();
    //accessing get & set functions
    void setLevelEducation(int levelEducation);
    int getLevelEducation()const;

    void print() const; //function that prints out Child's information, of type virtual

};

#endif
