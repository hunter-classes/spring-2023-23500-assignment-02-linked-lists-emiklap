#include <iostream>
#include <string>
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
  walker = this->head;
  trailer = nullptr;
  bool inList = false;

  //special case if the list is empty
  if (walker == nullptr) {
    newNode->setNext(head);
    head = newNode;
    inList = true;
  }
  else {
    //another special case if the item is bigger than the last item
    int current_item = walker->getData();
    if (current_item < data) {
      newNode->setNext(head);
      head = newNode;
      inList = true;
    }

    // continue if this is not the case
    while (!inList && walker != nullptr) {
      current_item = walker->getData();
      if (current_item < data) {
        newNode->setNext(walker);
        trailer->setNext(newNode);
        inList = true;
      }
      trailer = walker;
      walker = walker->getNext();
      if (!inList && walker == nullptr) {
        newNode->setNext(walker);
        trailer->setNext(newNode);
      }
    }
  }

}

/**
 * returns a string representation of the full list
 */
std::string OList::toString() {
  Node *tmp = this->head;
  std::string result = "";
  while (tmp != nullptr){
    result = result + std::to_string(tmp->getData());
    result = result + "-->";
    tmp = tmp->getNext();
  }
  result = result + "nullptr";
  return result;
}

/**
 * returns true if value is in the list, false otherwise
 */
bool OList::contains(int item) {
  Node *tmp = this->head;
  bool result = false;

  while (tmp != nullptr){
    int current_item = tmp->getData();
    if (current_item == item) {
      result = true;
    }
    tmp = tmp->getNext();
  }
  return result;
}
