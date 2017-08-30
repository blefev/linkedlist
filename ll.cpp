#include "ll.h"

LL::LL()
{
	head = NULL;
}

void LL::prepend(int num)
{
	node * newNode = new node;
	newNode->next = this->head;

	this->head = newNode;
}

void LL::append(int num)
{
	node** dblNodePtr = &(this->head);

	while(*dblNodePtr)
		dblNodePtr = &(*dblNodePtr)->next;

	*dblNodePtr = makeNode(num, NULL);
}

bool LL::remove(int num)
{
	node** dblNodePtr = &(this->head);

	while(*dblNodePtr && (**dblNodePtr).val != num)
		dblNodePtr = &(*dblNodePtr)->next;

	if(*dblNodePtr){
		node *toRemove = *dblNodePtr;
		*dblNodePtr = toRemove->next;
		delete toRemove;
		return true;
	}
	return false;
}

bool LL::removeFront()
{

}


bool LL::removeBack()
{

}

node* LL::search(int num)
{
	node** dblNodePtr = &(this->head);

	while(*dblNodePtr && (*dblNodePtr)->val != num)
		dblNodePtr = &(*dblNodePtr)->next;

	return *dblNodePtr;
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

node* LL::makeNode(int val, node* nextNode = NULL)
{
	node* madeNode = new node;
	madeNode->val = val;
	madeNode->next = nextNode;
	return madeNode;
}
