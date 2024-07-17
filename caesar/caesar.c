#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool only_digits(string);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    bool answer = only_digits(argv[1]);
    if (answer == 0){
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
bool only_digits(string text)
{
    bool anwers = true;
    for(int i = 0, len = strlen(text); i < len; i++)
    {
        if ( ! isdigit(string[i]))
        {
            anwers = false;
            return anwers;
        }
    }
    return anwers;
}
