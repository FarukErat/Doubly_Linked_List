#include <iostream>
#include "DLL.h"

#define TYPE double  // in order to keep the type of data same with the type of the list

using namespace std;

int main()
{
    DLList<TYPE> l;
    TYPE data; // keep the type of data same with the type of the list
    int choice, index;

    cout << "----------" << endl
         << "  [Menu]   " << endl
         << "----------";

    while (true)
    {
        cout << endl
             << endl
             << "1. add a value" << endl
             << "2. remove a value" << endl
             << "3. change a value" << endl
             << "4. insert a value" << endl
             << "5. print the list forward" << endl
             << "6. print the list backward" << endl
             << "7. the size of the list" << endl
             << "0. EXIT" << endl
             << "Enter your choice: ";

        cin >> choice;
        switch (choice)
        {
        case 0:
            return 0;
        case 1:
            cout << "Enter a number to append: ";
            cin >> data;
            l.append(data);
            break;
        case 2:
            cout << "Enter an index to pop an element: ";
            cin >> index;
            l.pop(index);
            break;
        case 3:
            cout << "Enter an index to change a value: ";
            cin >> index;
            cout << "Enter the new value: ";
            cin >> data;
            l.change(index, data);
            break;
        case 4:
            cout << "Enter an index to insert a value: ";
            cin >> index;
            cout << "Enter a new value: ";
            cin >> data;
            l.insert(index, data);
            break;
        case 5:
            l.Display();
            break;
        case 6:
            l.RevDisplay();
            break;
        case 7:
            cout << "The size: " << l.size();
            break;
        default:
            cout << "Invalid choice!" << endl
                 << "Enter a valid one";
            break;
        }
    }

    return 0;
}
