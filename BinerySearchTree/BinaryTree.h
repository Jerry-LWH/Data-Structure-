#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "itemType.h"

using namespace std;


class BinaryTree {
 private:
    struct Node{
    itemType item;
    Node * left;
    Node * right;
    Node(itemType & item):item(item){}
  };

  Node* root;
  int length;
  Node * parent;
  Node * createNode(itemType & item);
  void deleteItemPrivate(Node *& BST ,itemType & item);
  void removeThisNode(Node*& BST);
  void predecessorPrivate(Node* BST, itemType&item);
  void insertPrivate(Node* rootNode, itemType & item);
  void retrievePrivate(Node *rootNode,itemType & item, bool & found) const;
  void preOrderPrivate(Node * rootNode)const;
  void inOrderPrivate(Node * rootNode)const;
  void postOrderPrivate(Node * rootNode)const;
  void destructor(Node *& rootNode);
 public:
  BinaryTree();
  ~BinaryTree();
  void insert(itemType & key);
  void deleteItem(itemType & key);
  void retrieve(itemType & item,bool & found) const;
  void preOrder() const;
  void inOrder() const;
  void postOrder() const;
  int getLength() const;


};

#endif
