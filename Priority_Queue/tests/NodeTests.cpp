#include "doctest/doctest.h"
#include "Node.hh"

TEST_CASE("SNode class methods tests")
{
    SNode<int> N;
    CHECK ( N.getNext() == std::nullptr_t(NULL) );
    N.setElement(20);
    N.setKey(1);
    N.setNext(new SNode<int>);
    N.getNext()->setElement(30);
    N.getNext()->setKey(2);
    CHECK( N.getKey() == 1 );
    CHECK( N.getElement() == 20);
    CHECK( N.getNext()->getKey() == 2);
    CHECK( N.getNext()->getElement() == 30);
}