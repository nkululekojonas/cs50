#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int calculate_checksum(long number);
int sum_of_product(int number);
void print_card(int number);

int main(void)
{
    // Constiously prompt the user for a valid type long
    long number;
    do 
    {
        number = get_long("Card Number: ");
    }
    while (number < 0);

    // Initial variables
    int sum = 0;
    int position = 0;
    int leading_num;

    while (number > 0)
    {
        // Get and remove the current digit
        int digit = number % 10;
        number /= 10;

        // Check if position is odd and either multiply by 2 and add to sum or pass
        if ((position % 2) != 0)
        {
            // Calculate the value for digit and sum of their product
            sum += sum_of_product(digit * 2);
        } else 
        {
            sum += digit;
        }
        
        // Get first two digits when in range
        if (number > 10 && number < 100)
        {
            leading_num = number;
        }

        // Move a position 
        position++;
    }

    // Check for card for validity i.e correct length and starting digit
    if (sum % 10 == 0)
    {
        if (leading_num / 10 == 4)
        {
            leading_num = 4;
        }
        
        // Show the card
        print_card(leading_num);
    } 
    else 
    {
        // Card not valid
        printf("INVALID\n");
    }
}

void print_card(int number)
{
    switch (number)
    {
        case 4:
            printf("Visa\n");
            break;
        case 34:
        case 37:
            printf("American Express\n");
            break;
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
            printf("Mastercard\n");
            break;
    }
}   

int sum_of_product(int number)
{
    // Inital values
    int sum = 0;

    // Go over every digit in te number
    while (number > 0)
    {
        // Get and remove the digit
        int digit = number % 10;
        number /= 10;

        sum += digit;
    }
    return sum;
}

