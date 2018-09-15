#include "DataType.h"

using namespace std;

/**
 *A DataType is created with a int value
 *@param myValue: the int value used to initialize the DataType
 */
DataType::DataType(int myValue){
  value = myValue;
}

/**
 *return a enumurated comparison value indicting the equality of the two DataType items
 *@param item: the DataType Items that you want to make comparison with
 *@return EQUAL || GREATER || LESS 
 */
Comparison DataType::compareTo(DataType &item){
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
int DataType::getValue() const{
  return value;
}
