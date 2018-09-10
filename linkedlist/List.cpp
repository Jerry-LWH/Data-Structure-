#include <cstdlib>
#include <iostream>

#include "List.h"

using namespace std;

List::List(){
  head = NULL;
  curr = NULL;
  temp = NULL;
  length = 0;
}

void List::AddNode(int addData){
  length++;             
  node* aNode = new node;                       //create a new Node
  aNode -> link = NULL;
  aNode -> data = addData;
  
  if(head !=NULL){                             //if we already have a list
    curr = head;
    while(curr -> link != NULL){
      curr = curr -> link;
    }//while
    curr -> link = aNode;
  }//if
  else{                                     //if adding to a empty list
    head = aNode;
  }
}//addNode

bool List::AddAtIndex(int index, int addData){
  if(index>=length){                 //check if index out of bound
    return false;
  }else if(index ==length-1){       // if index happen to be the last index in the list, utilize the AddNode(addData) 
    AddNode(addData);
    return true;
  }else{                            //else create a new node and 
    length++;
    node* aNode = new node();   
    aNode->data = addData;
    curr = head;
    if(index==0){                   //check if adding to the first index because that involes the head ptr
      head = aNode;
      aNode->link = curr;
    }else{
      for(int i = 0; i < index; i++){   //do regular adding for all middle index
	temp = curr;
	curr = curr-> link;
      }
      temp -> link = aNode;
      aNode -> link = curr;
    }
    return true;
  }//else  
}//addatIndex

void List::DeleteNode(){
  if(length != 0){                   // check if its empty list
    curr = head;
    while(curr -> link != NULL){    
      temp = curr;
      curr = curr->link;
    }
    if(length == 1){                 //delete this way is the length is == 1 because involve ptr
      head = NULL;
      delete curr;
    }else{                           //delete other way is length > 1 
      temp -> link = NULL;
      delete curr;
    }
    length--;
  }
}

void List::DeleteAtIndex(int index){
  if(index > length -1){              //check if index out of bound
    cout<<"index out of bound"<<endl;
  }else if(index == length-1){        //check if index is last elemenet because we could utilize DeleteNode();   
    DeleteNode();
  }else if(index == 0){               //delete this way is index == 0 because involve head ptr
    curr = head;
    head = head -> link;
    delete curr;
    length--;
  }else{                             //delete other way for all middle index
    curr = head;
    for(int i = 0; i < index; i++){
      temp = curr;
      curr = curr -> link;
    }
    temp -> link = curr -> link;
    delete curr;
    length--;
  }
 }


void List::DeleteNode(int delData){
  node* delPtr = NULL;
  temp = head;
  curr = head;
  
  while (curr != NULL && curr -> data != delData){  
    temp = curr;
    curr = curr -> link;
  }//while
  
  if(curr == NULL){
    cout<< delData <<"was not in the list\n";
    delete delPtr;
  }else{
    length--;
    delPtr = curr;
    curr = curr -> link;
    temp -> link = curr;
    delete delPtr;
    cout<<"The value " << delData << "was deleted\n";
  }
}//DeleteNode

void List::PrintList(){
  curr = head;
  while(curr != NULL){
    cout<<curr->data<<endl;
    curr = curr -> link;
  }

}
