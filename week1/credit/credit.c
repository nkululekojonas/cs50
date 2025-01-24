#include <cs50.h>
#include <stdio.h>

// Function prototypes
int calculate_checksum(long number);
int sum_of_product(int number);
void print_card(int number, int lengt);

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
    int length = 0;
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
        length++;
        position++;
    }

    // Check for card for validity i.e correct length and starting digit
    if (sum % 10 != 0 || (length != 13 && length != 15 && length != 16))
    {
        printf("INVALID\n");
        return 0;
    } 
    
    // Show the card
    print_card(leading_num, length);
}

void print_card(int number, int length)
{
    if (number / 10 == 4 || (number == 4 && length == 13))
    {
        printf("VISA\n");
    }
    else if (number == 34 || number == 37)
    {
        printf("AMEX\n");
    }
    else if (number >= 51 && number <= 55)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
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

