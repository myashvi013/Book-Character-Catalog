/**
 * File : main.cpp
 * Capstone Draft Main Program - Character Catalog Manager
*/

#include <iostream>
#include <string>
#include "Character.h"
#include "Human.h"
#include "NonHuman.h"
#include "CharacterLinkedList.h"
using namespace std;
int main(){
    // Custom Data Structure from scratch
    CharacterLinkedList catalog;
    int choice=0;

    cout<<"Character Ranking Catalog\n";

    do{
        cout<<"\n Main Menu\n";
        cout<<"1. Add New Character?\n";
        cout<<"2. View All Characters\n";
        cout<<"3. Search Character\n";
        cout<<"4. Sort Catalog by Trait Scores\n";
        cout<<"5. Exit\n";
        cout<<"Enter Choice: ";
        cin>>choice;

        if(cin.fail()){
            cin.clear();
            cin.ignore(10000, '\n');
            cout<<"Invalid input. Please enter a number given.\n";
            continue;
        }
        switch(choice){
            case 1:{
                cin.ignore();
                string name, species, typeChoice;
                cout<<"Enter Character Name: ";
                getline(cin, name);
                cout<<"Enter Species: ";
                getline(cin, species);
                
                //Overloaded operator== check
                if(catalog.searchCharacter(name, species)){
                    cout << "[Notice] A character with this name and species already exists!\n";
                    break;
                }

                cout << "Is this character Human?: ";
                getline(cin, typeChoice);

                character* newChar = nullptr;
                if(typeChoice == "y" || typeChoice == "Y"){
                    string fav;
                    cout << "Enter Favorite Trope: ";
                    getline(cin, fav);
                    newChar = new Human(name, species, fav);
                } else{
                    string ability;
                    cout << "Enter Special Ability: ";
                    getline(cin, ability);
                    //Inheritance & Polymorphism 
                    newChar = new NonHuman(name, species, ability);
                }

                cout << "Enter 3 trait scores (0-100):\n";
                for(int i = 0; i < 3; i++){
                    int score;
                    cout << " Trait " << (i + 1) << ": ";
                    cin >> score;
                    newChar->setScore(1, score);
                }

                catalog.addCharacter(newChar);
                cout << "Character successfully added!\n";
                break;
            }
            case 2:{
                cout << "\n--- Current Catalog ---\n";
                catalog.displayAll();
                break;
            }
            case 3:{
                cin.ignore();
                string searchName, searchSpecies;
                cout << "Enter Character Name to search: ";
                getline(cin, searchName);
                cout << "Enter Character Species: ";
                getline(cin, searchSpecies);

                if(catalog.searchCharacter(searchName, searchSpecies)){
                    cout << "[Found] Character exists in the catalog!\n";
                } else{
                    cout << "[Not Found] Character does not exist.\n";
                }
                break;
            }

            case 4: {
                //Custom Sorting Algorithm
                catalog.sortCatalog();
                cout << "[Success] Catalog sorted by total trait scores!\n";
                catalog.displayAll();
                break;
            }
            case 5:
                cout << "Existing program. Goodbye!\n";
                break;
            default:
                cout << "Invaild choice. Try again.\n";

        }
    } while (choice != 5);
    return 0;
};

