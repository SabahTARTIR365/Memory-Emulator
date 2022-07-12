#include <iostream>
#include <cstdlib>
#include "StrutureHelper.cpp";

#include "Services.h"
using namespace std;

void menu();
void mainMenu();
void addDataSetForQueue();
int choice1 = 0;

Services CommandServices;


int main(int argc, char** argv) {

    addDataSetForQueue();
    menu();

    return 0;
}


void menu() {

    do {
      
        mainMenu();

        switch (choice1) {

        case 1:
            cout << "The data already generated as dataset in the begining \n\n";
            break;

        case 2:
            cout << "Select Id from the above list and enter\n";
            int id;
            cin >> id;
            CommandServices.Remove(id);
            break;

        case 3:
            cout << "----------Excution process for command start------- \n";
            CommandServices.Excute();
            break;
        case 4:
            CommandServices.Abort();
            break;
        case 5:
            break;//for quit

        }

    } while (choice1 != 5);


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
        my.Type = "write";
        my.StoredData.Value = 0x10+i;
        my.StoredData.Address = 0x20+i;
        my.print();
        CommandServices.Add(my);
    }


    for ( i = 5; i < 10; i++)
    {
        Command my;
        my.Id = 1000 + i;
        i % 2 ? my.Priority = false : my.Priority = true;
        my.Type = "read";
        my.StoredData.Address = 0x28 -i;
        my.print();
        CommandServices.Add(my);
    }

    Command m1(1001, "delete", false);
    m1.StoredData.Address = 0x21;
    m1.print();
    CommandServices.Add(m1);
    Command m2(1002, "delete", false);
    m2.StoredData.Address = 0x22;
    m2.print();
    CommandServices.Add(m2);
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

