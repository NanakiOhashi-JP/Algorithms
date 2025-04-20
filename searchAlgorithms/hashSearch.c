// Search Algorithms
// Hash Search
// Time Complexity: O(1)

#include <stdio.h>
#include <stdlib.h>

// Maros
/* here */

// Hash Table
typedef struct HashNode
{
    int key;
    int value;
    struct HashNode *next;
} HashNode;

typedef struct HashTable
{
    int size;
    HashNode **table;
} HashTable;

// Prototype
// Functions are defined after main()
void printArray(int arr[], int arr_size);
int hashSearch(int arr[], int arr_size, int target);
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
    int result = hashSearch(arr, arr_size, target /* = 5 */);

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

int hashSearch(int arr[], int arr_size, int target)
{
    if (arr == NULL || arr_size <= 0)
    {
        return -1; // Invalid array size
    }

    // Create a hash table
    HashTable *hashTable = malloc(sizeof(HashTable));
    hashTable->size = arr_size;
    hashTable->table = malloc(arr_size * sizeof(HashNode *));
    for (int i = 0; i < arr_size; i++)
    {
        hashTable->table[i] = NULL;
    }

    // Insert elements into the hash table
    for (int i = 0; i < arr_size; i++)
    {
        HashNode *newNode = malloc(sizeof(HashNode));
        newNode->key = arr[i];
        newNode->value = i;
        newNode->next = hashTable->table[arr[i] % arr_size];
        hashTable->table[arr[i] % arr_size] = newNode;
    }

    // Search for the target element
    int index = target % arr_size;
    HashNode *node = hashTable->table[index];
    while (node != NULL)
    {
        if (node->key == target)
        {
            return node->value; // Target found
        }
        node = node->next;
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