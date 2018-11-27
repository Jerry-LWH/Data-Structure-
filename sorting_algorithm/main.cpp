#include "Sorting.h"
#include<cstdlib>
#include<fstream>
#include<iostream>

using namespace std;

int main(int argc, char* argv[]){
  fstream fileStream;
  int num[11000];
  int copyNum[11000];
  int element;
  int length=0;
  string command;
  bool prompt = true;
  int index=0;
  //DataType data;

  // open file and put all the variable in the linkedList
  fileStream.open(argv[1],ifstream::in);
  if(fileStream.is_open()){
    fileStream >> element;
    while(!fileStream.eof()){
      num[index]=element;
      copyNum[index]=element;
      index++;
      length++;
      fileStream >> element;
    }
  }
  else{
    cout << "Error opening file. " <<
      "Try again." << endl;
    return 0;
  }

  Sorting sort;
  //prompt
  while(prompt){
    for(int i = 0; i < length; i++){
      num[i]=copyNum[i];
    }
    cout << "Enter a algorithm for sorting: ";
    cin >> command;

    if(command == "e" || command == "E"){
      prompt = false;
      cout<<"Exiting program..."<<endl;
    }else if(command =="i" || command =="I"){
      sort.insertionSort(num,length);
      cout<<"Insertion sort: ";
      sort.print(num,length);
      cout<<endl;
      cout<<"Total # comparisons: " << sort.counter<<endl;
    }else if(command=="m" || command =="M"){
      sort.mergeSort(num,0,length-1);
      cout<<"Merge sort: ";
      sort.print(num,length);
      cout<<endl;
      cout<<"Total # comparisons: " << sort.counter<<endl;
    }else if(command=="q" || command == "Q"){
      sort.quickSort(num,length);
      cout<<"Quick sort: ";
      sort.print(num,length);
      cout<<endl;
      cout<<"Total # comparisons: " << sort.counter<<endl;
    }else{
      cout<<"Unregonized command, try again..."<<endl;
    }
  }//while
 
  //sort.mergeSort(num,0,length-1);
  //sort.quickSort(num,length);
  //sort.print(num,length);
  //cout<<"count = "<<sort.counter<<endl;
}
