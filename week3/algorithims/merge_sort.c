#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000000

// Merge sorte lists
void merge_sorted_array(int a[], int left, int mid, int right)
{
    // Get lengths of sides
    int left_length = mid - left + 1; // 4 - 0 + 1 = 5
    int right_length = right - mid;   // 9 - 4 = 5

    // Temp values
    int temp_left[left_length];
    int temp_right[right_length];

    // Copy values to temp
    for (int i = 0; i < left_length; i++)
        temp_left[i] = a[left + i];

    for (int i = 0; i < right_length; i++)
        temp_right[i] = a[mid + 1 + i];

    int i, j, k;
    for(i = 0, j = 0, k = left; k <= right; k++)
    {
        if ((i < left_length) && (j >= right_length || temp_left[i] < temp_right[j]))
        {
           a[k] = temp_left[i];
           i++;
        } 
        else 
        {
            a[k] = temp_right[j];
            j++;
        }
    }
}

// Merge sort
void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        // Merge sorted lists
        merge_sorted_array(arr, left, mid, right);
    }
}

int main()
{
    // Define unsorted list
    int numbers[SIZE];
    
    // Read numbers from file
    FILE *file = fopen("numbers.txt", "r");
    if (file == NULL)
    {
        printf("Invalid inputs.\n");
        return 1;
    }
    
    for (int i = 0; i < SIZE; i++)
    {
        fscanf(file, "%d", &numbers[i]);
    }
    fclose(file);
    
    // Sort the list
    merge_sort(numbers, 0, SIZE - 1);

    FILE *w_file = fopen("sorted.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file");
        return 1;
    }
    // Print sorted list
    for (int i = 0; i < SIZE; i++)
    {
        fprintf(w_file, "%d\n", numbers[i]);
    }
    fclose(w_file);
    printf("File sorted\n");

    // Exit gracefully
    return 0;
}
