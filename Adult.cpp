#include "Person.h"
#include "Adult.h"
#include <iostream>
using namespace std;

//calls base constructor
Adult::Adult(string Lname, string Fname, string gender, int generation, int age, string occupation) : Person(Lname, Fname, gender, generation, age){

    this->occupation=occupation;
}

Adult::Adult(const Adult& A){ //defining copy constructor

    occupation=A.occupation;
}

Adult :: ~Adult(){

}
//get & set accessing functions

void Adult::setOccupation(string occupation){
    this->occupation=occupation;
}

string Adult::getOccupation() const{
    return occupation;
}

void Adult::print() const{
    //want to make it also print out info from base class Person

    cout<<"Person's first name and last name is: "<< getFname() <<" "<< getLname()<< endl;
    cout<<"Person's gender is: "<< getGender() <<"\n"<< endl;
    cout<<"Person's age is: "<< getAge()<< "\nPerson is a part of the generation: "<< getGeneration() <<endl;
    cout<<"Adult's occupation is: " << getOccupation() <<endl;
}
