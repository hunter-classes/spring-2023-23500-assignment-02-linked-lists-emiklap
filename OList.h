#pragma once
#include <iostream>
#include "Node.h"

class OList{
 private:
  Node *head;
 public:
  OList();
  ~OList();

  //helper function
  int getHead();

  //Insert a new node with value into the list in its proper location
  void insert(int data);

  //returns a string representation of the full list
  std::string toString();

  //returns true if value is in the list, false otherwise
  bool contains(int item);

  //returns the value at loc
  int get(int loc);

  //removes the value at loc
  void remove(int loc);

  //  This should “reverse” the list - that is reverse the pointers
  void reverse();
};
