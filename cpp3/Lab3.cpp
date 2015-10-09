#include "life.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cassert>
#include <unistd.h>

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
//     life gen0( initial );
//     life gen1 = gen0.next();
//     
//     gen0.print();
//     
//     std::cout << std::endl;
//     
//     gen1.print();
//     
//     assert( gen1 == life( expected ) );
    
    if (argc < 2)
    {
        std::cout << "Error, no argument supplied." << std::endl;
        return 1;
    }
    
    // open file
    fstream inputfile (argv[1], std::ifstream::in);
    
    std::vector<std::string> data;
    
    // parse input text file
    while (!inputfile.eof())
    {
        std::string buffer;
        inputfile >> buffer;
        if (buffer.length() == 0)
        {
            break;
        }
        data.push_back(buffer);
    }
    
    // create first iteration status
    life current (data);
    
    // loop
    for(;;)
    {
        current.print();
        std::cout << std::endl;
        usleep(100000);
        current = current.next();
    }
    
    return 0;
}
