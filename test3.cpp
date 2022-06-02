#include <iostream>
#include "DLList.hpp"

using namespace std;

int main()
{
    DLList<int> list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);
    DLList<DLList<int> *> list2;
    list2.append(&list1);
    DLList<DLList<DLList<int> *> *> list3;
    list3.append(&list2);
    cout << list3.get(0)->get(0)->get(0) << endl;

    return 0;
}
