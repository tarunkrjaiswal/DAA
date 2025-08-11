/*Aim of the program: Given an array arr[] of size N, find the prefix sum of the array. A prefix
sum array is another array prefixSum[] of the same size, such that the value of prefixSum[i] is
arr[0] + arr[1] + arr[2] . . . arr[i].
Input Array: 3 4 5 1 2
Output Array: 3 7 12 13 15*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    int *arr, *prefixSum;

    // Read the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Check if n is positive
    if (n <= 0)
    {
        printf("Array size must be a positive integer.\n");
        return 1;
    }

    // Allocate memory for the array
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read elements into the array
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Allocate memory for the prefix sum array
    prefixSum = (int *)malloc(n * sizeof(int));
    // Calculate prefix sums
    prefixSum[0] = arr[0];
    for (i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    printf("Prefix Sum is \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", prefixSum[i]);
    }
    
    // Free allocated memory
    free(arr);
    free(prefixSum);

    return 0;
}


