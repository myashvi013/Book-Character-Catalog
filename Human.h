#ifndef HUMAN_H
#define HUMAN_H
#include "Character.h"
#include <iostream>
#include <string>

/**
 * File : Human.h
 * Derived class holding a Human character 
*/
class Human: public character{
private:
    string favList;

public:
    Human(string cName, string cSpecies, string fList) : character(cName, cSpecies){
        favList = fList;
    }

    string getFavList() const {return favList;}
    void setFavList(string fList) {favList = fList;}

    //Polymorphism override
    void display()const override{
        //cout<<"[Human] Name:" << name << "| Species: " << species << " | Favorite Trope: " << favList << " | Total Score:" << TS() << endl;
        cout << "[Human] " << (*this) << " | Favorite Trope: " << favList << endl;
    }
};

#endif