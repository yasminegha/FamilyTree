

//This class represents the edges that connect the nodes (Person)

#include <iostream>
#include <iomanip>
#include "Person.h"
#include "Relation.h"

using namespace std;

Relation :: Relation(){
    type = -1;
    P1 = Person();
    P2 = Person();
}

Relation :: Relation(const Relation& Relation){
    P1 = Relation.P1;
    P2 = Relation.P2;
    type = Relation.type;
}

Relation :: Relation( Person& P1, Person& P2, int type){
    this->P1=P1;
    this->P2=P2;
    this->type=type;
}

//accessing functions
Person Relation :: getPerson1() const {
    return 	P1;
}
Person Relation ::getPerson2() const{
    return P2;
}
int Relation :: getType() const{
    return type;
}
//end of accessing functions

Relation::~Relation(){ //destructor

}

void Relation :: printRelation(){  //prints relation of P1 to P2
    // checks the type before outputting the description of the relation
    cout << P1 << "   ";
    if(type==0 || type==1 || type==2){

        if (type == 0){
            cout << "is married to ";
        }
        if (type == 1){
            if(P1.getGender()=="F"){
            cout <<"is the sister of ";
            }
            if(P1.getGender()=="M"){
            cout<<"is the brother of ";
            }
        }
        if (type == 2){
            cout<<"is a child of ";
        }
        cout <<P2<< endl;
    }
    else
        cout<<"is not directly related to " << P2;
}

void Relation :: printRelation1(){ //prints relation of P2 to P1
    // similarly checks the type before outputting the description of the relation, however in the reverse order, used in order to show the various paths the output may have
    cout <<P2 << "   ";
    if(type==0 || type==1 || type==2){

        if (type == 0){
            cout << "is married to ";
        }
        if (type == 1){
            if(P2.getGender()=="F"){
            cout <<" is the sister of ";
            }
            if(P2.getGender()=="M"){
            cout<< " is the brother of ";
            }
        }
        if (type == 2){
            if(P2.getGender()=="F"){
            cout <<"is the mother of ";
            }
            if(P2.getGender()=="M"){
            cout<<"is the father of ";
            }
        }
        cout << P1 << endl;
    }
    else
        cout<<"is not directly related to "<< P1;
}

bool Relation :: PersonP12 (Person &P){ //checks if the person  P1 is the same as input person P
    // Function checks if P1  or P2 in the relation is equal to the input P;

    if (P1 == P ||P2 == P){
        return true;
    }
    else
        return false;
}

bool Relation :: PersonP12(Relation &R){
    // Similar to the function above, if the P1 or P2 exists in either functions
    // The data is not accessed in the Family function when the == operator is invoked
    if ((P1 == R.P2 || P2 == R.P1)||(P1 == R.P1 || P2 == R.P2)){
        return true;
    }
    else
        return false;
}


bool Relation :: PersonP1 (Person &P){ //checks if the person  P1 is the same as input person P
                                       //check if P1 = P inputted
    if (P1 == P){
        return true;
    }
    else
        return false;
}


bool Relation :: PersonP2 (Person &P){ //checks if the person P2 is the same as input person P
    //check if P2 = P inputted

    if (P2 == P){
        return true;
    }
    else
        return false;
}

bool Relation:: PersonP1(Relation &R){ //comparing a person to a person of the relation R
    //relation p1 = input relation p1
    if (P1 == R.P1){
        return true;
    }
    else
        return false;
}
bool Relation:: PersonP2(Relation &R){
    //relation p2 = input relation p2
    if (P2 == R.P2){
        return true;
    }
    else
        return false;
}


