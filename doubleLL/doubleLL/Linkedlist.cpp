#include <iostream>
#include "LinkedList.h"

Linkedlist::Linkedlist() // Create empty list

{
	count = 0;
	m_first = nullptr;
	m_last = nullptr;
}

Linkedlist::~Linkedlist()
{
	

	delete m_first;
	delete m_last;
} 


Linkedlist::Node* Linkedlist::m_Reach(int index)
{
	if (count > 0)
	{
		int i = 0;
		Node* temp = m_first;

		while (temp != nullptr)
		{
			if (i == index)
			{
				return temp;
			}

			temp = temp->next;
			i++;
		}
	}

	return nullptr;
}

int Linkedlist::Front()

{
	if (m_first == nullptr)
		return 0;

	return m_first->value;
}

int Linkedlist::Back()

{
	if (m_last == nullptr)
		return 0;

	return m_last->value;
}

void Linkedlist::pop() 
{
	Node* newnode = m_last->prev;
	newnode->next = nullptr;

	delete m_last;

	m_last = newnode;
}
void Linkedlist::popFront()
{
	Node* newnode = m_first->next;
	newnode->prev = nullptr;

	delete m_first;

	m_first = newnode;
} 
void Linkedlist::Sort()
{
	
	for (int i = 0; i < count; i++) {

		for (int x = 0; x < count - i; x++) {

			if (m_Reach(x)->value > m_Reach(x + 1)->value){

				m_Swap(m_Reach(x), m_Reach(x + 1));

			}
		}
	}

} // Sort the list

void Linkedlist::m_Swap(Node* val, Node* val2)
{
	// If either value is a nullptr (empty) return (exit)
	if (val == nullptr || val2 == nullptr) {

		return;
	}

	if (m_last == val) {

		m_last = val2;
	}
	else if (m_last == val2) {

		m_last = val;
	}

	if (m_first == val) {

		m_first = val2;

	}
	else if (m_first == val2) {
		m_first = val;

	}

	Node* prevNode = val->prev;
	Node* nextNode = val2->next;

	if (prevNode != nullptr) {

		prevNode->next = val2;

	}

	val->prev = val2;
	val->next = nextNode;

	if (nextNode != nullptr) {

		nextNode->prev = val;

	}
	val2->next = val;
	val2->prev = prevNode;
}


void Linkedlist::Insert(int key, int value) 
{
	if (key > count) {

		pushBack(value);

	}
	else if (key <= 1) {

		pushFront(value);

	}
	else
	{
		Node* tempNode = m_Reach(key);
		Node* newNode = new Node();

		newNode->value = value;
		newNode->next = tempNode;
		newNode->prev = tempNode->prev;

		if (tempNode->prev != nullptr) {

			tempNode->prev->next = newNode;

		}

		tempNode->prev = newNode;

		count++;
	}
}
void Linkedlist::Remove(int key)
{
	Node* tempNode = m_Reach(key);

	Node* prev = tempNode->prev;
	Node* next = tempNode->next;

	if (prev != nullptr)
	{

		prev->next = next;
		prev->prev = prev;

	}

	if (next != nullptr)
	{

		next->prev = prev;

	}

	count--;

	delete tempNode;
}

void Linkedlist::pushBack(int value)
{
	Node* newnode = new Node();

	newnode->value = value;

	newnode->next = nullptr;

	newnode->prev = nullptr;

	if (count != 0)
	{

		newnode->prev = m_last;
		m_last->next = newnode;

		m_last = newnode;

	}
	else
	{

		m_first = newnode;

		m_last = newnode;

	}

	count++;
}
void Linkedlist::pushFront(int value)
{
	Node* newNode = new Node();

	newNode->value = value;
	newNode->next = m_first;
	newNode->prev = nullptr;

	m_first->prev = newNode;
	m_first = newNode;
}

void Linkedlist::Display()
{
	std::cout << "------------" << std::endl;
	for (int i = 0; i <= count; i++)
	{
		Node* node = m_Reach(i);

		if (node == nullptr) {

			std::cout << i << " == NULL" << std::endl;

		}
		else {

			std::cout << i << " == " << node->value << std::endl;

		}
	}
}


