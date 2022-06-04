#include <iostream>
#include "DLList.hpp"

using namespace std;

int main()
{
    DLList<int> list;
    list += 1;
    list += 2;
    list += 3;
    DLList<int> copy;
    copy = list;
    cout << "list: " << list;
    cout << "copy: " << copy;
    cout << "address of list: " << &list << endl;
    cout << "address of copy: " << &copy << endl;
    return 0;
}
