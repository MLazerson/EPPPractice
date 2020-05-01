#pragma once

class SNode {
public:
  int elem;
  SNode *next;
};
class IntegerLinkedList {
private:
  SNode *head;
  int getSumRecurse (SNode *ptr); // for Problem 3
public:
  IntegerLinkedList(): head(nullptr) {}
  void addFront(int x);

  int getSum(); /*; // for Problem 2 */

  // recursion helper function called from main for PROBLEM 3
  int getSumRecurseHelper ();
};
