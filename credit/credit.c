#include <cs50.h>
#include <stdio.h>
int main(void)
{
    long number;
    int num[20], i = 0, j = 0, sum = 0, k = 0;
    number = get_long("Number:");
    while (number != 0)
    {
        num[i] = number % 10;
        number = number / 10;
        i++;
    }
    for(j = 1; j <= i; j += 2)
    {
        k = 2 * num[j];
        if (k > 9)
        {
            sum = sum + k % 10 + 1;
        }
        else
            sum += k;
    }
    for(j = 0; j <= i; j += 2)
    {
        sum += num[j];
    }printf("%d\n",num[i]);
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 1;
    }
    int start = 0;
    start = 10 * num[i] + num[i-1];
    if (start == 34 || start == 37 || start ==51 || start == 52 || start == 53 || start == 54)
    {
        printf("VAILD\n");
    }
    else if (num[i] == 4)
        printf("VAILD\n");
    else
        printf("INVAILD5\n");
}
