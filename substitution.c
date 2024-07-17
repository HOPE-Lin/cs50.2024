#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool only_alpha(string text);

char encrypt(char a, string key);

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
        if(isalpha(plaintext[i]) != 0)
        {
            plaintext[i] = encrypt(plaintext[i], argv[1]);
        }
    }
    printf("ciphertext: %s\n", plaintext);
}
bool only_alpha(string text)
{
    bool b = false;
    int i = 0, len;
    for (i = 0, len = strlen (text); i < len; i++)
    {
       if (isalpha(text[i]) == 0)
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
char encrypt(char a, string key)
{
    int i = 0;
    char b;
    if (isupper(a) != 0)
    {
        i = a - 'A';
        b = key[i];
        b = toupper(b);
    }
    else
    {
        i = a - 'a';
        b = key[i];
        b = toupper(b);
    }
    return b;
}
