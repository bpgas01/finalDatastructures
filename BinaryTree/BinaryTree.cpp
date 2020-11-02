/*----------------------------------------
Author: Richard Stern
Description: A simple binary search tree
Date: 17/4/2015
----------------------------------------*/
#include "BinaryTree.h"
#include "TreeNode.h"
#include "raylib.h"
#include <iostream>
#include <cstdlib>

using namespace std;


BinaryTree::BinaryTree()
{
    m_pRoot = nullptr;
}

BinaryTree::~BinaryTree()
{
	while(m_pRoot)
	{
		Remove(m_pRoot->GetData());
	}
}

// Return whether the tree is empty
bool BinaryTree::IsEmpty() const 
{ 
	return (m_pRoot == nullptr);
}

// Insert a new element into the tree.
// Smaller elements are placed to the left, larger onces are placed to the right.
void order(TreeNode* Temp) {
	if (!Temp) {
		return;
	}

	order(Temp->GetLeft());
	order(Temp->GetRight());
}

TreeNode* newNode(int data) {
	TreeNode* temp = new TreeNode(data);

	temp->SetLeft(NULL);
	temp->SetRight(NULL);

	return temp;
}

void BinaryTree::Insert(int a_nValue)
{
	// Create new node
	TreeNode* node = new TreeNode(a_nValue);

	// Check to see if binary tree is empty
	if (IsEmpty())
	{
		m_pRoot = node;
		return;
	}
	// Set current and parent nodes to the root node
	TreeNode* current = m_pRoot;

	TreeNode* parent = m_pRoot;

	// Read tree data
	while (current != nullptr)
	{
		// Do nothing if input value is the same as current node data to avoid duplicate errors
		if (current->GetData() == a_nValue) {
			return;
		}
		
		// If value is smaller, read to the left
		else if (current->GetData() > a_nValue)
		{
			
			if (current->GetLeft() == nullptr) {
				parent = current; // Update parent 
			}
			current = current->GetLeft(); // Update current node
		}
		// If Value is larger, read to the right
		else if (current->GetData() < a_nValue)
		{
			if (current->GetRight() == nullptr) {
				parent = current; // Update parent
			}
			current = current->GetRight(); // Update current node
		}
	}
	// If Value is less than than the data at the parent node, Set the child node to the left
	if (a_nValue < parent->GetData()) {
		parent->SetLeft(node);
	}
	// If greater, set to the right
	else {

		parent->SetRight(node);
	}
}

TreeNode* BinaryTree::Find(int a_nValue)
{
	TreeNode* pCurrent = nullptr;
	TreeNode* pParent = nullptr;

	return FindNode(a_nValue, pCurrent, pParent) ? pCurrent : nullptr;
}

bool BinaryTree::FindNode(int a_nSearchValue, TreeNode*& ppOutNode, TreeNode*& ppOutParent)
{
	ppOutNode = m_pRoot;

	while (ppOutNode != nullptr) {
		if (a_nSearchValue = ppOutNode->GetData()) {
			return ppOutNode || ppOutParent;
		}
		else {
			if (a_nSearchValue < ppOutNode->GetData()) {
				ppOutParent->SetLeft(ppOutNode);
			}
			else {
				ppOutParent->SetRight(ppOutNode);
			}
		}
	}

	return false;
}

void BinaryTree::Remove(int a_nValue)
{
	TreeNode* current = m_pRoot;
	TreeNode* previous = NULL;

	// Check for existence of value within the binary tree
	while (current != NULL && current->GetData() != a_nValue) {

		previous = current;

		if (a_nValue < current->GetData()) {
			current = current->GetLeft();
		}
		else {
			current = current->GetRight();
		}

		// If value is not found
		if (current == NULL) {
			return;
		}
	}

	// Check for children
	if (current->GetLeft() == NULL || current->GetRight() == NULL) {

		// Create new node to replace removed node
		TreeNode* temp;

		// Check if children exist
		if (current->GetLeft() == NULL) {
			temp = current->GetRight();
		}
		else {
			temp = current->GetLeft();
		}

		// If node is root, return here (nothing is deleted)
		if (previous == NULL) {
			return;
		}

		// check if node to be deleted if the child of previous
		if (current == previous->GetLeft()) {
			previous->SetLeft(temp); // Replace Node with temp
		}
		else {
			previous->SetRight(temp); // Replace Node with temp
		}

		free(current); // Free memory of deleted node
	}
	else {
		// Create new parent and temp nodes
		TreeNode* parent = NULL;
		TreeNode* temp;

		// Figure out the order of the nodes
		temp = current->GetRight();
		while (temp->GetLeft() != NULL) {
			parent = temp;
			temp = temp->GetLeft();
		}

		// Set the children of the new node 
		if (parent != NULL) {
			parent->SetLeft(temp->GetRight());
		}
		else {
			current->SetRight(temp->GetRight());
		}
		current->SetData(temp->GetData());

		free(temp); // Free the memory of the temp node

	}
	return;

}


void BinaryTree::PrintOrdered()
{
	PrintOrderedRecurse(m_pRoot);
	cout << endl;
}

void BinaryTree::PrintOrderedRecurse(TreeNode* pNode)
{

}

void BinaryTree::PrintUnordered()
{
    PrintUnorderedRecurse(m_pRoot);
	cout << endl;
}

void BinaryTree::PrintUnorderedRecurse(TreeNode* pNode)
{

}

void BinaryTree::Draw(TreeNode* selected)
{
	Draw(m_pRoot, 400, 40, 400, selected);
}

void BinaryTree::Draw(TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{
	
	horizontalSpacing /= 2;

	if (pNode)
	{
		if (pNode->HasLeft())
		{
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
			
			Draw(pNode->GetLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		if (pNode->HasRight())
		{
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);

			Draw(pNode->GetRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		pNode->Draw(x, y, (selected == pNode));
	}
}