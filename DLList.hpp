#pragma once
#ifndef DLList_H
#define DLList_H

template <class Anytype>
/**
 * @brief Monomere of the list structure
 *
 */
struct Node
{
    Anytype data;        // data to be stored
    Node<Anytype> *next; // the pointer pointing the next node
    Node<Anytype> *prev; // the pointer pointing the previous node
};

template <class Anytype>
/**
 * @brief Doubly linked list of any type
 *
 */
class DLList
{
protected:
    int sizeOfList;
    Node<Anytype> *head; // the address of the first node
    Node<Anytype> *tail; // the address of the last node
    /**
     * @brief checks if there is boundary violation
     *
     * @param pos
     * @return true
     * @return false
     */
    bool boundCheck(int pos);

    // the following functions are not for public use
    /**
     * @brief adds a node at the beginning of the list
     *
     * @param data
     */
    void addHead(Anytype data);
    /**
     * @brief adds a node at the end of the list
     *
     * @param data
     */
    void addTail(Anytype data);
    /**
     * @brief deletes the first node
     *
     */
    void delHead();
    /**
     * @brief deletes the last node
     *
     */
    void delTail();

public:
    Anytype input; // for users not to have to declare a new variable while inputting
    /**
     * @brief Constructs a new DLList object
     *
     */
    DLList();
    /**
     * @brief Destroys the DLList object
     *
     */
    ~DLList();
    /**
     * @brief returns the data of the node at the given index
     *
     * @param index
     * @return Anytype
     */
    Anytype get(int index);
    /**
     * @brief appends a node at the end of the list
     *
     * @param data
     */
    void append(Anytype data);
    /**
     * @brief inserts a node at the given index
     *
     * @param pos
     * @param data
     */
    void insert(int pos, Anytype data);
    /**
     * @brief change the data of the node at the given index
     *
     * @param pos
     * @param data
     */
    void change(int pos, Anytype data);
    /**
     * @brief deletes the node at the given index but does not return the data
     *
     * @param pos
     */
    void pop(int pos);
    /**
     * @brief deletes the last node
     *
     */
    void pop();
    /**
     * @brief prints the elements of the list
     *
     */
    void printDLList(char delimiter = ' ');
    /**
     * @brief returns the size of the list
     *
     * @return int
     */
    int Size();
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

    Node<Anytype> *curr = new Node<Anytype>;         // create a pointer to the current node
    Node<Anytype> *nodeToRemove = new Node<Anytype>; // create a pointer to the node to be removed
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
    if (index >= sizeOfList || boundCheck(index) == false)
    {
        std::cout << "Index out of bound." << std::endl;
        return 0;
    }

    // iterate through the list to find the index
    Node<Anytype> *ptr = new Node<Anytype>;
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
    Node<Anytype> *newNode = new Node<Anytype>;

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
    if (boundCheck(pos) == false)
    {
        std::cout << "Cant add from out of range." << std::endl;
        return;
    }

    Node<Anytype> *temp = new Node<Anytype>;
    Node<Anytype> *ahead = new Node<Anytype>;
    Node<Anytype> *behind = new Node<Anytype>;

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
    Node<Anytype> *temp = new Node<Anytype>;
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

    Node<Anytype> *newNode = new Node<Anytype>; // a new node is created
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
    Node<Anytype> *curr = head;
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
    Node<Anytype> *temp = new Node<Anytype>;
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
    Node<Anytype> *temp = new Node<Anytype>;
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
    Node<Anytype> *behind = new Node<Anytype>;
    Node<Anytype> *ahead = new Node<Anytype>;
    if (boundCheck(pos) == false)
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
void DLList<Anytype>::printDLList(char delimiter)
{
    for (int x = 0; x < sizeOfList; x++)
    {
        std::cout << get(x) << delimiter;
    }
    std::cout << std::endl;
};

template <class Anytype>
int DLList<Anytype>::Size()
{
    return sizeOfList; // since size attribute is private
};

template <class Anytype>
bool DLList<Anytype>::boundCheck(int pos)
{
    Node<Anytype> *now = head; // checking if there is any gaps(NULL nodes)
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
    int Size()
    {
        return l.Size();
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
    int Size()
    {
        return l.Size();
    }
    Anytype get(int pos)
    {
        return l.get(pos);
    }
};
//! end of class Queue

#endif //! DLList_H
