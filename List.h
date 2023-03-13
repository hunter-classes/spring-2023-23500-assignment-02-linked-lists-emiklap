#pragma once
#include <iostream>
#include "Node.h"

class List{
 private:
  Node *head;
 public:
  List();
  void insert(int data);
  void insert(int loc, int data); //0 indexed
  int length();

  std::string toString(); // for testing purposes

  //part 1 functions
  bool contains(int item);
  void remove(int loc);
  ~List();
};
