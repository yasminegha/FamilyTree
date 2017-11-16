//Driver.cpp is the file that will run everything

#include <iostream>
#include "Person.h"
#include "Adult.h"
#include "Child.h"
#include "Relation.h"
#include <vector>
#include "Family.h"
#include <string>
#include <iomanip>
#include <exception>

using namespace std;

int main() {

    cout<<"               ***      WELCOME TO THE FAMILY TREE PROGRAM     **** \n \n \n";

    /*//Testing the copy constructor   if this is uncommented it will show that the copy constructor works
    Person test1("Smith", "Jane", "F", 1, 80);
    Person test2 = test1;
    test2.print();
    */

    //Defining all the family members
    Adult P1("Smith", "Jane", "F", 1, 80, "Retired");
    Adult P2("Smith", "John", "M", 1, 88, "Retired");
    Adult P3("Smith", "Samantha", "F", 2,  33, "Nurse");
    Adult P4("Adams", "Anthony", "M", 2,36, "Data Engineer");
    Child P5("Adams", "Jessica", "M", 3, 8, 3);

    Adult P6("Smith", "Tina", "F", 2, 32, "Travel Agent");
    Adult P7("Smith", "Jacob", "M", 2, 40, "Pilot");
    Child P8("Smith", "Valery", "F", 3, 6, 1);
    Child P9("Smith", "Matthew","M", 3, 12, 6);
    Child P10("Smith", "Marc", "M", 3, 14, 8);

    Adult P11("Smith", "Vanessa", "F", 2, 38, "Unemployed");
    Adult P12("Smith", "Andrew", "M", 2, 42, "Surgeon");

    /*  0:married to
        1:sister/brother of
        2:child of   */

    //Generation 1:
    Relation R1(P1, P2, 0); //John is Married to Jane
    //Generation 2:
    Relation R2(P3, P1, 2); //They have 3 children: Samantha, Jacob & Andrew
    Relation R3(P3, P2, 2);
    Relation R4(P7, P1, 2);
    Relation R5(P7, P2, 2);
    Relation R6(P12, P1, 2);
    Relation R7(P12, P2, 2);
    //The children of John & Jane are also all siblings
    Relation R8(P3, P7, 1);
    Relation R9(P3, P12, 1);
    Relation R10(P7, P12, 1);
    //These siblings: Samantha, Jacob & Andrew are all married
    Relation R11(P3, P4, 0);
    Relation R12(P7, P6, 0);
    Relation R13(P12, P11, 0);
    //Two of these couples have children

    //Generation 3:
    Relation R14(P5, P3, 2); //Samantha & Anthony's child
    Relation R15(P5, P4, 2);
    Relation R16(P8, P6, 2); //Tina & Jacob's 3 children
    Relation R17(P8, P7, 2);
    Relation R18(P9, P6, 2);
    Relation R19(P9, P7, 2);
    Relation R20(P10, P6, 2);
    Relation R21(P10, P7, 2);
    //Tina & Jacob's 3 children are all siblings
    Relation R22(P8, P9, 1);
    Relation R23(P8, P10, 1);
    Relation R24(P9, P10, 1);



    vector <Person> vectorPeople = {P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12};

    vector <Relation> vectorRelations = {R1, R2, R3, R4, R5, R6, R19, R7, R8, R9, R10, R11, R12, R13, R14, R15, R16,R17, R18, R19, R20, R21, R22, R23, R24 };

    Family myfamily(vectorPeople, vectorRelations); //creating a family tree "myfamily"

    //                  *****START TESTING THE FUNCTIONS OF THIS FAMILY TREE****

        //NOTE: Please note that some functions have a few cases & although there is an example for each case,
        //NOTE: some cases have simply been commentented out to not make the output too text heavy for the user,
        //NOTE: the user can however easily uncommented these cases and they will run right away

    cout<<"*  Function FamilyTree1 is now running: it will display all the direct relations of a family member  *\n"<< endl;

    myfamily.FamilyTree1(P6); //CASE 1: person is in family & shows all their direct relations

    /*//
    Person P15;
    myfamily.FamilyTree1(P15); //CASE 2: person is not in the family  *exception case
    *///

    cout << "___________"<< endl;
    cout<<"\n*  Function FamilyTree2 is now running: it will display all the direct relations of a person & go back to their ancestors  *\n"<< endl;

    //FamilyTree2 tests to shows all direct relations of a person in the family & their ancestors

    myfamily.FamilyTree2(P8); //CASE 1: Person is a member of the family
    cout << "Exception Trial : "<< endl;
    Person P15;
    myfamily.FamilyTree2(P15);  //CASE 2: Person is not a member of the family

    cout << "___________"<< endl;
    cout<<"\n*  Function FamilyTree3 is now running: it will display the direct relation between two people, if any  *\n"<< endl;
    //FamilyTree3 tests and shows the direct relation of two people

    myfamily.FamilyTree3(P9, P8); //CASE 1: Two people are directly-related & exist in the family

    cout << "Exception Trial : "<< endl;

    myfamily.FamilyTree3(P1, P11); //CASE 2: Two people are not directly-related & exist in the family

    /*//
    Person P15;
    myfamily.FamilyTree3(P15, P1); //CASE 3: One is a member of the family (P1) and the other is not (P15), also the same thing would occur if the both people were not members of the family
    /*///

    //myfamily.FamilyTree3(P1,P1); //CASE 4: If both people are the same *Exception will occur


    cout << "___________"<< endl;
    cout<<"\n*  Function FamilyTree4 is now running: it will display whether a relation exists or not in the family  *\n"<< endl;
    //FamilyTree4 checks if a relation exists within the family and outputs this relation

    myfamily.FamilyTree4(R15); //CASE 1: The relation exists

    Relation R30;
    cout << "Exception Trial : "<< endl;
    myfamily.FamilyTree4(R30); //CASE 2: The relation does not exist


    cout << "___________"<< endl;

    cout<<"\n*  This section will add a new person to the family tree & compare the size of the family before & after  *\n"<< endl;

    //myfamily.getSizeP();
    //Testing to see what will happen when you add a member in the family
    cout<<"Before : ";
    cout<<myfamily.getSizeP(); //Checking the family's size (# of people) before any modifications


    //the following segment adds a child to Samantha & Anthony
    Child P13("Adams", "Manny", "M", 3, 1, 0);
    myfamily.AddPerson(P13);
    Relation R25(P13, P3, 2);
    myfamily.AddRelation(R25);
    Relation R26(P13, P4, 2);
    myfamily.AddRelation(R26);
    Relation R27(P13, P5, 1);
    myfamily.AddRelation(R27);
    cout<<"\n\nAfter  : ";
    cout<<myfamily.getSizeP()<< "\n"<<endl; //Checking the family's size (# of people) after adding a person
    cout<<"New family member's information: \n"<<endl;
    P13.print();

    cout << "\n___________\n"<< endl;


    cout<<"*   Testing FamilyTree1 with the new member   *\n"<<endl;
    //testing out all the FamilyTree functions with this new member
    myfamily.FamilyTree1(P13);
    //FamilyTree2,FamilyTree3,FamilyTree4 could also be tested for this member
    /*//
    cout<<"\n*   Testing FamilyTree2 with the new member   *\n"<<endl;
    myfamily.FamilyTree2(P13);
    cout<<"\n*   Testing FamilyTree3 with the new member   *\n"<<endl;
    myfamily.FamilyTree3(P13,P1); //no direct relation
    cout<<"\n*   Testing FamilyTree4 with the new member   *\n"<<endl;
    myfamily.FamilyTree4(R26);
    *///
    cout << "___________\n"<< endl;

    cout<<"*   Testing what will happen a new person is added to the family but is not related to anyone   *\n"<<endl;
    //Testing to see what happens when a person is added to the family but has no relation to anyone
    cout<<"Before : ";
    cout<<myfamily.getSizeP();

    Child P14("Adams", "Johnny", "M", 3, 1, 0);
    myfamily.AddPerson(P14);

    cout<<"\n\nAfter  : ";
    cout<<myfamily.getSizeP()<< "\n"<<endl; //size should be incremented by 1 regardless if they have any relations

    cout<<"Testing familyTree1, 2 & 3 respectively"<<endl;
    cout << "familyTree1: " <<endl;
    myfamily.FamilyTree1(P14);
    cout << "familyTree2: " <<endl;
    myfamily.FamilyTree2(P14);
    cout << "familyTree3: " <<endl;
    myfamily.FamilyTree3(P14, P1); //works good




    cout << "\n___________\n"<< endl;
    cout<<"\n*  Function searchFamilyByName is now running: it will ask the user to input a person's first & last name to check if they are in the family  *\n"<< endl;
    //Function searchFamilyByName is a user defined function that asks users to input a person's first & last name then searches to see whether this person is a member of the family or not, there is also a version that is pre-defined that could be commented out instead of having to manually input it
    //*
    string Fname, Lname;
    cout<<"Enter the first name of the person you wish to search in this family by capitalizing the first letter \n";
    cin>>Fname;
    cout<<"Enter the last name of the person you wish to search in this family by capitalizing the first letter \n";
    cin>>Lname;
    myfamily.searchFamilyByName(Fname, Lname);

    //*//NOTE: this part ^^ can be commented out & searchByFamilyName can be tested without the user's input
    //by removing the "\\" & directly putting the first & last name in the apropriate fields below

    //myfamily.searchFamilyByName("Jane","Smith"); //CASE 1: this is the predefined function for a person that exists
    //myfamily.searchFamilyByName("Kat","James"); //CASE 2: this is the predefined function for a person that does not exist


    return 0;
}

