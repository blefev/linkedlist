#ifndef LL_H
#define LL_H

// include this library to use NULL, otherwise use nullptr instead
#include <cstddef>

// include iostream so anything that includes this file can use cout
#include <iostream>

using namespace std;

// Struct which will be the building block of our list
struct node{
	int val;
	node* next;
};

// Linked list class definition
class LL{
public:
	LL();
	void prepend(int);
	void append(int);
    bool remove(int);
	bool removeFront();
	bool removeBack();
	node* search(int);
	void print();
	int getSize();
private:
	node* head;
	node* makeNode(int, node*);
	node ** traverseTo(int);
};

#endif
