#ifndef LISTNODE_H
#define LISTNODE_H

#include "DataType.h"



/**
 * A struct representing a Node in the SortedLinkedList
 */
struct ListNode{
  DataType item;
  ListNode * Next;
  explicit ListNode(DataType & item):item(item){}

};



#endif
