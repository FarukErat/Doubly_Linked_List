#pragma once
#ifndef DLL_H
#define DLL_H

template <class Anytype>
struct node
{
	Anytype data;		 // data to be stored
	node<Anytype> *next; // the pointer pointing the next node
	node<Anytype> *prev; // the pointer pointing the previous node
};

template <class Anytype>
class DLList
{
private:
	node<Anytype> *head; // the address of the first node
	node<Anytype> *tail; // the address of the last node
	int sizeOfList = 0;

public:
	DLList();
	~DLList();
	void append(Anytype data);
	void insert(Anytype pos, Anytype data);
	void addHead(Anytype data);
	void addTail(Anytype data);
	void change(Anytype pos, Anytype data);
	void delHead();
	void delTail();
	void pop(Anytype Pos);
	int size();
	bool isEmpty();
	bool BoundCheck(Anytype pos);
	void Display();
	void RevDisplay();
};

template <class Anytype>
DLList<Anytype>::DLList()
{
	head = nullptr;
	tail = nullptr;
};

template <class Anytype>
DLList<Anytype>::~DLList()
{
	if (head == nullptr)
	{
		delete head;
		std::cout << "List has been destroyed." << std::endl;
		return;
	}

	node<Anytype> *ptr = new node<Anytype>;
	node<Anytype> *nodeToRemove = new node<Anytype>;
	ptr = head;
	while (ptr->next != nullptr)
	{
		nodeToRemove = ptr;
		ptr = ptr->next;
		delete nodeToRemove;
	}
	delete ptr;
	std::cout << "List has been destroyed." << std::endl;
};

template <class Anytype>
void DLList<Anytype>::append(Anytype data)
{
	// temp node is created and initialized
	node<Anytype> *temp = new node<Anytype>;
	node<Anytype> *curr = new node<Anytype>;
	temp->data = data;
	temp->next = nullptr;
	temp->prev = nullptr;
	// if the list is not empty
	if (head != nullptr)
	{
		curr = head;
		// iterating curr node to the end of the list
		while (curr->next != nullptr)
		{
			curr = curr->next;
		}
		// when it is in the end
		// its next node is assigned as temp
		curr->next = temp;
		// temp's previous node is assigned as curr
		temp->prev = curr;
		// tail node is updated
		tail = temp;
	}
	// if list is empty
	else
	{
		// in this case head and tail nodes are the same node and temp
		head = temp;
		tail = temp;
	}
	sizeOfList++;
};

template <class Anytype>
void DLList<Anytype>::insert(Anytype pos, Anytype data)
{
	node<Anytype> *temp = new node<Anytype>;
	node<Anytype> *ahead = new node<Anytype>;
	node<Anytype> *behind = new node<Anytype>;
	// if the position is out range
	if (BoundCheck(pos) == false)
	{
		std::cout << "Cant add from out of range." << std::endl;
		return;
	}
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
	// a new node is created
	node<Anytype> *temp = new node<Anytype>;
	// its data is assigned
	temp->data = data;
	// the previous node of temp is assigned as tail
	temp->prev = tail;
	// the next node of former tail node is assigned as temp
	tail->next = temp;
	// the next node of temp node is assigned as nullptr
	temp->next = nullptr;
	// tail node is updated
	tail = temp;
	sizeOfList++;
}

template <class Anytype>
void DLList<Anytype>::change(Anytype pos, Anytype data)
{
	node<Anytype> *curr = head;
	// iterating to the position
	for (int x = 0; x < pos; x++)
	{
		curr = curr->next;
	}
	// changing the data
	curr->data = data;
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
		// head is moved one node further
		temp = head->next;
		temp->prev = nullptr;
		delete head;
		// head is updated to temp
		head = temp;
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
		// tail is moved one node back
		temp = tail->prev;
		temp->next = nullptr;
		delete tail;
		// tail is updated to temp
		tail = temp;
		sizeOfList--;
	}
}

template <class Anytype>
void DLList<Anytype>::pop(Anytype pos)
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
int DLList<Anytype>::size()
{
	// since size attribute is private
	return sizeOfList;
};

template <class Anytype>
void DLList<Anytype>::Display()
{
	node<Anytype> *curr = head;
	// curr is itearated and printed
	while (curr != nullptr)
	{
		std::cout << curr->data << " ";
		curr = curr->next;
	}
};

template <class Anytype>
void DLList<Anytype>::RevDisplay()
{
	node<Anytype> *curr = tail;
	// curr is itearated and printed
	while (curr != nullptr)
	{
		std::cout << curr->data << " ";
		curr = curr->prev;
	}
};

template <class Anytype>
bool DLList<Anytype>::BoundCheck(Anytype pos)
{
	// checking if there is any gaps(NULL nodes)
	node<Anytype> *now = head;
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

#endif //! DLL_H
