#include <iostream>

#include "DLList.hpp"

int main()
{
    DLList<int> list = {1, 2, 3, 4, 5};
    list += 6;
    list += {7, 8, 9, 10};
    std::cout << list; // 1 2 3 4 5 6 7 8 9 10

    return 0;
}
