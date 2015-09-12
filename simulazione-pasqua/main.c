#include "JiangGiulio.h"

int main(void)
{
    int length = 7;
    void** a = calloc(length, sizeof(void*));
    if (a == NULL)
    {
        perror("calloc\n");
        exit(EXIT_FAILURE);
    }
    
    // populate array
    for (int i = 0; i < length; i++)
    {
        a[i] = calloc(1, sizeof(int));
        if (a[i] == NULL)
        {
            perror("calloc\n");
            exit(EXIT_FAILURE);
        }
    }
    *((int*) a[0]) = 10;
    *((int*) a[1]) = 2;
    *((int*) a[2]) = 5;
    *((int*) a[3]) = 9;
    *((int*) a[4]) = 4;
    *((int*) a[5]) = 7;
    *((int*) a[6]) = 6;
    
    printf("Original array:\t");
    printIntArray(a, length);
    
    printIntArray(Porzione(a, 1, 4, length), 3);
    
    printIntArray(Porzione(a, 3, 0, length), 4);
    
    printIntArray(Porzione(a, 0, 21, length), 7);
    
    printIntArray(Porzione(a, 1, 1, length), 0);
    
}