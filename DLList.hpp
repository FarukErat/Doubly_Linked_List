#pragma once
#ifndef DLList_H
#define DLList_H

template <class Anytype>
struct node
{
    Anytype data;        // data to be stored
    node<Anytype> *next; // the pointer pointing the next node
    node<Anytype> *prev; // the pointer pointing the previous node
};

template <class Anytype>
class DLList
{
protected:
    int sizeOfList;
    node<Anytype> *head; // the address of the first node
    node<Anytype> *tail; // the address of the last node
    bool BoundCheck(int pos);

    // the following functions are not for public use
    void addHead(Anytype data); // add a node at the beginning of the list
    void addTail(Anytype data); // add a node at the end of the list
    void delHead();             // delete the first node
    void delTail();             // delete the last node

public:
    Anytype input;
    DLList();                           // constructor
    ~DLList();                          // destructor
    Anytype get(int index);             // get the data of the node at the given index
    void append(Anytype data);          // append a node at the end of the list
    void insert(int pos, Anytype data); // insert a node at the given index
    void change(int pos, Anytype data); // change the data of the node at the given index
    void pop(int pos);                  // delete the node at the given index
    void pop();                         // delete the last node
    int getSize();                      // return the size of the list
};

template <class Anytype>
DLList<Anytype>::DLList()
{
    sizeOfList = 0; // initialize the size of the list to 0
    head = nullptr; // initialize the head pointer to nullptr
    tail = nullptr; // initialize the tail pointer to nullptr
};

template <class Anytype>
DLList<Anytype>::~DLList()
{
    // if head is nullptr, then head is the tail and they are all to be deleted
    if (head == nullptr)
    {
        delete head;
        return;
    }

    node<Anytype> *curr = new node<Anytype>;         // create a pointer to the current node
    node<Anytype> *nodeToRemove = new node<Anytype>; // create a pointer to the node to be removed
    curr = head;                                     // set the pointer to the head to start from the beginning
    // while the current node is not nullptr
    while (curr->next != nullptr)
    {
        nodeToRemove = curr; // set the node to be removed to the current node
        curr = curr->next;   // move the current node to the next node
        delete nodeToRemove; // delete the node to be removed
    }
    delete curr; // delete the last node
};

template <class Anytype>
Anytype DLList<Anytype>::get(int index)
{
    // check if the index is out of bound
    if (BoundCheck(index) == false)
    {
        std::cout << "Index out of bound." << std::endl;
        return 0;
    }

    // iterate through the list to find the index
    node<Anytype> *ptr = new node<Anytype>;
    ptr = head; // set the pointer to the head to start from the beginning
    for (int i = 0; i < index; i++)
    {
        ptr = ptr->next; // move the pointer to the next node
    }
    return ptr->data; // return the data of the node
};

template <class Anytype>
void DLList<Anytype>::append(Anytype data)
{
    // new node is created
    node<Anytype> *newNode = new node<Anytype>;

    // new node is initialized
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    // if the list is not empty
    if (head != nullptr)
    {
        tail->next = newNode;
        // temp's previous node is assigned as curr
        newNode->prev = tail;
        // tail node is updated
        tail = newNode;
    }
    // if list is empty
    else
    {
        // in this case head and tail nodes are the same node
        head = newNode;
        tail = newNode;
    }
    sizeOfList++;
};

template <class Anytype>
void DLList<Anytype>::insert(int pos, Anytype data)
{
    // if the position is out range
    if (BoundCheck(pos) == false)
    {
        std::cout << "Cant add from out of range." << std::endl;
        return;
    }

    node<Anytype> *temp = new node<Anytype>;
    node<Anytype> *ahead = new node<Anytype>;
    node<Anytype> *behind = new node<Anytype>;

    // it means it is head, if position is 0
    if (pos == 0)
    {
        addHead(data);
        return;
    }

    // it means it is tail, if position is size
    if (pos == sizeOfList)
    {
        addTail(data);
        return;
    }
    ahead = head;

    // ahead node is iterated to the position
    for (int x = 0; x < pos; x++)
    {
        behind = ahead;
        ahead = ahead->next;
    }

    // linking temp and ahead
    temp->next = ahead;
    ahead->prev = temp;

    // linking temp and behind
    behind->next = temp;
    temp->prev = behind;

    // assigning the data
    temp->data = data;
    sizeOfList++;
};

