#include <iostream>
#include <cstdlib>
#include "StrutureHelper.cpp";

#include "Services.h"
using namespace std;

void menu();
void mainMenu();
void optionsMenu();
void commandOptions();
void addDataSetForQueue();
int choice1 = 0;
int choice2 = 4;
Services CommandServices;


int main(int argc, char** argv) {

    addDataSetForQueue();
    menu();

    return 0;
}


void menu() {

    do {
        choice2 = 0;
        mainMenu();

        switch (choice1) {

        case 1:
            commandOptions();
          
            break;

        case 2:
            cout << "Pew pew!\n";
            break;

        case 3:
            break;
        case 4:
            break;
        case 5:
            break;//for quit

        }

    } while (choice1 != 5);


}

void commandOptions(void) {

    do {
        optionsMenu();

        switch (choice2) {

        case 1://create a read command 

            break;

        case 2:////create a write command 
            cout << "Beep!\n";
            break;

        case 3://create a delete command 
            cout << "Bbbbeep!\n";
            break;


        case 4://exit 
            break;

        default:
            break;

        }

    } while (choice2 != 4);


}

void addDataSetForQueue()
{  
    cout << "-------------------------Generate random Data set----------------------------- \n";
    int i=0;
    for ( i = 0; i < 5; i++)
    {
        Command my;
        my.Id = 1000+i;
        i % 2 ? my.Priority = true : my.Priority = false;
        my.Type = "Write";
        my.StoredData.Value = 0x10+i;
        my.StoredData.Address = 0x20+i;
        my.print();
    }
    for ( i = 5; i < 10; i++)
    {
        Command my;
        my.Id = 1000 + i;
        i % 2 ? my.Priority = true : my.Priority = false;
        my.Type = "read";
        my.StoredData.Address = 0x24 -i;
        my.print();
    }

    Command m1(1001, "delete", false);
    m1.StoredData.Address = 0x21;
    m1.print();

    Command m2(1002, "delete", false);
    m2.StoredData.Address = 0x22;
    m2.print();
    cout << "-------------------------End of Generation ----------------------------- \n";
    }

void mainMenu(void) {



    cout << "Main Menu\n";
    cout << "1 - Add command\n";
    cout << "2 - Remove command\n";
    cout << "3 - Execute\n";
    cout << "4 - Abort process\n";
    cout << "5 - Quit\n";
    cout << "Please choose: ";
    cin >> choice1;

}

void optionsMenu(void) {



    cout << "Options Menu for adding command\n";
    cout << "1 - Read command\n";
    cout << "2 - Write command \n";
    cout << "3- Delete command \n";
    cout << "4- Back\n";
    cout << "Please choose: ";
    cin >> choice2;

}