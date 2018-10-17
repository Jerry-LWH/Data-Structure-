#include <cstddef>
#include "itemType.h"


using namespace std;

/**
 *A DataType is created with a int value
 *@param myValue: the int value used to initialize the DataType
 */
itemType::itemType(int myValue){
  value = myValue;
}

itemType::itemType(){
  value = 0;
}

void itemType::setValue(int myValue){
  value=myValue;
}

/**
 *return a enumurated comparison value indicting the equality of the two DataType items
 *@param item: the DataType Items that you want to make comparison with
 *@return EQUAL || GREATER || LESS 
 */
Comparison itemType::compareTo(itemType &item){
  if(value > item.value){
    return GREATER;
  }else if(value == item.value){
    return EQUAL;
  }else{
    return LESS;
  }
}

/**
 *return the value of the DataType
 *@return a int representing the value
 */
int itemType::getValue() const{
  return value;
}
