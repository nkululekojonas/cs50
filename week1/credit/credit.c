#include <cs50.h>
#include <stdio.h>

// Function prototypes
int calculate_checksum(long number);
int sum_of_product(int number);
bool is_valid(int number);

int main(void)
{
    // Constiously prompt the user for a valid type long
    long number;
    do 
    {
        number = get_long("Card Number: ");
    }
    while (number < 0);

    // Define card variables
    bool valid;
    int checksum;
    string card;

    // Calculate the check the checksum
    checksum = calculate_checksum(number);
    printf("checksum: %i\n", checksum);

    // Check for card for validity i.e correct length and starting digit
    if (checksum % 10 != 0)
    {
        printf("INVALID\n");
    } else 
    {
        // Print the credit card type
        printf("VALID");
    }
}

// Return the checksum value for a given credit number
int calculate_checksum(long number)
{
    // Initial variables
    int sum = 0;
    int position = 0;

    while (number > 0)
    {
        // Get and remove the current digit
        int digit = number % 10;
        number /= 10;

        // Check if position is odd and either multiply by 2 and add to sum or pass
        if ((position % 2) == 1)
        {
            // Calculate the value for digit and sum of their product
            sum += sum_of_product(digit * 2);
        } else 
        {
            sum += digit;
        }

        // Move a position 
        position++;
    }

    return sum;
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
