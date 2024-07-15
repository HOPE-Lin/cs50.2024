#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int number, i, j, k;
    do
    {
        number = get_int("Height:\n");
    }
    while (number < 1);
    for (i = 1; i <= number; i++)
    {
        for (j = 1; j <= number; j++)
        {
            k = number - 1;
            if (j <= k)
            {
                printf(" ");
            }
            else
                printf("#");
        }
        printf("\n");
    }

}
