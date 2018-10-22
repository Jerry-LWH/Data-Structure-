#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<limits>
#include"BinaryTree.h"

using namespace std;



/*******print next interator && reset iterator****/

int getNumber(char a){
  string myString ="";
  if(a == 'i'){
    myString = "Enter a number: ";
  }else if (a == 'd'){
    myString = "Enter value to delete: ";
  }else if(a == 'r'){
    myString = "Enter a value to retrieve: ";
  } 
  cout<<myString;

  int x;
   cin >> x;
   while(cin.fail())
     {
       cin.clear();
       cin.ignore(numeric_limits<streamsize>::max(),'\n');
       cout << "Invalid input." << endl << myString;
       cin >> x;
     }
   return x;
}



int main(int argc, char* argv[]){
  fstream fileStream;
  BinaryTree myTree;
  int element;
  string command;
  bool prompt = true;
  
  // open file and put all the variable in the linkedList
  fileStream.open(argv[1],ifstream::in);
  if(fileStream.is_open()){
    fileStream >> element;
    while(!fileStream.eof()){
     itemType data = itemType(element);
     myTree.insert(data);
     fileStream >> element;
    }
  }
  else{
    cout << "Error opening file. " <<
      "Try again." << endl;
    return 0;
  }

  
  //promt
  cout<<"Commands: "<<endl;
  cout<<"(i) - Insert value \n" << "(d) - Delete value \n" <<"(r) - Retrieve \n";
  cout<< "(o) - Post-order\n" << "(l) - length\n" << "(n) - In-Order\n";
  cout<<"(p) - Pre-Order\n" << "(q) - Quit program\n";
  
  while(prompt){
    cout << "Enter a command: ";
    cin >> command;
    
    if(command == "q" || command == "Q"){
      prompt = false;
      cout<<"Quitting program..."<<endl;
    }else if(command =="i" || command =="I"){
      element = getNumber('i');
      itemType mydata = itemType(element);
      myTree.insert(mydata);
      myTree.inOrder();
      cout<<endl;
    }else if(command == "d" || command == "D"){
      if(myTree.getLength()==0){
	cout<<"The tree is empty."<<endl;
      }else{
       	element = getNumber('d');
	itemType mydata = itemType(element);
	myTree.deleteItem(mydata);
	myTree.inOrder();
	cout<<endl;
      }
    }else if(command == "r" || command == "R"){
      element = getNumber('r');
      itemType mydata = itemType(element);
      bool contain;
      myTree.retrieve(mydata,contain);
      if(contain) cout<<"Item found in tree."<<endl;
      else cout<<"Item not found in tree."<<endl;
    }else if(command == "p" || command == "P"){
      myTree.preOrder();
      cout<<endl;
    }else if(command == "l"|| command =="L"){
      cout<<"List length is "<<myTree.getLength()<<endl;
    }else if(command == "o" || command == "O"){
      myTree.postOrder();
      cout<<endl;
    }else if (command == "n" || command == "N"){
      myTree.inOrder();
      cout<<endl;
    }else{
      cout<<"Command not recognized. Try again"<<endl;
    }

  }//while

  return 0;
}



