#include "JiangGiulio.h"

int getUppercaseLowercaseOffset(void)
{
    return abs(((int) 'A') - ((int) 'a'));
}

int abs(int x)
{
    return x >= 0 ? x : -x;
}

int isLetter(char c)
{
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

int letterEquals(char a, char b)
{
    if (isLetter(a) && isLetter(b))
    {
        if (a < b)
        {
            return (a + getUppercaseLowercaseOffset()) == b;
        } else if (b < a)
        {
            return (b + getUppercaseLowercaseOffset()) == a;
        } else
        {
            return 1;
        }
    } else
    {
        return a == b;
    }
}

int QuasiUguale(char* a, char* s)
{
    int i = 0;
    for (i = 0; a[i] != '\0' && s[i] != '\0'; i++)
    {
        if (!letterEquals(a[i],s[i]))
        {
            return 0;
        }
    }
    return a[i] == '\0' && s[i] == '\0';
}

int* QuasiUguali(char *a[], char *s, int n)
{
    int* result = calloc(n, sizeof(int));
    if (result == NULL)
    {
        perror("calloc\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < n; i++)
    {
        result[i] = QuasiUguale(a[i], s);
    }
    
    return result;
}