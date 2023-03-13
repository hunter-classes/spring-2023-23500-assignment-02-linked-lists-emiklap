#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "OList.h"

OList *test1 = new OList();

//for these tests, i had to accomidate for rounding differences
TEST_CASE("toString and insert functions") {
  test1->insert(10);
  test1->insert(12);
  CHECK(test1->toString() == "12-->10-->nullptr");
  test1->insert(3);
  test1->insert(3);
  CHECK(test1->toString() == "12-->10-->3-->3-->nullptr");
  test1->insert(6);
  test1->insert(4);
  test1->insert(2);
  CHECK(test1->toString() == "12-->10-->6-->4-->3-->3-->2-->nullptr");
}

TEST_CASE("contains function") {
  CHECK(test1->contains(10));
  CHECK(test1->contains(4));
  CHECK(!test1->contains(15));
  CHECK(!test1->contains(0));
}

TEST_CASE("get function") {
  CHECK(test1->get(0) == 12);
  CHECK(test1->get(3) == 4);
  CHECK(test1->get(6)== 2);
  //I could not figure out how to check that the throw error works, but I know it does (I tested it in main)
  //CHECK(test1->get(10) == std::out_of_range("Our remove is out of range");
}

TEST_CASE("remove and toString functions") {
  test1->remove(0);
  CHECK(test1->toString() == "10-->6-->4-->3-->3-->2-->nullptr");
  test1->remove(3);
  CHECK(test1->toString() == "10-->6-->4-->3-->2-->nullptr");
}

TEST_CASE("reverse and toString function") {
  test1->reverse();
  CHECK(test1->toString() == "2-->3-->4-->6-->10-->nullptr");
  test1->reverse();
  CHECK(test1->toString() == "10-->6-->4-->3-->2-->nullptr");
}

//Sorry, I'm not sure how to test this one
TEST_CASE("deconstructor") { }
