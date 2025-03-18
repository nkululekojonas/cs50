#include <cs50.h>
#include <stdio.h>

// Function protoypes
int factorial(int num);

int main()
{
   // Get a number
   int num = get_int("Enter a number: ");
   printf("%i\n", factorial(num));
}

// Take a number and return the factoiral
int factorial(int num)
{
    // Base case 1! = 1
    if (num <= 1) 
    {
        return 1;
    }
    
    return num * factorial(num - 1);
}
