#include "doctest/doctest.h"
#include "PriorityQueue.hh"

TEST_CASE("Try,catch test") {
    SPriorityQueue<int> Q;
    try {
        Q.removeMin();
    }
    catch(Exception& e) {
        CHECK( e.getErrorMessage() == "Queue is empty" );
    }

    try {
        Q.removeRandom();
    }
    catch(Exception& e) {
        CHECK( e.getErrorMessage() == "Queue is empty" );
    }
    
}

