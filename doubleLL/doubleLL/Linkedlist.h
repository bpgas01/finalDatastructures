#pragma once

class Linkedlist
{
private:


	struct Node
	{
		int value;

		Node* next;

		Node* prev;


	};

	Node* m_first;
	Node* m_last;

	// Grab node at specfic index
	Node* m_Reach(int index);

	// swap index of two nodes (for sort function)
	void m_Swap(Node* val, Node* val2);

	// Keeps track of length of list
	int count;

public:

	
	// Create new empty list
	Linkedlist();

	// Class decontructor
	~Linkedlist();

	// Return value of last node
	int Back();

	// Return value of first node
	int Front();

	// Add new node at back of list 
	void pushBack(int value);

	// Add new node at start of list
	void pushFront(int value);

	// Sort the list
	void Sort();
	
	// "Pop" last node off the end of the list
	void pop();

	// Pop first value off the list
	void popFront();

	// Insert new value at a specific index
	void Insert(int key, int value);

	// Remove node at specific index
	void Remove(int key);

	// Display current node list
	void Display();
	

};

