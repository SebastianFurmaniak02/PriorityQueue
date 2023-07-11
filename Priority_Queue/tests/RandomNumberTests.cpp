#include "doctest/doctest.h"

#include "RandomNumber.hh"

TEST_CASE( "Random number generator test" )
{
    int x = getRandomNumber(1,5);
    CHECK( x <= 5 );
    CHECK( x >= 1 );
}