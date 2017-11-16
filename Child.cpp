#include "Person.h"
#include "Child.h"
#include <string>
#include <iostream>
using namespace std;

//calls base constructor
Child::Child(string Lname, string Fname, string gender, int generation, int age, int levelEducation) : Person(Lname, Fname, gender, generation, age){

    this->levelEducation=levelEducation;
}

Child::Child(const Child& C){  //defining copy constructor

    levelEducation=C.levelEducation;
}
Child :: ~Child(){

}
//get & set accessing functions for levelEducation
void Child::setLevelEducation(int levelEducation){
    this->levelEducation=levelEducation;

}
int Child::getLevelEducation()const{

    return levelEducation;
}
void Child::print() const{
    //want information from base class Person to also be printed here
    cout<<"Person's first name and last name is: "<< getFname() <<" "<< getLname()<< endl;
    cout<<"Person's gender is: "<< getGender()<< endl;
    cout<<"Person's age is: "<< getAge()<< "\nPerson is a part of the generation: "<< getGeneration()<<endl;
    cout<<"Child is at the level of education: "<< getLevelEducation()<<"\n"<< endl;

}


