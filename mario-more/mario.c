#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int number;
    do
    {
        number = get_int("Height: ");
    }
    while(number<1||number>8);

}
