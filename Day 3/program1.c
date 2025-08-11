
#include<stdio.h>
#include<stdlib.h>
int count=0; //For counting number of iterations

void ins_sort(int a[],int n){ // Insertion sort
    for (int j = 1; j < n; j++) {
        int temp = a[j];
        int i = j - 1;
        count++;
        while (i >= 0 && a[i] > temp) {
            a[i + 1] = a[i];
            i--;
            count++;
        }
        a[i + 1] = temp;
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    ins_sort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("loop runs for %d times\n", count);
    return 0;

    }
    