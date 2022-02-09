#include <iostream>
#include "DLL.hpp"

using namespace std;

int main()
{
    DLList<double> l;
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
             << "5. get a value" << endl
             << "6. print the list forward" << endl
             << "7. print the list backward" << endl
             << "8. the size of the list" << endl
             << "0. EXIT" << endl
             << "Enter your choice: ";

        cin >> choice;
        switch (choice)
        {
        case 0:
            return 0;
        case 1:
            cout << "Enter a number to append: ";
            cin >> l.input;
            l.append(l.input);
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
            cin >> l.input;
            l.change(index, l.input);
            break;
        case 4:
            cout << "Enter an index to insert a value: ";
            cin >> index;
            cout << "Enter a new value: ";
            cin >> l.input;
            l.insert(index, l.input);
            break;
        case 5:
            cout << "Enter an index to get a value: ";
            cin >> index;
            cout << l.get(index);
            break;
        case 6:
            l.Display();
            break;
        case 7:
            l.RevDisplay();
            break;
        case 8:
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
