// Search Algorithms
// Linear Search
// Time Complexity: O(n)

#include <stdio.h>
#include <stdlib.h>

// Maros

// Prototype
// Functions are defined after main()
void printArray(int arr[], int arr_size);
int linearSearch(int arr[], int arr_size, int target);
int inputTarget();
void printResult(int arr[], int arr_size, int target, int result);

// Main function
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr_size = sizeof(arr) / sizeof(arr[0]); // arr_size = 10 in this case

    printf("Array: ");
    printArray(arr, arr_size);

    int target = inputTarget();
    int result = linearSearch(arr, arr_size, target /* = 5 */);

    printResult(arr, arr_size, target, result);
}

// From here, define the functions which are declared above
void printArray(int arr[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int inputTarget()
{
    int target;
    printf("Enter the target element to search for: ");
    scanf("%d", &target);
    return target;
}

int linearSearch(int arr[], int arr_size, int target)
{
    // Add a sentinel value at the end of the array ("番兵")
    int sentinelIsHere_index = target;
    arr[sentinelIsHere_index] = target;
    int i = 0;

    while (arr[i] != target)
    {
        i++;
    }

    if (i == sentinelIsHere_index)
    {
        return -1; // Target not found
    }
    else
    {
        return i; // Target found at index i
    }

    return 0;
}

void printResult(int arr[], int arr_size, int target, int result)
{
    if (result != -1)
    {
        printf("Element %d found at index %d\n", target, result);
    }
    else
    {
        printf("Element %d not found in the array\n", target);
    }
}