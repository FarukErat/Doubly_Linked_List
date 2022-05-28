#include <iostream>

#include "DLList.hpp"

using namespace std;

int main()
{
    DLList<string> l;
    l.append("Hello");
    l.append("World");
    l.append("!");
    l.printDLList();
    l.change(1, "Mars");
    l.printDLList();
    l.pop(1);
    l.printDLList();
    cout << l.get(1) << endl;
    l.insert(1, ", how are you");
    l.printDLList();
    l.pop();
    l.printDLList();
    cout << "Size: " << l.Size() << endl;

    return 0;
}
