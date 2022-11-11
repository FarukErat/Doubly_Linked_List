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
private:
    int size = 0;
    Node<T> *head = nullptr; // the address of the first node
    Node<T> *tail = nullptr; // the address of the last node
    /**
     * @brief checks if there is boundary violation
     *
     * @param index
     * @return true
     * @return false
     */
    bool boundCheck(int index);

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
    DLList<T> operator+(DLList<T> &list);
    DLList<T> operator+(T data);
    /**
     * @brief overloads the += operator to append a list to the list
     *
     * @param data
     */
    void operator+=(DLList<T> &list);
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
     * @brief inserts a node at the given index
     *
     * @param index
     * @param data
     */
    void insert(T data, int index);
    void append(T data);
    /**
     * @brief deletes the node at the given index but does not return the data
     *
     * @param index
     */
    void remove(int index);
    /**
     * @brief deletes the last node
     *
     */
    void pop();
    /**
     * @brief returns the size of the list
     *
     * @return int
     */
    int getSize();
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
    template <class U>
    friend DLList<U> operator+(U data, DLList<U> &list);
};

template <class T>
void DLList<T>::operator=(DLList<T> &list)
{
    if (this == &list)
        return;
    this->~DLList();                          // deallocate the memory of the current list
    DLList<T> *temp = new (this) DLList<T>(); // reconstruct the list
    for (int i = 0; i < list.getSize(); i++)
    {
        this->append(list[i]); // append the elements of the list
    }
};

template <class T>
void DLList<T>::operator+=(DLList<T> &list)
{
    for (int i = 0; i < list.getSize(); i++)
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
    for (int i = 0; i < list.getSize(); i++)
    {
        out << list[i] << ' ';
    }
    out << std::endl;
    return out;
};

template <class T>
std::istream &operator>>(std::istream &in, DLList<T> &list)
{
    T data;
    in >> data;
    list.append(data);
    return in;
};

template <class T>
DLList<T>::DLList()
{
    size = 0;       // initialize the size of the list to 0
    head = nullptr; // initialize the head pointer to nullptr
    tail = nullptr; // initialize the tail pointer to nullptr
};

template <class T>
DLList<T>::DLList(std::initializer_list<T> const l)
{
    size = 0;
    head = nullptr;
    tail = nullptr;
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
    if (index >= size || boundCheck(index) == false)
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
DLList<T> DLList<T>::operator+(DLList<T> &list)
{
    DLList<T> temp;
    temp += *this;
    temp += list;
    return temp;
}

template <class T>
DLList<T> DLList<T>::operator+(T data)
{
    DLList<T> temp;
    temp += *this;
    temp += data;
    return temp;
}

template <class U>
DLList<U> operator+(U data, DLList<U> &list)
{
    DLList<U> temp;
    temp += data;
    temp += list;
    return temp;
}

template <class T>
void DLList<T>::insert(T data, int index)
{
    if (head == nullptr)
    {
        // new node is created
        Node<T> *newNode = new Node<T>;

        // new node is initialized
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
        size++;
        return;
    }
    // it means it is head, if position is 0
    if (index == 0)
    {
        addHead(data);
        return;
    }
    // it means it is tail, if position is sizeOfList
    else if (index == size)
    {
        addTail(data);
        return;
    }
    else
    {
        // new node is created
        Node<T> *newNode = new Node<T>;

        // new node is initialized
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        // iterate through the list to find the index
        Node<T> *ptr = head; // set the pointer to the head to start from the beginning
        for (int i = 0; i < index; i++)
        {
            ptr = ptr->next; // move the pointer to the next node
        }
        newNode->next = ptr;       // new node's next node is assigned as ptr
        newNode->prev = ptr->prev; // new node's previous node is assigned as ptr's previous node
        ptr->prev->next = newNode; // ptr's previous node's next node is assigned as new node
        ptr->prev = newNode;       // ptr's previous node is assigned as new node
        size++;
    }
};

template <class T>
void DLList<T>::append(T data)
{
    insert(data, size);
}

template <class T>
void DLList<T>::addHead(T data)
{
    Node<T> *temp = new Node<T>; // a new node is created
    temp->data = data;           // its data is assigned
    temp->next = head;           // the next node of temp is assigned as head
    temp->prev = nullptr;        // the previous node of temp is assigned as nullptr
    head->prev = temp;           // the previous node of the former head node is assigned as temp
    head = temp;                 // head node is updated to temp
    size++;
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
    size++;
};

template <class T>
void DLList<T>::delHead()
{
    Node<T> *temp = new Node<T>;
    if (size == 0)
    {
        std::cout << "Out of bound! From head." << std::endl;
        return;
    }
    // if there is only one node
    if (head->next == nullptr)
    {
        head = nullptr;
        size--;
    }
    else
    {
        temp = head->next; // head is moved one node further
        temp->prev = nullptr;
        delete head;
        head = temp; // head is updated to temp
        size--;
    }
};

template <class T>
void DLList<T>::delTail()
{
    Node<T> *temp = new Node<T>;
    if (size == 0)
    {
        std::cout << "Out of bound! From tail." << std::endl;
        return;
    }
    // if there is only one node
    if (tail->prev == nullptr)
    {
        tail = nullptr;
        size--;
    }
    else
    {
        temp = tail->prev; // tail is moved one node back
        temp->next = nullptr;
        delete tail;
        tail = temp; // tail is updated to temp
        size--;
    }
};

template <class T>
void DLList<T>::remove(int index)
{
    Node<T> *behind = new Node<T>;
    Node<T> *ahead = new Node<T>;
    if (index < 0 || index > size - 1 || boundCheck(index) == false)
    {
        throw std::out_of_range("Cannot pop out of range.");
    }

    // when the position is after the tail
    if (index == size - 1)
    {
        delTail();
        return;
    }

    // when the position is before head
    if (index == 0)
    {
        delHead();
        return;
    }

    ahead = head;
    for (int i = 0; i < index; i++)
    {
        behind = ahead;
        ahead = ahead->next;
    }

    behind->next = ahead->next;
    ahead->next->prev = behind;

    delete ahead;
    size--;
};

template <class T>
void DLList<T>::pop()
{
    remove(size - 1);
};

template <class T>
int DLList<T>::getSize()
{
    return size; // since size attribute is private
};

template <class T>
bool DLList<T>::boundCheck(int index)
{
    Node<T> *iter = head; // checking if there is any gaps(NULL nodes)
    for (int i = 0; i < index; i++)
    {
        if (iter == NULL)
        {
            return false;
        }
        iter = iter->next;
    }
    return true;
};
#endif //! DLList_H
