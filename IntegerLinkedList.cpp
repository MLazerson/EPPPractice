// ADD ANSWER TO THIS FILE

#include "IntegerLinkedList.h"
#include <iostream>
int IntegerLinkedList::getSum() {
  int sum = 0;
  while (head != nullptr) {
    //std::cout << head->elem << std::endl;
    sum = sum + head->elem;
    head = head->next;
  }
  return sum;
}

int IntegerLinkedList::getSumRecurse (SNode *ptr) {
  //return -1; // COMPLETE THIS FOR Problem3
  if ( ptr != nullptr ) {
        //std::cout << "hello" << std::endl;
        return ptr->elem + getSumRecurse(ptr->next);
  } else {
      return 0;
  }
}
void IntegerLinkedList::addFront(int x) {
  SNode *tmp = head;
	head = new SNode;
	head->next = tmp;
	head->elem = x;
}
// recursion helper function called from main for PROBLEM 3
int IntegerLinkedList::getSumRecurseHelper () {
  return getSumRecurse(head);
}
