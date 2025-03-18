#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000000  // Define array size
    
int main()
{
    // Initialize unsorted list
    int numbers[SIZE];
    FILE *file = fopen("numbers.txt", "r");
    if (!file) {
        printf("Error opening file\n");
        return 1;
    }

    // Read numbers from file into array
    for (int i = 0; i < SIZE; i++) {
        fscanf(file, "%d", &numbers[i]);
    }
    fclose(file);

    // Selection Sort
    for (int i = 0; i < SIZE - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < SIZE; j++)
        {
            if (numbers[j] < numbers[minIndex])
            {
                minIndex = j;
            }
        }
        
        if (minIndex != i)
        {
            int temp = numbers[i];
            numbers[i] = numbers[minIndex];
            numbers[minIndex] = temp;
        }
    }

    // Print out list
    printf("Sorted array (first 10 elements): ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
