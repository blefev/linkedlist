#include "ll.h"
/*
 * Linked List Implementation
 * @author Brendan Lefevre brendan.lefevre@mines.sdsmt.edu
 *
 * This linked list implementation uses double pointers to traverse
 * the list. The advantage of this is that the double pointer can
 * _point_ to the next pointer of a node, instead of simply
 * pointing to the node that next points to. This eliminates edge
 * cases and allows for ultimately more concise and functional code.
 * Instead of keeping track of a current and previous node, the program
 * only needs the double pointer.
 *
 * Deletes work by taking the dereferenced pointer (equivalent to next)
 * and deleting it's pointed-to node. Because we still have the pointer to the
 * node, we simply move it to the node after the one we delete (before we delete
 * it). The function deleteFromPointer() performs this operation.
 */
LL::LL() { this->head = NULL; }

LL::~LL() { this->deleteList(); }

void LL::deleteList() {
  while (this->head) {
    node *toDelete = this->head;
    this->head = this->head->next;
    delete toDelete;
  }
}

void LL::prepend(int num) { this->head = makeNode(num, this->head); }

void LL::append(int num) {
  node **dblNodePtr = &(this->head);

  while (*dblNodePtr)
    dblNodePtr = &(*dblNodePtr)->next;

  *dblNodePtr = makeNode(num, NULL);
}

bool LL::remove(int num) {
  node **dblNodePtr = &(this->head);

  while (*dblNodePtr && (**dblNodePtr).val != num)
    dblNodePtr = &(*dblNodePtr)->next;

  return deleteFromPtr(dblNodePtr);
}

bool LL::removeFront() {
  if (!this->head)
    return false;

  node *toShift = this->head->next;
  delete this->head;
  this->head = toShift;

  return true;
}

bool LL::removeBack() {
  if (!this->head)
    return false;

  node **dblNodePtr = &(this->head);

  while ((*dblNodePtr)->next)
    dblNodePtr = &(*dblNodePtr)->next;

  return deleteFromPtr(dblNodePtr);
}

node *LL::search(int num) {
  node *nodePtr = this->head;

  while (nodePtr && nodePtr->val != num)
    nodePtr = nodePtr->next;

  return nodePtr;
}

void LL::print() {
  node *cur = this->head;
  while (cur) {
    cout << cur->val << " -> ";
    cur = cur->next;
  }
  cout << "NULL" << endl;
}

int LL::getSize() {
  node *nodePtr = this->head;

  int listSize = 0;

  while (nodePtr) {
    listSize++;
    nodePtr = nodePtr->next;
  }

  return listSize;
}

node *LL::makeNode(int val, node *nextNode = NULL) {
  node *madeNode = new node;
  madeNode->val = val;
  madeNode->next = nextNode;
  return madeNode;
}

bool LL::deleteFromPtr(node **dblNodePtr) {
  if (!*dblNodePtr)
    return false;

  node *toRemove = *dblNodePtr;
  *dblNodePtr = toRemove->next;
  delete toRemove;
  return true;
}
