#include <stdio.h>

// Collatz function 
int collatz(int n)
{
    if (n <=1)
        return 0;
    else if (n % 2 == 0)
        return 1 + collatz( n / 2);
    else 
        return 1 +  collatz((3 * n) + 1);
}

int main()
{

    int num;
    printf("Enter a number: ");
    if(scanf("%d", &num) <= 0)
    {
        printf("Invalid input.\n");
        return 1;
    }
    
    // Calculate collatz number
    printf("Collatz: %d\n", collatz(num));
}
