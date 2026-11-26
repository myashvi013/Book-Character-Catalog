#ifndef NONHUMAN_H
#define NONHUMAN_H

#include "Character.h"
#include <iostream>
#include <string>

/**
 * File : NonHuman.h
 * Dervied class = Non-Human character
*/
class NonHuman : public character{
private:
    string ability;

public:
    NonHuman(string cName, string cSpecies, string cAbility) : character(cName, cSpecies){
        ability = cAbility;
    }

    string getAbility() const {return ability;}
    void setAbility(string cAbility) {ability = cAbility;}

    //Polymorphism override
    void display() const override{
        cout << "[NonHuman] " << (*this) << " | Special Ability: " << ability << endl;
    }
};

#endif