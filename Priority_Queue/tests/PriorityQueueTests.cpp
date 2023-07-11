#include "doctest/doctest.h"
#include "PriorityQueue.hh"

TEST_CASE("SPriorityQueue methods tests") {
    SPriorityQueue<int>* Q = new SPriorityQueue<int>;
    CHECK(Q->getHead() == std::nullptr_t(NULL));
    CHECK(Q->getSize() == 0);
    CHECK(Q->isEmpty());
    try {
        Q->removeMin();
    }
    catch (Exception& e) {
        CHECK ( e.getErrorMessage() == "Queue is empty");
    }
    try {
        Q->removeRandom();
    }
    catch (Exception& e) {
        CHECK ( e.getErrorMessage() == "Queue is empty");
    }
    Q->insert(2,5,false);
    CHECK(Q->getHead()->getElement() == 5);
    CHECK(Q->getHead()->getKey() == 2);
    CHECK(!Q->isEmpty());
    CHECK(Q->min().getElement() == 5 );
    CHECK(Q->removeMin().getElement() == 5); 
}

TEST_CASE ("SPriorityQueue auto sorting tests")
{
    SPriorityQueue<int>* S = new SPriorityQueue<int>;
    S->insert(0,5,false); 
    CHECK( S->getSize() == 1 );
    S->insert(1,3,false);
    CHECK( S->getHead()->getElement() == 5 );
    S->insert(4,20,false);
    CHECK( S->getHead()->getNext()->getNext()->getElement() == 20 );
    S->insert(3,-2,false);
    S->insert(2,60,false);
    CHECK( S->getHead()->getElement() == 5 );
    CHECK( S->getHead()->getNext()->getElement() == 3 );
    CHECK( S->getHead()->getNext()->getNext()->getElement() == 60 );
    CHECK( S->getHead()->getNext()->getNext()->getNext()->getElement() == -2 );
    CHECK( S->getHead()->getNext()->getNext()->getNext()->getNext()->getElement() == 20 );
}