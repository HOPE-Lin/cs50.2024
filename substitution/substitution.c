#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ,/substitution key\n");
        return 1;
    }
    bool answer = only_alpha(argv[1]);
    if (answer == false)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    string plaintext = get_string("plaintext: ");
    for (int i = 0, len = strlen(plaintext); i < len;i++)
    {
        if(isalpha != 0)
        {
            plaintext = encrypt(plaintext[i], );
        }
    }
}
bool only_alpha(string text)
{
    bool b = false;
    int i = 0;
    for (i = 0, len = strlen (text); i < len; i++)
    {
       if (isalpha == 0)
       {
        return b;
       }
    }
    if (i == 25)
    {
        b = true;
    }
    return b;
}
