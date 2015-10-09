#include "life.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

// The initial pattern
// HINT: vector<string> is a conveniant representation, but may not be optimal
const vector<string> initial {
    "........",
    "....*...",
    "...**...",
    "........"
};

const vector<string> expected {
    "........",
    "...**...",
    "...**...",
    "........"
};

int main( int argc, char *argv[] )
{
    life gen0( initial );
    life gen1 = gen0.next();
    assert( gen1 == life( expected ) );
}
