#include <iostream>
#include "LinkedList.h"

int main()
{

    // Create new double linked list object
    Linkedlist* list = new Linkedlist();

    // Add random numbers to each node
    list->pushBack(8);
    list->pushFront(45);
    list->pushBack(97);
    list->pushBack(13);
    list->pushBack(86);

    // pop front node
    list->popFront();

    // Add two identical values to the front and back
    list->pushBack(52);
    list->pushFront(52);

    // Show new unsorted list
    list->Display();

    // Sort current list
    list->Sort();

    // Show sorted list
    list->Display();

    // remove value from index 1
    list->Remove(1);

    // Display final list
    list->Display();

    
}
