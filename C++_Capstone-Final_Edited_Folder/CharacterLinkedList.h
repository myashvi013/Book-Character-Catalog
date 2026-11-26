#ifndef CHARACTER_LINKED_LIST_H
#define CHARACTER_LINKED_LIST_H

#include "Character.h"
#include <iostream>

using namespace std;

//Node structure for custom Linked List
struct Node{
    character* data;
    Node* next;

    Node(character* c){
        data = c;
        next = nullptr;
    }
};

/**
 * File : CharacterLinkedList.h
 * Custon Linked List data structure built from scratch.
*/
class CharacterLinkedList{
private:
    Node* head;
    int size;

public:
    CharacterLinkedList(){
        head = nullptr;
        size = 0;
    }

    ~CharacterLinkedList(){
        Node* current = head;
        while(current != nullptr){
            Node* nextNode = current->next;
            delete current->data;
            delete current;
            current = nextNode;
        }
    }

    int getSize() const {return size;}
    bool isEmpty() const {return head == nullptr;}

    //Add Character to linked list
    void addCharacter(character* c){
        Node* newNode = new Node(c);
        if(head == nullptr){
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr){
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }

    // Search for character by name and species
    bool searchCharacter(string searchName, string searchSpecies) const {
        Node* current = head;
        while(current != nullptr){
            if(current->data->getName() == searchName && current->data->getSpecies() == searchSpecies){
                return true;
            }
            current = current->next;
        }
        return false;
    }

    //Display all characters using polymorphism
    void displayAll() const {
        if(isEmpty()){
            cout << "Catalog is empty. \n";
            return;
        }
        Node* current = head;
        int index = 1;
        while (current != nullptr){
            cout << index++ << ". ";
            current->data->display(); //Polymorphic call
            current = current->next;
        }
    }

    // Custom Sorting Algorithm (Bubble Sort implemented on Linked List)
    void sortCatalog(){
        if(isEmpty() || head->next == nullptr) return;
        bool swapped;
        Node* ptr1;
        Node* lptr = nullptr;

        do{
            swapped = false;
            ptr1 = head;

            while(ptr1->next != lptr){
                // Using overloaded operator< to sort descending by total score
                if(*(ptr1->next->data) < *(ptr1->data)){
                    character* temp = ptr1->data;
                    ptr1->data = ptr1->next->data;
                    ptr1->next->data = temp;
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while(swapped);
    }
};

#endif