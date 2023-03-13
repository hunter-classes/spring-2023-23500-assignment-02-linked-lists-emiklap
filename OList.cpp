#include <iostream>
#include "Node.h"
#include "OList.h"

/**
 * constructor
 */
OList::OList(){
  head = nullptr;
}

/**
 * Deconstructor
 */
OList::~OList(){
  std::cerr << "Calling the destructor\n";
  Node *walker = head;
  Node *trailer = nullptr;
  while (walker != nullptr){
    trailer=  walker;
    walker = walker->getNext();
    std::cerr << "Deleting " << trailer->getData() << ", ";
    delete trailer;
  }
  std::cerr << "\n";
}

/**
 * Insert a new node with value into the list in its proper location
 */
void OList::insert(int data) {
  Node *newNode = new Node(data);
  Node *walker, *trailer;
  walker = this->head; // start of the list
  trailer = nullptr; // one behind

  //special case for inserting the first item in the list
  if (walker = nullptr) {
    newNode->setNext(head);
    head = newNode;
  } else {
    while (walker != nullptr) {
      int current_item = walker->getData();
      if (current_item > data) {
        trailer->setNext(newNode);
        newNode->setNext(walker);
        break;
      }
      trailer = walker;
      walker->getNext();
    }
  }
}
