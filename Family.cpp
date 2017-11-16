#include "Person.h"
#include "Family.h"
#include <iostream>
#include <string>
#include <array>
#include <exception>
using namespace std;

Family :: Family(){ //base constructor
    persList = new Person[MAX_SIZE];
    relaList = new Relation[MAX_SIZE];
    sizeR = 0;
    sizeP = 0;

}

Family :: Family(const Family& f){ //copy constructor
    sizeR = f.sizeR;
    sizeP = f.sizeP;
    relaList = new Relation[MAX_SIZE];
    persList = new Person[MAX_SIZE];
    for (int i = 0; i < sizeR; ++i){
        persList[i] = f.persList[i];
    }
    for(int i = 0; i < sizeR; ++i){
        relaList[i] = f.relaList[i];
    }

}

Family :: ~Family(){
	delete[] relaList;
	delete[] persList;
}

Family::Family (vector<Person> personVector, vector<Relation> relationVector){



    // STORING ALL MEMEBERS OF FAMILY
    persList = new Person[MAX_SIZE];
    relaList = new Relation[MAX_SIZE];
;

    for (size_t i = 0 ; i < personVector.size(); ++i){ //adds the people in personVector

        persList[i] = personVector[i];

        sizeP = i;
    }
    for (size_t j = 0; j < relationVector.size(); ++j){ //adds the relations in relationVector
        relaList[j] = relationVector[j];
        sizeR = j;
    }
    ++sizeR;
    ++sizeP;


}

void Family::AddPerson(Person &P){ //adds a person to the person vector

    persList[sizeP] = P;
    ++sizeP;
}

void Family::AddRelation(Relation &R){ //adds a relationship to the relation vector
    relaList[sizeR] = R;
    ++sizeR;
}

int Family::getSizeP(){ //size person
    cout<<"Family's size is: ";
    return sizeP;
}
int Family::getSizeR(){  //size relation
    return sizeR;
}


void Family :: FamilyTree(){
    // outputs entire family
    for (int i = 0; i < sizeR; ++i){
        relaList[i].printRelation();
    }
}



void Family :: FamilyTree1(Person &P){

    // outputs all direct relations with the input Person
    bool exists = false;
    try{
        for (int i = 0; i < sizeR; ++i){
            if((relaList[i].PersonP1(P) || relaList[i].PersonP2(P)) && (relaList[i].getType()==0 || relaList[i].getType() == 1)){
                exists = true;
                relaList[i].printRelation();
            }
            else if((relaList[i].PersonP1(P) && relaList[i].getType() == 2)){
                exists = true;
                relaList[i].printRelation();
            }
            else if((relaList[i].PersonP2(P) && relaList[i].getType() == 2)){
                exists = true;
                relaList[i].printRelation1();
            }

        }
        if (exists == false){
			for (int s =  0; s < sizeP; ++s){
				if (persList[s] == P){
					exists = true;
					cout << P << "has no direct relation with any member of the family" << endl;
					break;
				}
			}
        }
        if(exists == false){
           throw " ";
        }
    }
    catch(...){

        cout <<  P << " does not exits in this family" << endl;

        }
    }

