#include <iostream>
#include "DLList.hpp"

using namespace std;

void first(int num1, int num2)
{
    cout << "First function called with " << num1 << " and " << num2 << endl;
}

void second(int num1, int num2)
{
    cout << "Second function called with " << num1 << " and " << num2 << endl;
}

void third(int num1, int num2)
{
    cout << "Third function called with " << num1 << " and " << num2 << endl;
}

int main()
{
    // test on queues
    Queue<string> q;
    q.push("Hello");                         // Hello
    q.push("World");                         // Hello World
    q.push("and");                           // Hello World and
    q.push("Universe");                      // Hello World and Universe
    q.pop();                                 // World and Universe
    q.pop();                                 // and Universe
    q.pop();                                 // Universe
    cout << q[0] << " " << q.Size() << endl; // Universe(0)
    cout << q;                               // Universe

    // test on stacks
    Stack<string> s;
    s.push("Hello");                         // Hello
    s.push("World");                         // Hello World
    s.push("and");                           // Hello World and
    s.push("Universe");                      // Hello World and Universe
    s.pop();                                 // Hello World and
    s.pop();                                 // Hello World
    cout << s[0] << " " << s.Size() << endl; // Hello(0) World(1)
    cout << s;                               // Hello World

    // test on lists
    DLList<string> l;
    l.append("Hello");                       // Hello
    l.append("World");                       // Hello World
    l.append("and");                         // Hello World and
    l.append("Universe");                    // Hello World and Universe
    l.pop();                                 // Hello World and
    l.change(1, "Mars");                     // Hello Mars and
    l.pop(1);                                // Hello and
    cout << l[0] << " " << l.Size() << endl; // Hello(0) and(1)
    cout << l;                               // Hello and

    // test on function lists
    DLList<void (*)(int, int)> funcs;

    funcs.append(first);
    funcs.append(second);
    funcs.append(third);

    funcs[1](0, 5); // call second function with 0 and 5
    funcs[0](3, 1); // call first function with 3 and 1
    funcs[2](7, 2); // call third function with 7 and 5
    cout << funcs;

    return 0;
}
