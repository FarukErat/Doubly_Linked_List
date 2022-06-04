#pragma once
#ifndef DLList_H
#define DLList_H

template <class T>
/**
 * @brief Monomere of the list structure
 *
 */
struct Node
{
    T data;        // data to be stored
    Node<T> *next; // the pointer pointing the next node
    Node<T> *prev; // the pointer pointing the previous node
};

template <class T>
/**
 * @brief Doubly linked list of any type
 *
 */
class DLList
{
protected:
    int sizeOfList;
    Node<T> *head; // the address of the first node
    Node<T> *tail; // the address of the last node
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
    void addHead(T data);
    /**
     * @brief adds a node at the end of the list
     *
     * @param data
     */
    void addTail(T data);
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
    T input; // for users not to have to declare a new variable while inputting
    /**
     * @brief Constructs a new DLList object
     *
     */
    DLList();
    DLList(std::initializer_list<T> const l);
    /**
     * @brief Destroys the DLList object
     *
     */
    ~DLList();
    /**
     * @brief returns the data of the node at the given index
     *
     * @param index
     * @return T
     */
    T &operator[](int index);
    /**
     * @brief overloads the += operator to append to the list
     *
     * @param data
     */
    void operator+=(T data);
    /**
     * @brief overloads the += operator to append a list to the list
     *
     * @param l
     */
    void operator+=(std::initializer_list<T> const l);
    /**
     * @brief clones the list
     *
     * @param list
     */
    void operator=(DLList<T> &list);
    /**
     * @brief resets the list and appends a list to the list
     *
     * @param l
     */
    void operator=(std::initializer_list<T> const l);
    /**
     * @brief overloads the += operator to appened to the list
     *
     * @param data
     */
    void append(T data);
    /**
     * @brief inserts a node at the given index
     *
     * @param pos
     * @param data
     */
    void insert(int pos, T data);
    /**
     * @brief change the data of the node at the given index
     *
     * @param pos
     * @param data
     */
    void change(int pos, T data);
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
    /**
     * @brief enables the user to print list with ease
     *
     * @param out
     * @param list
     *
     * @return std::ostream&
     */
    template <class U> // different type name in order to avoid shadowing the function in the class
    friend std::ostream &operator<<(std::ostream &out, DLList<U> &list);
    /**
     * @brief enables user to imput and append to the list with ease
     *
     * @param in
     * @param list
     * @return std::istream&
     */
    template <class U>
    friend std::istream &operator>>(std::istream &in, DLList<U> &list);
};

template <class T>
void DLList<T>::operator=(DLList<T> &list)
{
    if (this == &list)
        return;
    this->~DLList();                          // deallocate the memory of the current list
    DLList<T> *temp = new (this) DLList<T>(); // reconstruct the list
    for (int i = 0; i < list.Size(); i++)
    {
        this->append(list[i]); // append the elements of the list
    }
};

template <class T>
void DLList<T>::operator=(std::initializer_list<T> const l)
{
    this->~DLList();                          // deallocate the memory of the current list
    DLList<T> *temp = new (this) DLList<T>(); // reconstruct the list
    for (auto i : l)
    {
        this->append(i); // append the elements of the list
    }
};

template <class T>
void DLList<T>::operator+=(T data)
{
    this->append(data);
};

template <class T>
void DLList<T>::operator+=(std::initializer_list<T> const l)
{
    for (auto i : l)
    {
        this->append(i);
    }
};

template <class T>
std::ostream &operator<<(std::ostream &out, DLList<T> &list)
{
    for (int i = 0; i < list.Size(); i++)
    {
        out << list[i] << ' ';
    }
    out << std::endl;
    return out;
}

template <class T>
std::istream &operator>>(std::istream &in, DLList<T> &list)
{
    T data;
    in >> data;
    list.append(data);
    return in;
}

template <class T>
DLList<T>::DLList()
{
    sizeOfList = 0; // initialize the size of the list to 0
    head = nullptr; // initialize the head pointer to nullptr
    tail = nullptr; // initialize the tail pointer to nullptr
};

