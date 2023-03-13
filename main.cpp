#include <iostream>
#include "List.h"
#include "OList.h"

int main()
{
  List *l = new List();
  l->insert(0,1);
  l->insert(0,2);
  l->insert(0,3);
  l->insert(0,4);
  try {
    l->insert(10,10);
  } catch (std::exception e){
    //std::cout << "Insert x didn't work\n";
  }

  l->insert(2, 20);
  l->insert(5, 50);
  std::cout << l->toString() << " " << l->length() << "\n";

  //PART 1 DEMOS
  std::cout << "------- PART 1 DEMOS -------\n";

  std::cout << "does l contain 20? " << l->contains(20) << "\n";
  std::cout << "does l contain 30? " << l->contains(20) << "\n";

  std::cout << "\n" << "Before removing any items:   " << l->toString() << "\n";
  l->remove(3);
  std::cout << "After removing item @ loc 3: " << l->toString() << "\n";

  l->remove(4);
  std::cout << "After removing item @ loc 4: " << l->toString() << "\n";

  delete l;

  //PART 2 DEMOS
  std::cout << "\n------- PART 2 DEMOS -------\n";
  OList *l2 = new OList();
  l2->insert(10);
  l2->insert(12);
  l2->insert(3);
  l2->insert(6);
  l2->insert(4);
  l2->insert(2);

  std::cout << "> Adding 10, 12, 3, 4, 2\n";
  std::cout << l2->toString() << "\n\n";

  std::cout <<"does list contain 2? " << l2->contains(2) << "\n";
  std::cout <<"does list contain 1000? " << l2->contains(1000) << "\n";
  std::cout <<"item at location 2 is:  " << l2->get(2) << "\n\n";
  //this works, but it will crash the program so I commented it out
  //std::cout <<"item at location 10 is:  " << l->get(10) << "\n";

  l2->remove(0);
  l2->remove(2);
  std::cout << "> Remove the item at 0, then 2\n";
  std::cout << l2->toString() << "\n\n";
  std::cout << "l->reverse(): \n";
  l2->reverse();
  std::cout << l2->toString() << "\n\n";

  delete l2;
  //im not sure how to check the deleted list in the tests file
  return 0;
}
