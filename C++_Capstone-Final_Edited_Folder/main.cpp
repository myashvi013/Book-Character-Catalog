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
#include "Menu.h"
using namespace std;
int main(){
    // Custom Data Structure from scratch
    CharacterLinkedList catalog;
    

    // Dedicated Menu class using std::vector
    Menu mainMenu("CHARACTER CATALOG MANAGER");
    mainMenu.addOption("Add New Character");
    mainMenu.addOption("View All Characters");
    mainMenu.addOption("Search Character");
    mainMenu.addOption("Sort Catalog by Trait Score");
    mainMenu.addOption("Exit");

    int choice = 0;

    do{
        mainMenu.display();
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

                cout << "Is this character Human?: ";
                getline(cin, typeChoice);
                
                character* newChar = nullptr;
                if(typeChoice == "y" || typeChoice == "Y"){
                    string fav;
                    cout << "Enter Favorite Trope: ";
                    getline(cin, fav);
                    newChar = new Human(name, species, fav);
                } else {
                    string ability;
                    cout << "Enter Special Ability: ";
                    getline(cin, ability);
                    //Inheritance + Polymorphism
                    newChar = new NonHuman(name, species, ability);
                }


                //character* newChar = nullptr;
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
                for(int i=0; i<3; i++){
                    int score;
                    cout << " Trait " << (i+1) << ": ";
                    cin >> score;
                    newChar->setScore(i, score);
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

