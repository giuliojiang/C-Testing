#include <limits>
#include <iostream>

using namespace std;

// function prototype
bool GetIntegerArrayMetrics( const int *array,
                             const size_t array_size,
                             size_t& min_pos,
                             int& min_val,
                             size_t& max_pos,
                             int& max_val )
{
    if (array == NULL || array_size == 0)
    {
        return false;
    }
    
    min_pos = 0;
    min_val = array[0];
    max_pos = 0;
    max_val = array[0];
    
    for (int i = 0; i < array_size; i++)
    {
        if (array[i] < min_val)
        {
            min_val = array[i];
            min_pos = i;
        }
        if (array[i] > max_val)
        {
            max_val = array[i];
            max_pos = i;
        }
    }
    
    return true;
}

int main(int argc, char* argv[])
{
    // Declare an array of integers (note on the stack
    // not the heap so we don't have to worry about freeing up the memory
    // it uses)
    const int array[] = {
        -897,
        12,
        347,
        9912345,
        0,
        3423,
        11,
        -1023,
        -67,
        99999999
    };
    // Figure out how many integers are in the array.
    const size_t array_size = sizeof(array)/sizeof(array[0]);

    size_t minPosition = 0;
    size_t maxPosition = 0;
    int minValue = 0;
    int maxValue = 0;
	
    if( GetIntegerArrayMetrics(array,
                               array_size,
                               minPosition,
                               minValue,
                               maxPosition,
                               maxValue) )
    {
        cout << '\n'
             << "Min value is " << minValue << " in position " << minPosition << '\n'
             << "Max value is " << maxValue << " in position " << maxPosition << '\n'
             << endl;
    }
    else
    {
        cout << "Something went wrong!" << endl;
    }

    return 0;
}
