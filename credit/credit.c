#include <cs50.h>
#include <stdio.h>
int main(void)
{
    long number;
    int num[20], i = 0;
    number = ger_long("Number:");
    while (number > 9)
    {
        num[i] = number % 10;
        number = number / 10;
        i++;
    }
}
