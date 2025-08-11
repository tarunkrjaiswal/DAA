#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0; // For counting number of iterations

void ins_sort(int a[], int n) { 
    // Insertion sort
    for (int j = 1; j < n; j++) {
        count++; 
        // for-loop iteration
        int temp = a[j];
        int i = j - 1;
        while (i >= 0 && a[i] > temp) {
            count++; 
            // while-loop iteration
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = temp;
    }
}

int main() {
    FILE *inFile1 = fopen("input.txt", "w");
    if (inFile1 == NULL) {
        printf("Error opening input file for writing.\n");
        return 1;
    }

    //srand(time(NULL)); // Seed the random number generator

    for (int i = 0; i < 300; i++) { // Generating random numbers from 1 to 300
        int num = (rand() % 300) + 1;
        fprintf(inFile1, "%d ", num);
    }
    fclose(inFile1);

    FILE *inFile = fopen("input.txt", "r");
    if (inFile == NULL) {
        printf("Error opening input file for reading.\n");
        return 1;
    }

    int arr[300], n = 0;
    while (fscanf(inFile, "%d", &arr[n]) == 1 && n < 300) {
        n++;
    }
    fclose(inFile);

    ins_sort(arr, n);

    // Write sorted array and iteration count to output.txt
    FILE *resultFile = fopen("output.txt", "a");
    if (resultFile == NULL) {
        printf("Error opening output file for writing.\n");
        return 1;
    }
    fprintf(resultFile, "Sorted array:\n");
    for (int i = 0; i < n; i++) {
        fprintf(resultFile, "%d ", arr[i]);
    }
    fprintf(resultFile, "\nTotal iterations (for + while): %d\n", count);
    fprintf(resultFile, "\n");
    fclose(resultFile);

    printf("Total iterations (for + while): %d\n", count);

    return 0;
}
