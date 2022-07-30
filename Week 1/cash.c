#include <stdio.h>
#include <cs50.h>

int get_cents(void);

int calculate_quarters(int cents)
{
    int coin = cents / 25;
    return (coin);
}

int calculate_dimes(int remain)
{
    int coin = remain / 10;
    return (coin);
}

int calculate_nickels(int remain)
{
    int coin = remain / 5;
    return (coin);
}

int calculate_pennies(int remain)
{
    int coin = remain;
    return (coin);
}

int main(void)
{
    int d = get_cents();
    int coin;
    int remain;

    coin = calculate_quarters(d);
    remain = d % 25;
    d  = remain;
    coin += calculate_dimes(remain);
    remain = d % 10;
    d  = remain;
    coin += calculate_nickels(remain);
    remain = d % 5;
    d  = remain;
    coin += calculate_pennies(remain);



    printf("Coins: %i\n", coin);

}

int get_cents(void)
{
    int c;
    do
    {
        c = get_int("Change owed: \n");
    }
    while (c < 0);
    return c;
}

