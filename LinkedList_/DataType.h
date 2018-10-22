#ifndef DATATYPE_H
#define DATATYPE_H

typedef enum {GREATER,LESS,EQUAL} Comparison;

class DataType{
 private:
  int value;

 public:
  explicit DataType(int myValue);
  Comparison compareTo(DataType &item);
  int getValue() const;
};

#endif
