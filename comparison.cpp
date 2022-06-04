/* a code to compare vector library and my own implementation */

#include <iostream>
#include <vector>

#include "DLList.hpp"

using namespace std;

int main()
{
    DLList<int> list = {1, 2, 3, 4, 5};
    vector<int> v = {1, 2, 3, 4, 5};

    cout << list; // 1 2 3 4 5
    // cout << v; // no operator "<<" matches these operands

    list += 6;
    // v += 6; // no operator "+=" matches these operands

    list += {7, 8, 9, 10};
    // v += {7, 8, 9, 10}; // no operator "+=" matches these operands

    list[0] = 0;
    v[0] = 0;

    list[100]; // terminates with error message
    v[100];    // terminates withOUT error message

    list.insert(0, 0);
    // v.insert(0, 0); // does NOT have insert method

    list.change(0, 0);
    // v.change(0, 0); // does NOT have change method

    list.pop(0);
    v.pop_back(); // can only pop back

    cout << list[0] << endl;
    cout << v[0] << endl;

    cin >> list[0];
    cin >> v[0];

    cout << list[0] << endl;
    cout << v[0] << endl;

    cin >> list[0];
    cin >> v[0];

    cin >> list;
    // cin >> v; // no operator ">>" matches these operands

    return 0;
}
