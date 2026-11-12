#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>

using namespace std;

/**
 * File : Character.h
 * Abstract base class having a fictional character.
*/
class character{
protected :
    string name;
    string species;
    int score[3];
public:
    character(string cName="",string cSpecies=""){
        name=cName;
        species=cSpecies;
        for(int i=0; i<3; i++){
            score[i]=0;
        }
    }
    virtual ~character(){}

    //Getters and Setters
    string getName() const{return name;}
    string getSpecies() const{return species;}

    void setName(string cName) {name = cName;}
    void setSpecies(string cSpecies) {species = cSpecies;}

    void setScore(int index, int Tscore){
        if(index>= 0 && index<3){
            score[index]=Tscore;
        }
    }

    int getScore(int index) const{
        if(index >= 0 && index < 3) return score[index];
        return 0;
    }

    //Calculate total trait score
    int TS() const{
        int total=0;
        for(int i=0; i<3; i++){
            total += score[i];
        }
        return total;
    }
    // Virtural function for polymorphism
    virtual void display() const=0;

    //Overloaded operator== (checks for duplicates by name and species)
    bool operator==(const character& other) const{
        return(name == other.name && species == other.species);
    }

    //Overloaded operator< (compares trait scores for sorting)
    bool operator<(const character& other) const{
        return this->TS() < other.TS();
    }

    //Overloaded operator << (stream insertation for printing)
    friend ostream& operator<<(ostream& os, const character& c){
        os << "Name: " << c.name << " | Species: " << c.species << " | Total Score: " << c.TS();
        return os;
    }
};

#endif