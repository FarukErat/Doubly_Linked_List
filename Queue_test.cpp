#include <iostream>
#include "DLList.hpp"

using namespace std;

int main()
{
    int choice, index;
    Queue<string> q;
    while (true)
    {
        cout << "1 - push" << endl;
        cout << "2 - pop" << endl;
        cout << "3 - size" << endl;
        cout << "4 - print" << endl;
        cout << "0 - exit" << endl;

        cin >> choice;
        switch (choice)
        {
        case 0:
            return 0;
        case 1:
            cout << "Enter an element to push: ";
            cin >> q.input;
            q.push(q.input);
            break;
        case 2:
            q.pop();
            break;
        case 3:
            cout << "The size of the queue is: " << q.size() << endl;
            break;
        case 4:
            for (int i = 0; i < q.size(); i++)
            {
                cout << q.get(i) << endl;
            }
            break;
        }
    }

    return 0;
}