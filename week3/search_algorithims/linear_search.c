#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000000

int linear_search(int arr[], int size, int target)
{
    // Search through every element in list until target is found
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == target) 
        {
            return i; // Found at index i
        }
    }
    
    // Not found
    return -1;
}

int main(int argc, char *argv[])
{
    // Validate inputs
    if (argc != 2)
    {
        // Print usage instructions
        printf("Usage: %s <target>\n", argv[0]);
        return 1;
    }
   
    // Read numbers from file
    int numbers[SIZE];
    FILE *file = fopen("numbers.txt", "r");

    if (!file)
    {
        printf("Error reading file\n");
        return 2;
    }

    for (int i = 0; i < SIZE; i++)
    {
        fscanf(file, "%d", &numbers[i]);
    }
    fclose(file);

    // Attempt to find target
    int target = atoi(argv[1]);

    int index = linear_search(numbers, SIZE, target);
    if (index != -1)
        printf("Found at Index: %d\n", index);
    else 
        printf("Target not found\n");

    return 0;
}
