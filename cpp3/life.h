#pragma once
#ifndef LIFE_H
#define LIFE_H
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

// game representation
//
// You'll want to add some more member functions, and some way of
// loading and saving them to files

class life {
public:
    // \constructor
    // Constructs the layout from a vector of strings
    life( const std::vector<std::string>& data );

    // \brief calculate the next generation
    // \returns the next layout
    life next() const;

    // \brief compare two 'life' instances for equality
    // \returns true iff the two instances are equivalent
    bool operator==( const life& ) const;
    // \brief compare two 'life' instances for inequality
    // \returns true iff the two instances are not equivalent
    bool operator!=( const life& ) const;
    
    // prints to console the status of the life
    void print();
private:
    // members
    std::vector<std::string> data_;
    int height;
    int width;
    
    // private methods
    char getCellAt(int x, int y) const;
    int getAliveNeighbours(int x, int y) const;
};

#endif
