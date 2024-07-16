#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int compute(string word);

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    int score1 = compute(word1);
    int score2 = compute(word2);
}
int compute(string word)
{}
