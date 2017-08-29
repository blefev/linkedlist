#include "ll.h"

LL::LL()
{
	head = NULL;
}

bool LL::prepend(int num)
{
	node * newNode = new node;
	newNode->next = this->head;

	this->head = newNode;
}

bool LL::append(int num)
{
	node * newNode = new node;
	if(!newNode)
		return false;

	newNode->val = num;
	newNode->next = NULL;

	if(!this->head){
		this->head = newNode;
		return true;
	}

	node * nodePtr = this->head;


	while(nodePtr->next)
		nodePtr = nodePtr->next;

	nodePtr->next = makeNode(num, NULL);

	return true;
}

bool LL::remove(int num)
{
	// List empty?
	if(!head){
		
	}
}

bool LL::removeFront()
{

}


bool LL::removeBack()
{

}

node* LL::search(int num)
{

}

void LL::print()
{
	node * cur = this->head;
	while(cur){
		cout << cur->val << endl;
		cur = cur->next;
	}
}

int LL::getSize()
{
	node * nodePtr = this->head;

	int listSize = 0;

	while(nodePtr)
		listSize++;

	return listSize;
}

node* LL::makeNode(int val, node* nextNode)
{
	node* madeNode = new node;
	madeNode->val = val;
	madeNode->next = nextNode;
	return madeNode;
}
