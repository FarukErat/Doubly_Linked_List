#include <iostream>

using namespace std;

typedef struct node
{
    int value;
    struct node *next;
    struct node *previous;
} Node;

typedef struct list
{
    int memberNumber;
    Node *firstNode;
    Node *lastNode;
} List;

enum howToPrint
{
    FORWARD = false,
    BACKWARD = true
};

class doubly_linked
{
public:
    List list;
    doubly_linked();
    ~doubly_linked();
    void printMenu();
    void append(int newElement);
    void pop(int index);
    void printList(bool isBackward = FORWARD);
};

int main()
{
    int value;
    unsigned int choice, index;
    doubly_linked l;

    cout << "----------" << endl
         << "  [Menu]   " << endl
         << "----------";

    while (true)
    {
        l.printMenu();
        cin >> choice;
        switch (choice)
        {
        case 0:
            return 0;
        case 1:
            cout << "Enter a number to append: ";
            cin >> value;
            l.append(value);
            break;
        case 2:
            cout << "Enter the index to pop an element: ";
            cin >> index;
            l.pop(index);
            break;
        case 3:
            l.printList(FORWARD);
            break;
        case 4:
            l.printList(BACKWARD);
            break;
        default:
            cout << "Invalid choice!" << endl
                 << "Enter a valid one";
            break;
        }
    }

    return EXIT_SUCCESS;
}

doubly_linked::doubly_linked()
{
    this->list.firstNode = new Node;
    this->list.firstNode->previous = NULL;
    this->list.firstNode->next = NULL;
    this->list.lastNode = this->list.firstNode;
    this->list.memberNumber = 0;
}

doubly_linked::~doubly_linked()
{
    Node *ptr = this->list.firstNode;
    Node *nodeToRemove;

    while (ptr->next != NULL)
    {
        nodeToRemove = ptr;
        ptr = ptr->next;
        delete nodeToRemove;
    }
    delete ptr;
    cout << endl
         << "The program exitted";
}

void doubly_linked::printMenu()
{
    cout << endl
         << endl
         << "1. add a value" << endl
         << "2. remove a value" << endl
         << "3. print the list forward" << endl
         << "4. print the list backward" << endl
         << "0. EXIT" << endl
         << "Enter your choice: ";
}

void doubly_linked::append(int newElement)
{
    if (this->list.memberNumber == 0)
    {
        this->list.firstNode->value = newElement;
        this->list.memberNumber++;
        return;
    }

    Node *newNode = new Node;
    newNode->value = newElement;

    this->list.lastNode->next = newNode;
    newNode->previous = this->list.lastNode;
    this->list.lastNode = newNode;
    this->list.lastNode->next = NULL;
    this->list.memberNumber++;
}

void doubly_linked::pop(int index)
{

    if (this->list.memberNumber == 0 || index > this->list.memberNumber)
    {
        cout << "Invalid value!";
        return;
    }

    if (this->list.memberNumber == 1)
    {
        this->list.memberNumber--;
        cout << "The number has been removed";
        return;
    }

    Node *ptr = NULL;

    if (index == 1)
    {
        ptr = this->list.firstNode;
        this->list.firstNode = this->list.firstNode->next;
        this->list.firstNode->previous = NULL;
        this->list.memberNumber--;
        delete ptr;
        return;
    }

    if (index == this->list.memberNumber)
    {
        ptr = this->list.lastNode;
        this->list.lastNode = this->list.lastNode->previous;
        this->list.lastNode->next = NULL;
        this->list.memberNumber--;
        delete ptr;
        return;
    }

    int i = 1;
    ptr = this->list.firstNode;
    while (i < index - 1 && ptr->next != NULL)
    {
        ptr = ptr->next;
        i++;
    }

    Node *nodeToRemove = ptr->next;
    nodeToRemove->previous->next = nodeToRemove->next;
    nodeToRemove->next->previous = nodeToRemove->previous;
    delete nodeToRemove;
    this->list.memberNumber--;
    cout << endl
         << "The number has been removed";
}

void doubly_linked::printList(bool isBackward)
{
    if (this->list.memberNumber == 0)
    {
        cout << "The list is empty!";
        return;
    }

    Node *ptr;
    if (isBackward)
    {
        ptr = this->list.lastNode;
        cout << ptr->value << endl;
        while (ptr->previous != NULL)
        {
            ptr = ptr->previous;
            cout << ptr->value << endl;
        }
    }
    else
    {
        ptr = this->list.firstNode;
        cout << ptr->value << endl;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
            cout << ptr->value << endl;
        }
    }
}
