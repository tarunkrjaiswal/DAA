/* Aim of the program: Write a program to find out the second smallest and second largest element stored in an array of n integers.
 Input: Size of the array is ‘n’ and read ‘n’ number of elements from a disc file.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    int n, i;
    int *arr;

    // opening the file in read mode
    fp = fopen("input1.txt", "r"); // fopen returns the address of the first element of the file
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    // reading the size of the array
    fscanf(fp, "%d", &n);

    //allocate memory for the array
    arr = (int *)malloc(n * sizeof(int)); //sizeof(int) returns the size of an integer in bytes
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        fclose(fp);
        return 1;
    }

    //read elements into the array
    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp); // close the file after reading

    //print the elements of the array
    printf("Elements in the array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    //2nd smallest and 2nd largest elements

    int largest = arr[0], second_largest = arr[0];
    int smallest = arr[0], second_smallest = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            second_smallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] < second_smallest && arr[i] != smallest)
        {
            second_smallest = arr[i];
        }

        if (arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] > second_largest && arr[i] != largest)
        {
            second_largest = arr[i];
        }
    }
        printf("\nSecond Largest: %d",second_largest);
        printf("\nSecond Smallest: %d",second_smallest);
    }
    

    
    