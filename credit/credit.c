#include <cs50.h>
#include <stdio.h>
int main(void)
{
    long number;
    int i;
    number = ger_long("Number:");
    while (number > 9)
    {
        i = number % 100;
        number = number / 100
    }
}
