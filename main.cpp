#include <iostream>
#include "List.h"

int main()
{
  List *l = new List();
  std::cout << l->toString() << " " << l->length() << "\n";
  l->insert(0,"a");
  std::cout << l->toString() << " " << l->length() << "\n";
  l->insert(0,"b");
  l->insert(0,"c");
  l->insert(0,"d");
  try {
    l->insert(10,"10");
  } catch (std::exception e){
    std::cout << "Insert x didn't work\n";
  }

  std::cout << l->toString() << "\n";
  l->insert(2,"inserted at 2");
  std::cout << l->toString() << "\n";
  l->insert(5,"inserted at end");
  std::cout << l->toString() << " " << l->length() << "\n";

  //PART 1 DEMOS
  std::cout << "\n------- PART 1 DEMOS -------\n";

  std::cout << "does l contain \"inserted at 2\"? " << l->contains("inserted at 2") << "\n";
  std::cout << "does l contain \"2\"? " << l->contains("2") << "\n";

  std::cout << "\n" << "Before removing any items:   " << l->toString() << "\n";
  l->remove(3);
  std::cout << "After removing item @ loc 3: " << l->toString() << "\n";

  l->remove(4);
  std::cout << "After removing item @ loc 4: " << l->toString() << "\n";

  delete l;
  return 0;
}
