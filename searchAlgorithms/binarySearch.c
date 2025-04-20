// Search Algorithms
// Binary Search
// Time Complexity: O(log n)

#include <stdio.h>
#include <stdlib.h>

// Maros
/* here */

// Prototype
// Functions are defined after main()
void printArray(int arr[], int arr_size);
int binarySearch(int arr[], int arr_size, int target);
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
    int result = binarySearch(arr, arr_size, target /* = 5 */);

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

int binarySearch(int arr[], int arr_size, int target)
{
    if (arr == NULL || arr_size <= 0)
    {
        return -1; // Invalid array size
    }

    int begin = 0;
    int end = arr_size - 1;

    while (begin <= end)
    {
        int mid = begin + (end - begin) / 2;
        if (arr[mid] == target)
        {
            return mid; // Target found
        }
        else if (arr[mid] < target)
        {
            begin = mid + 1; // Search in the right half
        }
        else
        {
            end = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found
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