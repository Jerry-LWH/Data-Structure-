#include <cstddef>
#include <iostream>
#include "SortedLinkedList.h"

using namespace std;

/**
 *List created with zero ListNode
 */
SortedLinkedList::SortedLinkedList(){
  count = 0;
  head = NULL;
}

/**
 *Destruct the List and free all the memory  
 */
SortedLinkedList::~SortedLinkedList(){
  ListNode * temp;
  while(head != NULL){
    temp = head;
    head = head->Next;
    delete temp;
  }
  count = 0;
}

/**
 *return the length of the SortedLinkedList
 *@return int representing the number of ListNodes in the list
 */
int SortedLinkedList::length() const {
  return count;
}

/**
 *add a Node to the List in appropriete index based on its value
 *@param &item the Datatype used to comstruct the ListNode.
 */
void SortedLinkedList::insertItem(DataType & item){
  ListNode * myNode = new ListNode(item);
  myNode -> Next = NULL;
  if(count == 0){
    head = myNode;
    count++;
  }else{
    ListNode * prev = NULL;
    ListNode * curr = head;
    while(curr != NULL){   
      //if(curr -> item.getValue() > item.getValue()){
      if(curr -> item.compareTo(item) == GREATER){
	break;
      }
      prev = curr;
      curr = curr -> Next;
    }//while
    if(prev == NULL){
      head = myNode;
      myNode ->Next = curr;
    }else{
    prev ->Next = myNode;
    myNode ->Next =curr;
    }
    count++;
  }//if
}//insert  

/**
 *Delete an Node from the list
 *@param &item representing the ListNode that you want to delete
 */
void SortedLinkedList::deleteItem(DataType & item){
  if(count != 0){  //perform only when list isn't empty
    ListNode * prev = NULL;
    ListNode * curr = head;
    bool contain = false;
    while(curr != NULL){
      //if(curr -> item.getValue() == item.getValue()){
      if(curr -> item.compareTo(item)== EQUAL){
	contain = true;
	break;
      }
      prev = curr;
      curr = curr->Next;
    }//while
    if(contain){
      if(prev == NULL){   //deleting the first Node
	head = curr -> Next;
	delete curr;
      }else{
	prev -> Next = curr ->Next;
	delete curr;
      }
      count--;
    }
  }//if
}//delete

/**
 *empties the List and free the memory
 */
void SortedLinkedList::clear(){
  if(count != 0){
    ListNode * temp;
    while(head != NULL){
      temp = head;
      head = head->Next;
      delete temp;
    }
    count = 0;
    head=NULL;
  }//if
}//clear

/**
 *prints out the list  
 */
void SortedLinkedList::print(){
  ListNode * temp = head;
  while (temp != NULL){
    cout<< temp->item.getValue()  <<" ";
    temp = temp->Next;
  }
  cout<<"\n";
}

/**
 *return the index of the ListNode if found, -1 otherwise.
 *@param &item represent the ListNode that you want to search for
 */
int SortedLinkedList::search(DataType & item) {
  int index = -1;
  ListNode * temp = head;
  bool found = false;
  if(head == NULL){    
    return -1;
  }else{
    while(temp != NULL){
      index++;
      //if(temp->item.getValue()==item.getValue()){
      if(temp -> item.compareTo(item) ==EQUAL){	
	found = true;
	break;
      }
      temp = temp->Next;
    }//while
    if(found) return index;
    else return -1;
  }//if
}

/**
 *swap the adjusant ListNodes in the whole list
 */
void SortedLinkedList::pairwiseSwap(){
  if(count > 1){   //only perform if there are more than 2 nodes
    ListNode * tempHead = head;

    while(tempHead != NULL && tempHead -> Next != NULL){
      DataType tempData = tempHead ->item;
      tempHead->item = tempHead ->Next ->item;
      tempHead ->Next ->item = tempData;

      tempHead = tempHead ->Next ->Next; // increment over next two Nodes
    }//while
   
  }//if
}

