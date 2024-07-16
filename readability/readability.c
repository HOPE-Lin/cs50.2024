#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_sentences(string text);

int count_words(string text);

int count_letters(string text);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    
}
int count_letters(string text)
{
    int i, count = 0;
    for (i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}
int count_words(string text)
{
    int i, count = 0;
    for(i = 0, len = strlen(text); i < len; i++)
    {
        if (isblank(text[i]))
        {
            count++;
        }
    }
    return count;
}
int count_sentences(string text)
{
    int i, count = 0;
    for (i = 0, len = strlen(text); i < len; i++)
    {
        if (ispunct(text[i]))
        {
            count++;
        }
    }
    return count;
}
