#include <string.h>

#include "JiangGiulio.h"

#define BUFFER_SIZE 50

int main(void)
{
    printf("offset is %i\n", getUppercaseLowercaseOffset());
    
    printf("\nletterEquals tests...\n");
    printf("%i\n", letterEquals('k','k'));
    printf("%i\n", letterEquals('k','K'));
    printf("%i\n", letterEquals('K','k'));
    printf("%i\n", letterEquals('K','K'));
    printf("%i\n", letterEquals('-','-'));
    printf("\n");
    printf("%i\n", letterEquals('k','a'));
    printf("%i\n", letterEquals('-','-' + getUppercaseLowercaseOffset()));
    printf("%i\n", letterEquals('L','d'));
    
    printf("\n");
    
    printf("QuasiUguale tests...\n");
    printf("%i\n", QuasiUguale("ciao", "Ciao"));
    printf("%i\n", QuasiUguale("ciao", "CIAO"));
    printf("%i\n", QuasiUguale("ciao", "ciao"));
    printf("%i\n", QuasiUguale("cia==o", "Cia==o"));
    printf("\n");
    printf("%i\n", QuasiUguale("bello", "a"));
    printf("%i\n", QuasiUguale("a", "bello"));
    printf("%i\n", QuasiUguale("nana-", "nana?"));
    printf("%i\n", QuasiUguale("", "e"));
    
    // callocate space for string array
    int length = 7;
    char** strings = calloc(length, sizeof(char*));
    if (strings == NULL)
    {
        perror("calloc\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < length; i++)
    {
        strings[i] = calloc(BUFFER_SIZE, sizeof(char));
        if (strings[i] == NULL)
        {
            perror("calloc\n");
            exit(EXIT_FAILURE);
        }
    }
    int* result = 0;
    strcpy(strings[0], "ciao-");
    strcpy(strings[1], "ciAo-");
    strcpy(strings[2], "CIAO-");
    strcpy(strings[3], "ciao");
    strcpy(strings[4], "");
    strcpy(strings[5], "beeeee");
    strcpy(strings[6], "cIao=");
    
    
    result = QuasiUguali(strings, "ciao-", 7);
    for (int i = 0; i < 7; i++)
    {
        printf("%s\t\t%i\n", strings[i], result[i]);
    }
    
    // free memory
    free(result);
    for (int i = 0; i < length; i++)
    {
        free(strings[i]);
    }
    free(strings);
    
    return EXIT_SUCCESS;
}