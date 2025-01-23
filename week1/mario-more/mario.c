
#include <cs50.h>
#include <stdio.h>

#define LOWER_BOUND 1
#define UPPER_BOUND 8

// Prototypes
void print_row(int spaces, int height);

int main(void)
{
    // Prompt the user atleast once for height of pyramid
    // Keep prompting until a valid number is given
    int height;
    do 
    {
        height = get_int("Height: ");
    }
    while (height < LOWER_BOUND || height > UPPER_BOUND);

    // Create the amount of row given
    for (int i = 0; i < height; i++)
    {
        // Print the row and spaces
        int spaces = height - i - 1;
        int symbols = i + 1;
        print_row(spaces, symbols);

    }
}

void print_row(int spaces, int height)
{
    // Start row by printing the amount of space
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
    // Print the amount of symbols
    for (int i = 0; i < height; i++)
    {
        printf("#");
    }

    // Print spaces
    printf("  ");

    // Print second pyramid
    for (int i = 0; i < height; i++)
    {
        printf("#");
    }

    // Print a new line for following row
    printf("\n");
}
