#include <iostream>
#include "Node.h"
#include "List.h"

List::List(){
  head = nullptr;
}

// insert at the "front" (head)
void List::insert(std::string data){
  Node *tmp = new Node(data);
  tmp->setNext(head);
  head = tmp;
}

/*
  insert at loc
  We need a pointer to the node BEFORE
  the location where we want to insert

  Piggybacking
 */
void List::insert(int loc, std::string data){
  Node *walker, *trailer;
  walker = this->head; // start of the list
  trailer = nullptr; // one behind

  while(loc>0 && walker != nullptr){
    loc=loc-1;

    /* trailer will always be one node
       behind walker */
    trailer=walker;
    walker = walker->getNext();

  }

  // At this point, trailer points to the Node
  // BEFORE where we want to insert


  // test to see if we're trying to
  // insert past the end
  if (loc > 0){
    // do something to indicate this is invalid
    throw std::out_of_range("Our insert is out of range");
  }

  Node *newNode = new Node(data);
  // Inserting at true location 0
  // will have trailer == nullptr
  // - we have to treat that as a special case
  if (trailer == nullptr){
    newNode->setNext(head);
    head = newNode;
  } else {
    // do the regular case
    newNode->setNext(walker);
    trailer->setNext(newNode);
  }
}

/*
  Alternate solution:
    make a private variable to store the length
    and just return it here.

    Change all the insert/delete/remove type
    routines to upate that variable
 */
int List::length(){
  int count = 0;
  Node *walker = head;
  while (walker != nullptr){
    count++;
    walker = walker->getNext();
  }
  return count;
}

std::string List::toString(){
  Node *tmp = this->head;
  std::string result = "";
  while (tmp != nullptr){
    result = result + tmp->getData();
    result = result + "-->";
    tmp = tmp->getNext();
  }
  result = result + "nullptr";
  return result;
}


//PART 1 ATTEMPTS

bool List::contains(std::string item) {
  Node *tmp = this->head;
  bool result = false;

  while (tmp != nullptr){
    std::string current_item = tmp->getData();
    if (current_item == item) {
      result = true;
    }
    tmp = tmp->getNext();
  }
  return result;
}

void List::remove(int loc) {
  //have three nodes: a walker in front, one in the middle, and a trailer at the end
  Node *walker, *middle, *trailer;
  walker = this->head; // start of the list
  middle = nullptr;
  trailer = nullptr; // one behind

  //this loop should stop when the middle reaches the location or when the walker goes out of bounds
  while(loc>=0 && walker != nullptr){
    loc--;
    trailer=middle;
    middle = walker;
    walker = walker->getNext();

  }

  // test to see if we're trying to
  // insert past the end
  if (loc > 0){
    // do something to indicate this is invalid
    throw std::out_of_range("Our remove is out of range");
  }

  //by setting the next node of the trailer to walker, we are cutting out the middle node from the list
  trailer->setNext(walker);

  return;
}

List::~List() {
  Node *tmp, *next;
  tmp = this->head;
  next = this->head->getNext();
  while (next != nullptr){
    tmp = nullptr;
    tmp = next;
    next->getNext();
    std::cout << tmp << " ";
  }
  next = nullptr;
}

