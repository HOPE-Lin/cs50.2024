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
    int index;
    double L;
    L = ((double) letters / (double) words) * 0.0588 * 100 - ((double) sentences / (double) words) *100 * 0.296 - 15.8;
    index = (int) round(L);
    if (index > 16 )
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
int count_letters(string text)
{
    int i, count = 0, len;
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
    int i, count = 0, len;
    for(i = 0, len = strlen(text); i < len; i++)
    {
        if (isblank(text[i]))
        {
            count++;
        }
    }
    return count + 1;
}
int count_sentences(string text)
{
    int i, count = 0, len;
    for (i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '?' || text[i] == '!' || text[i] == '.')
        {
            count++;
        }
    }
    return count;
}
