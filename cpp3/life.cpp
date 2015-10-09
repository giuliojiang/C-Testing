#include "life.h"

using namespace std;

life::life( const vector<string>& data )
    : data_(data)
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
    vector<string> stage;
    for (int i = 0; i < height; i++)
    {
        std::stringstream linebuffer;
        for (int j = 0; j < width; j++)
        {
            if (getCellAt(j, i) == '*')
            {
                if (getAliveNeighbours(j, i) < 2)
                {
                    linebuffer << '.';
                }
                else if (getAliveNeighbours(j, i) == 2 || getAliveNeighbours(j, i) == 3)
                {
                    linebuffer << '*';
                }
                else
                {
                    linebuffer << '.';
                }
            } else
            {
                if (getAliveNeighbours(j, i) == 3)
                {
                    linebuffer << '*';
                }
                else
                {
                    linebuffer << '.';
                }
            }
        }
        stage.push_back(linebuffer.str());
    }
    
    life out (stage);
    return out;
}

bool life::operator==( const life& that ) const
{
    return data_ == that.data_;
}

bool life::operator!=( const life& that ) const
{
    return !( *this == that );
}

char life::getCellAt(int x, int y) const
{
    int xx = (x + width) % width;
    int yy = (y + height) % height;
    
    return data_[yy][xx];
}

int life::getAliveNeighbours(int x, int y) const
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



void life::print()
{
    for (int i = 0; i < height; i++)
    {
        for (char c : data_[i])
        {
            if (c == '.')
            {
                std::cout << ' ';
            } else
            {
                std::cout << c;
            }
        }
        std::cout << std::endl;
    }
}