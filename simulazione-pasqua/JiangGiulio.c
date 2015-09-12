#include "JiangGiulio.h"

void** Porzione(void** a, int i, int j, int n)
{
    if (a == NULL || i >= n)
    {
        // empty input or invalid i
        return NULL;
    }
    else if (j == 0 || j >= n)
    {
        // return a[i:]
        int newLength = n - i;
        
        // allocate memory
        void** result = calloc(newLength, sizeof(void*));
        if (result == NULL)
        {
            perror("calloc\n");
            exit(EXIT_FAILURE);
        }
        
        // copy
        for (int b = 0; i < n; b++, i++)
        {
            result[b] = a[i];
        }
        
        return result;
    }
    else if (i >= j)
    {
        // empty sequence requested
        return NULL;
    }
    else
    {
        int newLength = j - i;
        
        // allocate memory
        void** result = calloc(newLength, sizeof(void*));
        if (result == NULL)
        {
            perror("calloc\n");
            exit(EXIT_FAILURE);
        }
        
        // copy
        for (int b = 0; i < j; b++, i++)
        {
            result[b] = a[i];
        }
        
        return result;
    }
}

void printIntArray(void** a, int n)
{
    if (a == NULL)
    {
        printf("\n");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%i\t", *((int*) a[i]));
    }
    printf("\n");
}

// 0 1 2 3 4    n = 5   i = 2
//     x x x
//     
//     l = 3
// 
// 0 1 2 3 4   i = 2  j = 3
//     x 