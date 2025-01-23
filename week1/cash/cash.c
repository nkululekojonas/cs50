#include <cs50.h>
#include <stdio.h>

// Define coin values
#define QUATER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1

// Function prototypes
int calc_quaters(int amount);
int calc_dimes(int amount);
int calc_nickels(int amount);
int calc_pennies(int amount);

int main(void)
{
    // Continuosly prompt the user for the amount owed until they enter number > 0
    int change;
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 0);

    // Keep a running total of the amount of coins that will be needed staring at 0
    int total = 0, quaters = 0, dimes = 0, nickels = 0, pennies = 0;

    // While change is greater than 0 keep testing which coins can fit
    while (change > 0)
    {
        // Calculate how many 25's can go into change and update change with remainder
        quaters = calc_quaters(change);
        change = change % QUATER;

        // Calculate how many 10's can go into change and update change with remainder
        dimes = calc_dimes(change);
        change = change % DIME;

        // Calculate how many 5's can go into change and update change with remainder
        nickels = calc_nickels(change);
        change = change % NICKEL;

        // Calculate how many 1's can go into change and update change with remainder
        pennies = calc_pennies(change);
        change = change % PENNY;
    }
    // Return total amount 
    total = quaters + dimes + nickels + pennies;

    // Return updated value of total 
    printf("Total: %i\n", total);
}

// Calculate how ma=ny quaters can go into a given amount
int calc_quaters(int amount)
{
    int total = 0;
    while (amount >= QUATER)
    {
        total++;
        amount -= QUATER;
    }

    return total;
}

// Calc dimes
int calc_dimes(int amount)
{
    int total = 0;
    while (amount >= DIME)
    {
        total++;
        amount -= DIME;
    }

    return total;
}

// Calc nickels
int calc_nickels(int amount)
{
    int total = 0;
    while (amount >= NICKEL)
    {
        total++;
        amount -= NICKEL;
    }

    return total;
}

// Calc pennies
int calc_pennies(int amount)
{
    int total = 0;
    while (amount >=  PENNY)
    {
        total++;
        amount -= PENNY;
    }

    return total;
}
