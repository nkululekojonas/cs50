#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

// Define size or elements to search
#define SIZE 1000000

// Binary Search Algorithim
int binary_search(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        // Find the find point
        int mid = left + (right - left) / 2;

        // Check if target is greater or less than mid point
        if (arr[mid] == target) { return mid; } 
        if (arr[mid] < target) return left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <target>\n", argv[0]);
        return 1;
    }

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

    int target = atoi(argv[1]);

    int index = binary_search(numbers, SIZE, target);
    if (index != -1)
        printf("Found at index: %d\n", index);
    else
        printf("Not found\n");

    return 0;
}
