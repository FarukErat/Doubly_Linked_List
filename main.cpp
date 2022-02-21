#include <iostream>
#include "DLList.hpp"

using namespace std;

int main()
{
    DLList<string> l;
    int choice, index;

    cout << "----------" << endl
         << "  [Menu]   " << endl
         << "----------";

    while (true)
    {
        cout << endl
             << endl
             << "1. add an element" << endl
             << "2. remove an element" << endl
             << "3. change an element" << endl
             << "4. insert an element" << endl
             << "5. get a spesific element" << endl
             << "6. print the list" << endl
             << "7. the size of the list" << endl
             << "0. EXIT" << endl
             << "Enter your choice: ";

        cin >> choice;
        switch (choice)
        {
        case 0:
            return 0;
        case 1:
            cout << "Enter an element to append: ";
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
            cout << "Enter a new element: ";
            cin >> l.input;
            l.insert(index, l.input);
            break;
        case 5:
            cout << "Enter an index to get an element: ";
            cin >> index;
            cout << l.get(index);
            break;
        case 6:
            if (l.size() == 0)
            {
                cout << "The list is empty." << endl;
            }
            else
            {
                for (int i = 0; i < l.size(); i++)
                {
                    cout << l.get(i) << " ";
                }
            }
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
