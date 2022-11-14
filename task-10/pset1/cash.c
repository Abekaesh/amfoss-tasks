#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // prompt the user to input the change owed in dollars 
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
        
    }
    
    while (!(dollars > 0));
    // converting dollars to cents
    int cents = round(dollars * 100);
    int coins = 0;

    while (cents != 0)
    {
        //denomination of quarters
        coins += cents / 25;
        cents = cents % 25;
        
        // denomination of dimes 
        coins += cents / 10;
        cents = cents % 10;
        
        //denomination of nickels
        coins += cents / 5;
        cents = cents % 5;
        
        //denomination of pennies
        coins += cents / 1;
        cents = cents % 1;
    }
    printf("%d\n", coins);
    
}
