#include <cs50.h>
#include <stdio.h>
int main(void)
{
    long number;
    int num[20], i = 0, j = 0, sum = 0, k = 0;
    number = ger_long("Number:");
    while (number != 9)
    {
        num[i] = number % 10;
        number = number / 10;
        i++;
    }
    for(j=1; j<=i; j += 2)
    {
        k = 2 * num[j];
        if (k > 9)
        {
            sum = sum + k % 10 + 1;
        }
        else
            sum += k;
    }
    if (sum % 10 != 0)
    {
        printf("INVALID");
        return 1;
    }
    int start = 0;
    start = number[i] * 10 +number[i-1];
    if (start == 34 || start == 37 || start ==51 || start == 52 || start == 53 || start == 54)
    {
        printf("VAILD");
    }
}
