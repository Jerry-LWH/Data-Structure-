#include <cstdlib>
#include<iostream>
#include "List.h"

using namespace std;

int main(){
  List aList;
  
  aList.AddAtIndex(0,2);
  aList.AddNode(3);
  aList.AddNode(4);
  aList.DeleteNode();
  aList.DeleteAtIndex(0);
  aList.AddNode(3);
  aList.AddNode(4);
  aList.DeleteAtIndex(1);
    aList.DeleteAtIndex(0);
  aList.PrintList();
}
