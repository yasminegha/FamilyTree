//This class represents the edges that connect the nodes (Person)


#ifndef Relation_h
#define Relation_h
#include "Person.h"
#include "Adult.h"
#include "Child.h"
#include <iomanip>
#include <iostream>
using namespace std;

class Relation{

    Person P1;
    Person P2;

    int type;

public:

    Relation(); //constructor
    Relation(const Relation&); //copy constructor
    Relation(Person&, Person&, int);
    ~Relation(); //destructor
    Person getPerson1() const;
    Person getPerson2() const;
    int getType() const;


    void printRelation();
    void printRelation1();

    bool PersonP12(Person &); //comparing if the imput person is P1 or P2
    bool PersonP12(Relation&); //Comparing the relation between two people

    //function overloading

    bool PersonP1(Person &);
    bool PersonP2(Person &);

    bool PersonP1(Relation &);
    bool PersonP2(Relation &);
    // friend ostream& operator<<( ostream&, const Relation & );

    //Relation


};

#endif