template <class T>
DLList<T>::DLList(std::initializer_list<T> const l)
{
    sizeOfList = 0; // initialize the size of the list to 0
    head = nullptr; // initialize the head pointer to nullptr
    tail = nullptr; // initialize the tail pointer to nullptr
    for (auto i : l)
    {
        this->append(i);
    }
};

template <class T>
DLList<T>::~DLList()
{
    // if head is nullptr, then head is the tail and they are all to be deleted
    if (head == nullptr)
    {
        delete head;
        return;
    }

    Node<T> *curr = new Node<T>;         // create a pointer to the current node
    Node<T> *nodeToRemove = new Node<T>; // create a pointer to the node to be removed
    curr = head;                         // set the pointer to the head to start from the beginning
    // while the current node is not nullptr
    while (curr->next != nullptr)
    {
        nodeToRemove = curr; // set the node to be removed to the current node
        curr = curr->next;   // move the current node to the next node
        delete nodeToRemove; // delete the node to be removed
    }
    delete curr; // delete the last node
};

template <class T>
T &DLList<T>::operator[](int index)
{
    // check if the index is out of bound
    if (index >= sizeOfList || boundCheck(index) == false)
    {
        throw std::out_of_range("Index out of bound.");
    }

    // iterate through the list to find the index
    Node<T> *ptr = head; // set the pointer to the head to start from the beginning
    for (int i = 0; i < index; i++)
    {
        ptr = ptr->next; // move the pointer to the next node
    }
    return ptr->data; // return the data of the node
};

template <class T>
void DLList<T>::append(T data)
{
    // new node is created
    Node<T> *newNode = new Node<T>;

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

template <class T>
void DLList<T>::insert(int pos, T data)
{
    // if the position is out range
    if (pos < 0 || pos > sizeOfList || boundCheck(pos) == false)
    {
        throw std::out_of_range("Cannot add from out of range.");
    }

    Node<T> *temp = new Node<T>;
    Node<T> *ahead = new Node<T>;
    Node<T> *behind = new Node<T>;

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

template <class T>
void DLList<T>::addHead(T data)
{
    // a new node is created
    Node<T> *temp = new Node<T>;
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

template <class T>
void DLList<T>::addTail(T data)
{
    Node<T> *newNode = new Node<T>; // a new node is created
    newNode->data = data;           // its data is assigned
    newNode->prev = tail;           // the previous node of temp is assigned as tail
    tail->next = newNode;           // the next node of former tail node is assigned as temp
    newNode->next = nullptr;        // the next node of temp node is assigned as nullptr
    tail = newNode;                 // tail node is updated
    sizeOfList++;
}

template <class T>
void DLList<T>::change(int pos, T data)
{
    // if the position is out range
    if (pos < 0 || pos > sizeOfList - 1 || boundCheck(pos) == false)
    {
        throw std::out_of_range("Cannot change out of range.");
    }

    Node<T> *curr = head;
    // iterating to the position
    for (int x = 0; x < pos; x++)
    {
        curr = curr->next;
    }
    curr->data = data; // changing the data
}

template <class T>
void DLList<T>::delHead()
{
    Node<T> *temp = new Node<T>;
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

template <class T>
void DLList<T>::delTail()
{
    Node<T> *temp = new Node<T>;
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

template <class T>
void DLList<T>::pop(int pos)
{
    Node<T> *behind = new Node<T>;
    Node<T> *ahead = new Node<T>;
    if (pos < 0 || pos > sizeOfList - 1 || boundCheck(pos) == false)
    {
        throw std::out_of_range("Cannot pop out of range.");
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

template <class T>
void DLList<T>::pop()
{
    pop(sizeOfList - 1);
};

template <class T>
int DLList<T>::Size()
{
    return sizeOfList; // since size attribute is private
};

template <class T>
bool DLList<T>::boundCheck(int pos)
{
    Node<T> *now = head; // checking if there is any gaps(NULL nodes)
    for (int x = 0; x < pos; x++)
    {
        if (now == NULL)
        {
            return false;
        }
        now = now->next;
    }
    return true;
};
#endif //! DLList_H
