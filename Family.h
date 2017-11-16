//This class puts together all the nodes(people) and edges(relations) to make them presentable in a graph

#ifndef Family_h
#define Family_h
#include "Person.h"
#include "Adult.h"
#include "Child.h"
#include "Relation.h"
#include <array>
#include <vector>
#include <string>
#include <exception>
#include <iostream>

using namespace std;

class Family{

private:

    Person *persList; //pointer points to list of people
    int sizeR; //size family
    int sizeP; //size family person
    Relation *relaList;  //pointer points to list of relation
    static const size_t MAX_SIZE = 150; //max size of people in a single family


public:

    Family(); //default constructor

    Family (vector<Person>, vector<Relation>); //family made up of person vect & relation vect

    Family(const Family&); //copy constructor

    ~Family();


    void AddPerson(Person&); //adds person to persList vector
    void AddRelation(Relation&); //adds person to relaList vector

    int getSizeP(); //gets number of people
    int getSizeR(); //gets number of relations

    void FamilyTree(); //to output every single relation


    //  ** The following 5 functions represent different tasks that can be accomplished with the program **

    void FamilyTree1(Person&); //takes in 1 person & searches for all the direct relations of that person


    void FamilyTree2(Person&); //takes in 1 person & searches for all of its ancestors, keeps going up until no more,
                               //keeps doing down in the generations the smaller the int generation, the older)

    void FamilyTree3(Person&, Person&); //takes in 2 people & searches for their direct relationship if any,
                                        //this is where the exception handeling is used

    void FamilyTree4(Relation&); //takes in a relation and outputs all the combinations that share that relation so ex:
                                 //child of , then all the children of relations will be displayed

    void searchFamilyByName(string, string); //user can directly check whether someone is a member of the family or not
                                             //by inputting their first & last name

};

#endif


