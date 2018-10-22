#ifndef ITEMTYPE_H
#define ITEMTYPE_H

typedef enum {GREATER,LESS,EQUAL} Comparison;

class itemType{
 private:
  int value;

 public:
  itemType();
  itemType(int myValue);
  Comparison compareTo(itemType &item);
  int getValue() const;
  void setValue(int myValue);
};

#endif
