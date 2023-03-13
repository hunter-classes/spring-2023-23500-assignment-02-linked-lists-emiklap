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
  CHECK(test1->toString() == "12-->10-->3-->nullptr");
  test1->insert(6);
  test1->insert(4);
  test1->insert(2);
  CHECK(test1->toString() == "12-->10-->6-->4-->3-->2-->nullptr");
}

TEST_CASE("contains function") {
  CHECK(test1->contains(10));
  CHECK(test1->contains(4));
  CHECK(!test1->contains(15));
  CHECK(!test1->contains(0));
}
