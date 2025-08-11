/*Aim of the program: Write a program to read ‘n’ integers from a disc file that must contain
some duplicate values and store them into an array. Perform the following operations on the
array.
a) Find out the total number of duplicate elements.
b) Find out the most repeating element in the array.*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    int n, i;
    int *arr;

    fp = fopen("input2.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    fscanf(fp, "%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        fclose(fp);
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);

    printf("Elements in the array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    int count[100] = {0}; // Assuming elements are in 0-99
    int maxCount = 0, totalDuplicates = 0;

    for (i = 0; i < n; i++)
    {
        count[arr[i]]++;
        if (count[arr[i]] > maxCount)
        {
            maxCount = count[arr[i]];
        }
    }

    // Calculate total duplicates
    for (i = 0; i < 100; i++)
    {
        if (count[i] > 1)
        {
            totalDuplicates += count[i] - 1;
        }
    }

    printf("\nTotal number of duplicate elements: %d", totalDuplicates);

    if (maxCount == 1)
    {
        printf("\nNo repeating elements.\n");
    }
    else
    {
        printf("\nMost repeating element(s): ");
        for (i = 0; i < 100; i++)
        {
            if (count[i] == maxCount)
            {
                printf("%d ", i);
            }
        }
        printf("(repeats %d times)\n", maxCount);
    }

    free(arr);
    return 0;
}