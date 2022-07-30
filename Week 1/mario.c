#include <stdio.h>
#include <cs50.h>


int main(void)
{
    int n = -1;

    //loop for the correct character
    while (n < 1 || n > 8)
    {
        n = get_int("Number: ");
    }

    //for row
    for (int i = 1; i <= n; i++)
    {
        //space before #
        for (int k = n; k > i; k--)
        {
            printf(" ");
        }
        //firsts #
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        //space between
        printf("  ");

        //seconds #
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }

}