void Family :: FamilyTree2(Person &P){
    Relation *Rptr = new Relation[MAX_SIZE]; //Pointer Rptr is a dummy array

    // output all the direct realtion of the input person in addition to all the direct relation to the input person parents and up until the family reaches the last ancester in record

    bool dummy = false;
    try{

        for (int r =  0; r < sizeR; ++r){
            if (relaList[r].PersonP12(P) == true){
                dummy = true;
                break;
            }
        }
        if (dummy != true){
			for (int s =  0; s < sizeP; ++s){
				if (persList[s] == P){
					dummy = true;
					cout << P << "has no direct relation with any member of the family" << endl;
					break;
				}
			}
        }
        if ( dummy == false){

            throw " ";
        }

        int count = 0;
        for (int i = 0; i < sizeR; ++i){
            if (relaList[i].PersonP1(P) == true || relaList[i].PersonP2(P) == true){
                Rptr[count++] = relaList[i];
            }
        }
        for (int j = 0; j < sizeR; ++j){
            if (relaList[j].PersonP1(P) == true && relaList[j].getType() == 2){

                for (int l = 0; l < sizeR; ++l){
                    if (relaList[j].PersonP12(relaList[l]) == true){
                        Rptr[count++] = relaList[l];
                        if (relaList[l].getType() == 2 ){
                            for (int k = 0; k < sizeR; ++k){
                                if (relaList[l].PersonP12(relaList[k]) == true){
                                    Rptr[count++] = relaList[k];
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        int counter = -1;
        for (int m = 0; m < count; ++m){
            for (int n = m+1; n < count; ++n){
                if (Rptr[m].PersonP1(Rptr[n]) == true && Rptr[m].PersonP2(Rptr[n])){
                    counter = n;
                    --n;

                }

                if (counter != -1 ){
                    for (int o = counter; o <= count; ++o){
                        Rptr[o] = Rptr[o+1];
                        counter = -1;
                    }
                    count = count - 1;
                }
            }

        }
        for (int p = 0; p < count; ++p){
            if (Rptr[p].PersonP12(P) == true ){
                Rptr[p].printRelation();
            }
        }
        for (int q = 0; q < count; ++q){
            if (Rptr[q].PersonP12(P) == false ){
                Rptr[q].printRelation();
            }
        }

    }
    catch (...){

        cout <<  P << "This person does not exits in this family" << endl;

    }
    delete[] Rptr;

}

void Family::FamilyTree3(Person& P1, Person& P2){
    // searches for relation in the family
    bool dummy = false;
    try{
        for (int j =  0; j < sizeP; ++j){
            if (persList[j] == P1 && persList[j] == P2) {
                dummy = true;
                if(P1==P2){
                    dummy=false;  //will go to exception if both people are the same
                    break;
                }
                break;
            }
            else {
                for (int k = 0; k < sizeR; ++k){
                    if (relaList[k].PersonP12(P1) == true && relaList[k].PersonP12(P2) == true){
                        dummy = true;
                        break;
                    }
                }
            }
        }
        if (dummy == false){
            throw " ";
        }

            for (int i = 0; i < sizeR; ++i){
                if(relaList[i].PersonP12(P1)== true && relaList[i].PersonP12(P2)==true){
                    relaList[i].printRelation();
                    relaList[i].printRelation1();
                    break;
                }
                if(relaList[i].PersonP12(P1)== false && relaList[i].PersonP12(P2)==false){
                    if(i==sizeR-1){
                        cout<< P1 << " is not directly related to " << P2 << endl;
                        break;
                    }
                }
                if (P1==P2 || P2==P1){
                    throw " ";
                    break;
                }
            }
    }

    catch(...){
        if (P1 == P2  ){
            cout << "Exception: " << P1 << " is the same as " <<P2 << endl;
        }
        else
            cout <<  "There is no direct relation between these two people " << endl;
    }


}

void Family::FamilyTree4(Relation& R) //Query the family tree based on a given relation
{
    //cout<<"Current number of relations: "<<sizeR<<endl;
    if(R.getType()==2)//P1 child of P2 type of relation
    {
        for (int i = 0; i < sizeR; ++i)
        {
            if(relaList[i].getPerson1()==R.getPerson1() && relaList[i].getPerson2()==R.getPerson2())
            {
                cout<<"Relation exists: "<<endl;
                R.printRelation();
                return;
            }
            else if(relaList[i].getPerson2()==R.getPerson1() && relaList[i].getPerson1()==R.getPerson2())
            {
                cout<<"Relation exists: "<<endl;
                R.printRelation1();
                return;
            }

        }

        cout<<"This relation does not exist!"<<endl;
    }
    else //P1 and P2 are married or siblings
    {
        for (int i = 0; i < sizeR; ++i)
        {
            if((relaList[i].getPerson1()==R.getPerson1() && relaList[i].getPerson2()==R.getPerson2())||(relaList[i].getPerson2()==R.getPerson1() && relaList[i].getPerson1()==R.getPerson2()))
            {
                cout<<"Relation exists: "<<endl;
                R.printRelation();
                return;
            }

        }

        cout<<"Relation does not exist!"<<endl;
    }



}

void Family::searchFamilyByName(string Fname, string Lname)
{
    for (int j = 0; j < sizeP; ++j)
    {
        if(persList[j].getFname()==Fname && persList[j].getLname()==Lname)
        {
            cout<<"Person exists: ";
            cout<<persList[j];
            return;
        }
    }
    cout<<"Person: "<<Fname<<" "<<Lname<<" does not exist."<<endl;

}






