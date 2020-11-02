// Hash Tables.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "hashtables.h"


int main()
{
    hashtables table(100);

    table.insert(1, 'e');
    table.insert(2, '3');
    table.insert(3, 'r');
    table.insert(4, 'g');


    std::cout << table.search(2) << " : key 2" << std::endl;
    std::cout << table.search(1) << " : key 1" << std::endl;

    if (table.Remove(2)) {
        std::cout << "Element at key 2 deleted" << std::endl;
    }
    else {
        std::cout << "Error" << std::endl;
    }

    std::cout << table.search(2) << " : Key 2 was deleted. So this should result as nothing " << std::endl;


    

}

