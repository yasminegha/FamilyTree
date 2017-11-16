

#include "Person.h"
#include "iostream"
#include <string>
#include <iomanip>
using namespace std;

Person::Person() {  //base constructor
    Lname= " ";
    Fname= " ";
    gender= " ";
    generation = 0;
    age = 0;
}

Person::Person(string Lname, string Fname, string gender, int generation, int age){ //sets persons data

    this->Lname=Lname;
    this->Fname=Fname;
    this->gender=gender;
    this->generation=generation;
    this->age=age;
}
Person :: ~Person(){ //Destructor

}

Person :: Person(Person const& P1){  //defining copy constructor
    this->Lname=P1.Lname;
    this->Fname=P1.Fname;
    this->gender=P1.gender;
    this->generation=P1.generation;
    this->age=P1.age;
}

//get & set accessing functions are as follows:

void Person::setLname(string name){
    this->Lname=Lname;
}

string Person::getLname() const{
    return Lname;
}

void Person::setFname(string name){
    this->Fname=Fname;
}

string Person::getFname() const{
    return Fname;
}


void Person::setGender(string gender){
    this->gender=gender;
}

string Person::getGender() const{
    return gender;
}

void Person::setGeneration(int generation){
    this->generation=generation;
}

int Person::getGeneration()const{
    return generation;
}

void Person::setAge(int age){
    this->age=age;
}

int Person::getAge()const{
    return age;
}

//end of get/set accessing functions

void Person::print()const {

    printName();
    cout<<"Person's gender is: "<< getGender() <<endl;
    cout<<"Person's age is: "<< getAge()<<endl;
    cout<<"Person is part of the generation: "<< getGeneration() << "\n"<<endl;

}
void Person::printName() const{ //prints person's name
    cout<<"\n"<<"Person's first name and last name is: "<< Fname <<" "<< Lname <<endl;
}

bool Person::operator == (const Person &P ) const{ //overloading "==" so now we can directly compare two people

    if ( Fname == P.Fname && Lname == P.Lname){ //if first name & last name are the same ==
        return true;
    }
    else{
        return false;
    }
}

ostream& operator<<( ostream& output, const Person &p ){ //<< overloading outputs the person's first & last name

    output << p.getFname() <<" "<< p.getLname()<< endl;

    return output;
}
