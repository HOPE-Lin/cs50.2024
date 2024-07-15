#include <cs50.h>
#include <stdio.h>

void row(int space, int i);

int main(void)
{
    int number, space, i, j;
    do
    {
        number = get_int("Height: ");
    }
    while (number < 1 || number > 8);
    for (i = 0; i < number; i++)
    {
        space = number - 1 - i;
        row(space, i + 1);
    }
}
void row(int space, int i)
{
    int k;
    for (k = 0; k < space; k++)
    {
        printf(" ");
    }
    for (k = 0; k < i; k++)
    {
        printf("#");
    }
    printf("  ");
    for (k = 0; k < i; k++)
    {
        printf("#");
    }
    printf("\n");
}


