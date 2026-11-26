#ifndef MENU_h
#define MENU_h
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * file: Menu.h
 * Menu management class menu items using std::vector.
*/
class Menu {
    private:
    string title;
    vector<string> options;
public:
    Menu(string menuTitle){
        title = menuTitle;
    }
    void addOption(string option){
        options.push_back(option);
    }
    void display() const{
        cout << "\n===========================\n";
        cout << "       " << title << "      ";
        cout << "=============================\n";
        for(size_t i = 0; i<options.size(); ++i){
            cout << (i+1) << ". " << options[i] << "\n";
        }
        cout << "Enter Choice: ";
    }
};
#endif