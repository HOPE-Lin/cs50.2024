#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int number,i,j;
    do{
        number = get_int("Height:\n");
    }while(number<=0);
    for(i=1;i<=number;i++){
        for(j=1;j<=i;j++){
            printf("#");
        }
        printf("\n");
    }

}
