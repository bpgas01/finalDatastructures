#pragma once
#include <iostream>

class hashtables
{

public:

	struct entry {
		int key;
		char value;
		bool inUse = false;
	};

	// Default table size
	int size = 50;

	// Create empty pointer for hashtable
	entry* hashtable = nullptr;

	// Custom hashfunction 
	int hashFunction(int key) {
		return key % size + (93 / 3);
	}

	// Insert new char value
	void insert(int key, char value) {
		// create new header via the key
		int header = hashFunction(key); 
		// Create empty hashtable entry
		entry addnew;
		// check for inuse entries
		if (hashtable[header].inUse) {
			// Find the next unused entry 
			while (!hashtable[header].inUse) {
				// Increment header size until empty slot is found
				header++;
				// if header exceeds max size do nothing
				if (header > size) {
					return;
				}
			}
		}
		// Set new entry values
		addnew.key = key;
		addnew.value = value;
		// Insert new hashtable entry
		hashtable[header] = addnew;
	}

	// Search for char value with hashkey
	char search(int key) {
		// create table header based on key
		int header = hashFunction(key);

		// Check for entries that are in use and loop through
		if (hashtable[header].inUse && (hashtable[header].key != key)) {
			while (hashtable[header].inUse && (hashtable[header].key == key)) {
				header++;

				// if loop goes into unallocated areas return nothing
				if (header > size) {
					return hashtable[0].value;
				}
			}
		}
		// Return table value when found
		return hashtable[header].value;
	}

	// Remove a value with key - returns bool based on if the value is removed or not
	bool Remove(int key) {
		// Create header with key
		int header = hashFunction(key);
		// Find entry via header + key
		if (hashtable[header].key == key) {
			// Set allocated state to unallocated 
			hashtable[header].inUse = false;
			// return success state
			return true;
		}
		// return failed state
		return false;
	}

	// Class constructor override - Set custom size
	hashtables(int _size) {
		size = _size;
		hashtable = new entry[size];
	}

	// Create new hashtable object
	hashtables() {

		hashtable = new entry[size];
	}

	~hashtables() {
	}



};

