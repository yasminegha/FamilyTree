//This class represents each member (person) of the family
//This is the base class and is inherited by 2 other classes, Adult & Child

#ifndef Person_h
#define Person_h
#include <iostream>
#include <string>
using namespace std;

class Person{

protected:

    string Lname; //Last Name
    string Fname; //First Name
    string gender;
    int generation;
    int age;

public:


    Person();  //constructor
    Person(const Person&); //copy constructor
    Person(string Lname, string Fname,string gender, int generation, int age);
    virtual ~Person(); //destructor
    bool operator==(const Person& ) const; //operator overloading


    //get & set accessing functions
    void setLname(string Lname);
    string getLname()const;
    void setFname(string Fname);
    string getFname()const;
    void setGender(string gender);
    string getGender()const;
    void setGeneration(int generation);
    int getGeneration()const;
    void setAge(int age);
    int getAge()const;
    //end of accessing functions

    virtual void print() const; //printing function is virtual
    void printName() const;  //prints person's name
    friend ostream& operator<<( ostream&, const Person & ); //overloading "<<" (so from now on we can just write cout<<P1)


};


#endif

