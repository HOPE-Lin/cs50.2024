#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);

int main(void)
{
    int cents, quarters;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);
    quarters = calculate_quarters(cents);
    printf("%d\n", quarters);
}
int calculate_quarters(int cents)
{
    int i = 0;
    while (cents >= 25)
    {
        cents -= 25;
        i++;
    }
    while (cents >= 10)
    {
        cents -= 10;
        i++;
    }
    while (cents >= 5)
    {
        cents -= 5;
        i++;
    }
    while (cents > 0)
    {
        cents--;
        i++;
    }
    return i;
}
