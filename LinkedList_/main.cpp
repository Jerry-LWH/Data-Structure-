#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<limits>
#include"SortedLinkedList.h"

using namespace std;



/*******print next interator && reset iterator****/

int getNumber(char a){
  string myString ="";
  if(a == 'i'){
    myString = "Enter a number: ";
  }else if (a == 'd'){
    myString = "Enter value to delete: ";
  }else if(a == 's'){
    myString = "Enter a value to search: ";
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
  SortedLinkedList myList;
  int element;
  string command;
  bool prompt = true;
  //DataType data;

  // open file and put all the variable in the linkedList
  fileStream.open(argv[1],ifstream::in);
  if(fileStream.is_open()){
    fileStream >> element;
    while(!fileStream.eof()){
     DataType data = DataType(element);
      myList.insertItem(data);
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
  cout<<"(i) - Insert value \n" << "(d) - Delete value \n" <<"(S) - Search value\n" << "(n) - Print next iterator value\n";
  cout<<"(r) - Reset iterator\n" << "(p) - Print list\n" << "(l) - Print length\n" << "(b) - Pairwise swap\n";
  cout<<"(c) - Clear list\n" << "(q) - Quit program\n";
  
  while(prompt){
    cout << "Enter a command: ";
    cin >> command;
   
    if(command == "q" || command == "Q"){
      prompt = false;
      cout<<"Quitting program..."<<endl;
    }else if(command =="i" || command =="I"){
      if(myList.length() !=0 ){
	myList.print();
      }else{
	cout<<"Insert your fist number! "<<endl;
      }
      element = getNumber('i');
      DataType mydata = DataType(element);
      myList.insertItem(mydata);
      myList.print();
    }else if(command == "d" || command == "D"){
      if(myList.length() != 0){
	myList.print();
	element = getNumber('d');
	DataType mydata = DataType(element);
	myList.deleteItem(mydata);
	if(myList.length() != 0){
	  myList.print();
	}else{
	  cout<<"You Deleted Everything..."<<endl;
	}
      }else{
	cout<<"You don't have anything to delete"<<endl;
      }
    }else if(command == "s" || command == "S"){
      element = getNumber('s');
      DataType mydata = DataType(element);
      int index = myList.search(mydata);
      if(index == -1) cout <<"Item not Found..." <<endl;
      else cout << "Index of the item is " << index << endl;
    }else if(command == "p" || command == "P"){
      if(myList.length()==0) cout<<"List is Empty..."<<endl;
      else myList.print();
    }else if(command == "l"|| command =="L"){
      cout<<"List length is "<<myList.length()<<endl;
    }else if(command == "b" || command == "B"){
      if(myList.length() != 0){
	cout<<"Before pairwise swap \n";
	myList.print();
	cout<<"After pairwise swap \n";
	myList.pairwiseSwap();
	myList.print();
      }else{
	cout<<"You have a empty list, cannot perform the swap" <<endl;
      }
    }else if (command == "c" || command == "C"){
      myList.clear();
      cout<<"List cleared"<<endl;
    }else{
      cout<<"Invalid Command! Try again"<<endl;
    }

  }//while

  return 0;
}



