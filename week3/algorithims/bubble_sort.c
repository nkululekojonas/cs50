#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000000

int main()
{
    // Intialise unsorted list
    int numbers[SIZE];
    FILE *file = fopen("numbers.txt", "r");
    if (!file) {
        printf("Error opening file\n");
        return 1;
    }

    for (int i = 0; i < SIZE; i++) {
        fscanf(file, "%d", &numbers[i]);
    }
    fclose(file);

    // Use Bubble Sort to sort the list
    // Set swap counter
    int i = 0;
    int swap = -1;

    // Iterate other elements to comapre
    do
    {
        // Reset swap for every pass
        swap = 0; 

        for (int j = 0; j < SIZE - 1 - i; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
                swap++;
            }
        }
        i++;
    }
    while (swap != 0);
}

