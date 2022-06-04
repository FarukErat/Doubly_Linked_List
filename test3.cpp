#include <iostream>
#include "DLList.hpp"

using namespace std;

int main()
{
    // list of ints
    DLList<int> list1;
    list1.append(456);

    // list of pointers to lists of ints
    DLList<DLList<int> *> list2;
    list2.append(&list1);

    // list pointers to lists of pointers to lists of ints
    DLList<DLList<DLList<int> *> *> list3;
    list3.append(&list2);

    cout << *list3[0][0][0];
    /* prints 1
    list3[0] returns a pointer to a list of pointers to lists of ints
    list3[0][0] returns a pointer to a list of ints
    list3[0][0][0] returns an int
    */

    return 0;
}
