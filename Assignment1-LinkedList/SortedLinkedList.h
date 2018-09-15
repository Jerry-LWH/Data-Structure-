#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

#include "ListNode.h"
#include "DataType.h"

class SortedLinkedList{
 private:
  int count;
  ListNode* head;

 public:
  SortedLinkedList();
  ~SortedLinkedList();
  int length() const;
  void insertItem(DataType & item);
  void deleteItem(DataType & item);
  int search(DataType & item);
  //Iterator getIterator();
  void clear();
  void pairwiseSwap();

  //tobe deleted
  void print();
  
};


#endif
