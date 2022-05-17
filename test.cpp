#include <iostream>
#include "DLList.hpp"

using namespace std;

int main()
{
    Queue<string> q;
    q.push("Hello");                                // Hello
    q.push("World");                                // Hello World
    q.push("and");                                  // Hello World and
    q.push("Universe");                             // Hello World and Universe
    q.pop();                                        // World and Universe
    q.pop();                                        // and Universe
    q.pop();                                        // Universe
    cout << q.get(0) << " " << q.getSize() << endl; // Universe(0)

    Stack<string> s;
    s.push("Hello");                                // Hello
    s.push("World");                                // Hello World
    s.push("and");                                  // Hello World and
    s.push("Universe");                             // Hello World and Universe
    s.pop();                                        // Hello World and
    s.pop();                                        // Hello World
    cout << s.get(0) << " " << s.getSize() << endl; // Hello(0) World(1)

    DLList<string> l;
    l.append("Hello");                              // Hello
    l.append("World");                              // Hello World
    l.append("and");                                // Hello World and
    l.append("Universe");                           // Hello World and Universe
    l.pop();                                        // Hello World and
    l.change(1, "Mars");                            // Hello Mars and
    l.pop(1);                                       // Hello and
    cout << l.get(1) << " " << l.getSize() << endl; // Hello(0) and(1)

    return 0;
}
