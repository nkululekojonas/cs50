#include <cs50.h>
#include <stdio.h>

// Define coin values
#define QUATER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1

int main(void)
{
    // Continuosly prompt the user for the amount owed until they enter number > 0
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    // Keep a running total of the amount of coins that will be needed staring at 0
    int total = 0;

    // Calculate how many 25's can go into cents and update cents with remainder
    // total += calc_quaters(cents);
    total += cents / QUATER;
    cents = cents % QUATER;

    // Calculate how many 10's can go into cents and update cents with remainder
    // total += calc_dimes(cents);
    total += cents / DIME;
    cents = cents % DIME;

    // Calculate how many 5's can go into cents and update cents with remainder
    // total += calc_nickels(cents);
    total += cents / NICKEL;
    cents = cents % NICKEL;

    // Calculate how many 1's can go into cents and update cents with remainder
    // total += calc_pennies(cents);
    total += cents / PENNY;

    // Return updated value of total 
    printf("Total: %i\n", total);
}
