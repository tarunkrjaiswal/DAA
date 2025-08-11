/*Aim of the program: Write a function to ROTATE_RIGHT (p1, p2) right an array for first p2
elements by 1 position using EXCHANGE (p, q) function that swaps/exchanges the numbers p
& q. Parameter p1 be the starting address of the array and p2 be the number of elements to be
rotated.
Input:
Enter an array A of size N (9): 11 22 33 44 55 66 77 88 99
Call the function ROTATE_RIGHT (A, 5)
Output:
Before ROTATE: 11 22 33 44 55 66 77 88 99
After ROTATE: 55 11 22 33 44 66 77 88 99
*/
#include <stdio.h>
#include <stdlib.h>
void exchange(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void rotate_right(int *p1, int p2) {
    if (p2 <= 0) return; // No rotation needed for 0 or negative p2
    int last = *(p1 + p2 - 1); // Store the last element to be rotated
    for (int i = p2 - 1; i > 0; i--) {
        exchange(p1 + i, p1 + i - 1); // Shift elements to the right
    }
    *p1 = last; // Place the last element at the start
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int p2;
    printf("Enter the number of elements to rotate: ");
    scanf("%d", &p2);

    printf("Before ROTATE: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    rotate_right(arr, p2);

    printf("After ROTATE: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}