
--This linked list class contain six functions--
  List();	      
  void AddNode(int addData); // add Node to the end
  bool AddAtIndex(int index, int addData);  //add Node to specified index
  void DeleteNode(int delData);  //delete specific Node with the delData  
  void DeleteAtIndex(int index); //delete specific Node at Index
  void DeleteNode();  //delete Node at end
  void PrintList();  //print list

To compile:

type: make

To run:

type: ./main