#include <cs50.h>
#include <stdio.h>

void print_row(int count, char item);

int main(void)
{
    int height;
    char item;
    do 
    {
        height = get_int("What is the height of the pyramid? ");
    } 
    while ( height < 1 );
    item = get_char("Enter a character for your pyrmaid: ");

    // Print pyramid onto the screen 
    for(int i = 0; i < height; i++)
    {
        print_row(i + 1, item);
    }
}

void print_row(int count, char item)
{
    // Repeat print for number of items
    for(int i = 0; i < count; i++)
    {
        printf("%c", item);
    }

    printf("\n");
}
