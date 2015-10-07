#include <cassert>
#include <cstring>

#include <iostream>
using namespace std;

const size_t NO_OF_CHARS = 100;

void ChangeHateToLove(char*);

int main(int argc, char* argv[])
{
    try
    {
        char *pString = new char[NO_OF_CHARS];

        strcpy(pString, "These Imperial College students hate, absolutely hate, C++.  Whatever!");
        
        cout << endl << pString << endl;

        ChangeHateToLove(pString);

        cout << endl << pString << endl;

        // Clean up after ourselves
        delete [] pString;
    }
    catch( const std::exception& ex )
    {
        std::cerr << "main: Caught " << ex.what() << std::endl;
        return -1;
    }
}

bool checkHate(char* s)
{
    char match[5] = "hate";
    for (int i = 0; match[i] != '\0'; i++)
    {
        if (s[i] == '\0' || s[i] != match[i])
        {
            return false;
        }
    }
    return true;
}

void replaceHate(char* s)
{
    char rep[5] = "love";
    for (int i = 0; rep[i] != '\0'; i++)
    {
        s[i] = rep[i];
    }
}

void ChangeHateToLove(char* pString)
{
    bool isNewWord = true;
    for (int i = 0; pString[i] != '\0'; i++)
    {
        if (isNewWord && checkHate(&pString[i]))
        {
            replaceHate(&pString[i]);
        }
        isNewWord = pString[i] == ' ';
    }
}
