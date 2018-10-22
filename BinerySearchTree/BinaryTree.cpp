#include "BinaryTree.h"
#include <iostream>
#include <cstddef>

using namespace std;

/**
Binary search tree is created
*/
BinaryTree::BinaryTree(){
  root = nullptr;
  length=0;
}

/**
Destructor to free alll the Nodes
*/
BinaryTree::~BinaryTree(){
  destructor(root);
}

/**
Helper method for destructor
*/
void BinaryTree::destructor(Node *& rootNode){  //must pass in the reference to ptr because it will delete the reference to ptr
  if(rootNode == nullptr){                      //in the parent node, so we dont need to modify the link part (set to nullptr manually)
    return;                                     //in parent when we delete a child node 
  }else{
    destructor(rootNode->left);
    destructor(rootNode->right);
    delete rootNode;                            //must delete rootNode last because if we do delete it earlier, when calling recursive 
  }                                             //function again there will be error because rootNode deleted
}

/**
Return the number of nodes in the tree
*/
int BinaryTree::getLength()const{
  return length;
}

/**
Printing out the tree in preOrder
*/
void BinaryTree::preOrder()const{
  if(length!=0){
    cout<<"Pre-Order: ";
    preOrderPrivate(root);
  }else{
    cout<<"The tree is empty"<<endl;
  }
}

/**
Helper method to Print out the tree in preOrder 
*/
void BinaryTree::preOrderPrivate(Node * rootNode)const{  //because we needed to pass in the rootNode as a started pointing  
  if(rootNode ==nullptr){                               
      return;
    }else{
      cout<<rootNode->item.getValue()<<" ";
      preOrderPrivate(rootNode->left);
      preOrderPrivate(rootNode->right);
    }
}

/**
Printing out the tree in inOrder
*/
void BinaryTree::inOrder()const{
  if(length!=0){
    cout<<"In-Order: ";
    inOrderPrivate(root);
  }else{
    cout<<"The tree is empty"<<endl;
  }
}

/**
Helper method of printing out the tree
*/
void BinaryTree::inOrderPrivate(Node * rootNode)const{
  if(rootNode ==nullptr){
      return;
    }else{
      inOrderPrivate(rootNode->left);
      cout<<rootNode->item.getValue()<<" ";
      inOrderPrivate(rootNode->right);
    }
}

/**
Printing out the tree in postOrder
*/
void BinaryTree::postOrder()const{
  if(length!=0){
    cout<<"Post-Order: ";
    postOrderPrivate(root);
  }else{
    cout<<"The tree is empty"<<endl;
  }
}

/**
Helper method for pringting out the tree in postOrder
*/
void BinaryTree::postOrderPrivate(Node * rootNode)const{
    if(rootNode==nullptr){
      return;
    }else{
      postOrderPrivate(rootNode->left);
      postOrderPrivate(rootNode->right);
      cout<<rootNode->item.getValue()<<" ";
    }
}

/**
Check if the tree contains a specific item
@param item the number to be searched
@param found the boolean flag, to be set to true if number found and false otherwise
*/
void BinaryTree::retrieve(itemType & item, bool & found)const{
  retrievePrivate(root,item,found);
}

/**
helper method to rerieve
*/
void BinaryTree::retrievePrivate(Node * rootNode, itemType & item, bool & found) const{ //again, we need this helper method because we need
  if(rootNode==nullptr){                                                                //to pass in the rootNode, and there is noway we
    found=false;                                                                        //can pass that in when call the function outside with the
    return;                                                                             //object
  }else if(rootNode->item.compareTo(item)==GREATER){
    retrievePrivate(rootNode->left,item,found);
  }else if(rootNode->item.compareTo(item)==LESS){
    retrievePrivate(rootNode->right,item,found);
  }else if(rootNode->item.compareTo(item)==EQUAL){
    item=rootNode->item;
    found=true;
    return;
  }
}

/**
Insert node into the tree
@param item the item object to be inserted
*/
void BinaryTree::insert(itemType & item){
    insertPrivate(root,item);
}

/**
Helper method for insert
*/
void BinaryTree::insertPrivate(Node * rootNode, itemType & item){
  if(root==nullptr){               //if tree is empty
    root=createNode(item);
  }else if(rootNode->item.compareTo(item)==LESS){   //if node is smaller than item
    if(rootNode->right != nullptr){                 //if node->right is not null
      insertPrivate(rootNode->right,item);          //recursive call
    }else{
      rootNode->right=createNode(item);            //else if node->right is null, createNode and assign 
    }
  }else if(rootNode -> item.compareTo(item)==GREATER){ //if node is greater
    if(rootNode -> left !=nullptr){                    //see above,just opposite
      insertPrivate(rootNode->left,item);
    }else{
      rootNode->left=createNode(item);
    }
  }else{                                           //if equal, do not insert
    cout<<"Number already exist"<<endl;
  }

}

/**
Creat a node
@param item the item for the node to be made
*/
BinaryTree::Node* BinaryTree::createNode(itemType& item){
  Node * myNode = new Node(item);
  myNode ->left =nullptr;
  myNode ->right=nullptr;
  length++;                            //whenever a new node is made, length++
  return myNode;
}


/**
Deletes a node from Tree
@param item the item to be deleted
*/
void BinaryTree::deleteItem(itemType & item){
  bool contain = false; 
  retrieve(item,contain);      
  if(contain==true){          //delete only if the tree contains the item(number)      
    deleteItemPrivate(root,item);
  }else{
    cout<<"This tree does not contain "<<item.getValue()<<endl;
  }
}

/**
Helper method for above
*/
void BinaryTree::deleteItemPrivate(Node *& BST, itemType & item){   //pass in the root and the targeted item
  if(BST->item.compareTo(item) == GREATER){                         //this method locates the targeted node and calls removeThisNode
    deleteItemPrivate(BST->left,item);                              //function and pass in the targeted node to be removed
  }else if(BST->item.compareTo(item)==LESS){
    deleteItemPrivate(BST->right,item);
  }else{
    removeThisNode(BST);
  }
}

/**
actually removes the targeted node 
 */
void BinaryTree::removeThisNode(Node*& BST){
  itemType value;
  Node * tempPtr;

  tempPtr=BST;
  if(BST->left == nullptr){            //if no left child
    BST = BST->right;                  
    delete tempPtr;
    length--;
  }else if(BST->right == nullptr){    //if no right child 
    BST = BST->left;                  //just make the BST equal its left child and delete itself which was store in tempPtr
    delete tempPtr;
    length--;
  }else{                              //if the node has two childre
    predecessorPrivate(BST->left,value);   //find the greatest in its left sub-tree and store its data in value
    BST->item  = value;                    //set the node's item to that value
    deleteItemPrivate(BST->left,value);    //and delete that greatest left node in the left-subtree
  }
}

/**
find the greatest of a tree and store its data into item
*/
void BinaryTree::predecessorPrivate(Node* BST, itemType&item){
  while(BST->right != nullptr){
    BST = BST->right;
  }
  item  = BST->item;
}


