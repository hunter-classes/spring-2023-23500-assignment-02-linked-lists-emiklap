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

/**
 *  returns the value at loc
 */
int OList::get(int loc) {
  Node *tmp = this->head;

  while(loc > 0 && tmp != nullptr) {
    loc--;
    tmp = tmp->getNext();
  }

  if (tmp == nullptr) {
    throw std::out_of_range("Our remove is out of range");
  }
  return tmp->getData();
}

/**
 * removes the value at loc
 */
void OList::remove(int loc) {
  Node *walker, *trailer;
  walker = this->head;
  trailer = nullptr;

  //this loop should stop when the middle reaches the location or when the walker goes out of bounds
  while(loc > 0 && walker != nullptr){
    loc--;
    trailer=walker;
    walker = walker->getNext();
  }

  //if the walker goes out of bounds, the remove loc was not in range
  if (walker == nullptr) {
    throw std::out_of_range("Our remove is out of range");
  }

  if (trailer == nullptr) {
    head = walker->getNext();
  } else {
    trailer->setNext(walker->getNext());
  }
  delete walker;
  return;
}

/**
 * This should ???reverse??? the list - that is reverse the pointers
 */
void OList::reverse() {
  Node *walker = head;
  Node *trailer = nullptr;
  Node *tmp = walker->getNext();

  while (tmp != nullptr) {
    walker->setNext(trailer);
    trailer = walker;
    walker = tmp;
    tmp = tmp->getNext();
  }
  walker->setNext(trailer);

  head = walker;
  return;
}