template <class Anytype>
void DLList<Anytype>::addHead(Anytype data)
{
    // a new node is created
    node<Anytype> *temp = new node<Anytype>;
    // its data is assigned
    temp->data = data;
    // the next node of temp is assigned as head
    temp->next = head;
    // the previous node of temp is assigned as nullptr
    temp->prev = nullptr;
    // the previous node of the former head node is assigned as temp
    head->prev = temp;
    // head node is updated to temp
    head = temp;
    sizeOfList++;
};

template <class Anytype>
void DLList<Anytype>::addTail(Anytype data)
{

    node<Anytype> *newNode = new node<Anytype>; // a new node is created
    newNode->data = data;                       // its data is assigned
    newNode->prev = tail;                       // the previous node of temp is assigned as tail
    tail->next = newNode;                       // the next node of former tail node is assigned as temp
    newNode->next = nullptr;                    // the next node of temp node is assigned as nullptr
    tail = newNode;                             // tail node is updated
    sizeOfList++;
}

template <class Anytype>
void DLList<Anytype>::change(int pos, Anytype data)
{
    node<Anytype> *curr = head;
    // iterating to the position
    for (int x = 0; x < pos; x++)
    {
        curr = curr->next;
    }
    curr->data = data; // changing the data
}

template <class Anytype>
void DLList<Anytype>::delHead()
{
    node<Anytype> *temp = new node<Anytype>;
    if (sizeOfList == 0)
    {
        std::cout << "Out of bound! From head." << std::endl;
        return;
    }
    // if there is only one node
    if (head->next == nullptr)
    {
        head = nullptr;
        sizeOfList--;
    }
    else
    {

        temp = head->next; // head is moved one node further
        temp->prev = nullptr;
        delete head;
        head = temp; // head is updated to temp
        sizeOfList--;
    }
};

template <class Anytype>
void DLList<Anytype>::delTail()
{
    node<Anytype> *temp = new node<Anytype>;
    if (sizeOfList == 0)
    {
        std::cout << "Out of bound! From tail." << std::endl;
        return;
    }
    // if there is only one node
    if (tail->prev == nullptr)
    {
        tail = nullptr;
        sizeOfList--;
    }
    else
    {
        temp = tail->prev; // tail is moved one node back
        temp->next = nullptr;
        delete tail;
        tail = temp; // tail is updated to temp
        sizeOfList--;
    }
}

template <class Anytype>
void DLList<Anytype>::pop(int pos)
{
    node<Anytype> *behind = new node<Anytype>;
    node<Anytype> *ahead = new node<Anytype>;
    if (BoundCheck(pos) == false)
    {
        std::cout << "Cant delete, out of range." << std::endl;
        return;
    }

    // when the position is after the tail
    if (pos == sizeOfList - 1)
    {
        delTail();
        return;
    }

    // when the position is before head
    if (pos == 0)
    {
        delHead();
        return;
    }

    ahead = head;
    for (int x = 0; x < pos; x++)
    {
        behind = ahead;
        ahead = ahead->next;
    }

    behind->next = ahead->next;
    ahead->next->prev = behind;

    delete ahead;
    sizeOfList--;
};

template <class Anytype>
void DLList<Anytype>::pop()
{
    pop(sizeOfList - 1);
}

template <class Anytype>
int DLList<Anytype>::getSize()
{
    return sizeOfList; // since size attribute is private
};

template <class Anytype>
bool DLList<Anytype>::BoundCheck(int pos)
{
    node<Anytype> *now = head; // checking if there is any gaps(NULL nodes)
    for (int x = 0; x < pos; x++)
    {
        if (now == NULL)
        {
            return false;
        }
        now = now->next;
    }
    return true;
}
//! end of class DLList

//! class Stack
template <class Anytype>
class Stack
{
private:
    DLList<Anytype> l;

public:
    Anytype input;
    void push(Anytype data)
    {
        l.append(data);
    }
    void pop()
    {
        l.pop();
    }
    int getSize()
    {
        return l.getSize();
    }
    Anytype get(int pos)
    {
        return l.get(pos);
    }
};
//! end of class Stack

//! class Queue
template <class Anytype>
class Queue
{
private:
    DLList<Anytype> l;

public:
    Anytype input;
    void push(Anytype data)
    {
        l.append(data);
    }
    void pop()
    {
        l.pop(0);
    }
    int getSize()
    {
        return l.getSize();
    }
    Anytype get(int pos)
    {
        return l.get(pos);
    }
};
//! end of class Queue

#endif //! DLList_H
