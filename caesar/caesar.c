#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string);
char rotate(char a, int k);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    bool answer = only_digits(argv[1]);
    if (answer == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key = atoi(argv[1]) % 26;
    string plaintext = get_string("plaintext :");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (isalpha(plaintext[i]) != 0)
        {
            plaintext[i] = rotate(plaintext[i], key);
        }
    }
    printf("ciphertext: %s\n", plaintext);
}
bool only_digits(string text)
{
    bool anwers = true;
    for(int i = 0, len = strlen(text); i < len; i++)
    {
        if (isdigit(text[i]) == 0)
        {
            anwers = false;
            return anwers;
        }
    }
    return anwers;
}
char rotate(char a, int k)
{
    int i;
    char b;
    if (isupper(a) != 0)
    {
        i = a - 'A';
        i = (i + k) % 26;
        b = 'A' + i;
    }
    if (islower(a) != 0)
    {}
    return i;
}
