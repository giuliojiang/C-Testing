#include "life.h"

using namespace std;

life::life( const vector<string>& data )
    : data_(data);
{
    height = data.size();
    
    if (height == 0)
    {
        std::cout << "Error, height can't be 0" << std::endl;
    }
    
    width = data[0].length();
}

life life::next() const
{
    // TODO - create a game instance representing the next generation here
    return *this;
}

bool life::operator==( const life& that ) const
{
    // TODO: 
    return false;
}

bool life::operator!=( const life& that ) const
{
    return !( *this == that );
}

char life::getCellAt(int x, int y)
{
    int xx = (x + width) % width;
    int yy = (y + height) % height;
    
    return data[yy][xx];
}

int life::getAliveNeighbours(int x, int y)
{
    int count = 0;
    
    if (getCellAt(x-1, y-1) == '*')
    {
        count++;
    }
    
    if (getCellAt(x, y-1) == '*')
    {
        count++;
    }
    
    if (getCellAt(x+1, y-1) == '*')
    {
        count++;
    }
    
    if (getCellAt(x-1, y) == '*')
    {
        count++;
    }
    
    if (getCellAt(x+1, y) == '*')
    {
        count++;
    }
    
    if (getCellAt(x-1, y+1) == '*')
    {
        count++;
    }
    
    if (getCellAt(x, y+1) == '*')
    {
        count++;
    }
    
    if (getCellAt(x+1, y+1) == '*')
    {
        count++;
    }
    
    return count;
}

//         -x-y =x-y +x-y
// 
//         -x=y      +x=y
// 
//         -x+y =x+y +x+y