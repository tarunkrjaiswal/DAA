
 
#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int n, int binary[], int *index)
{
    if (n > 0) {
        decimalToBinary(n / 2, binary, index);
        binary[(*index)++] = n % 2;
    }
}

int main()
{
int n;
FILE *inFile;
inFile = fopen("input1.txt", "r"); // fopen returns the address of the first element of the file
    if (inFile == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
while(fscanf(inFile, "%d", &n) == 1) // Read integers from the file until EOF
    {
        int binary[32] = {0}; // Array to store binary representation
        int num = n; // Original number for output
        int index = 0;

        // Convert decimal to binary using recursion
        decimalToBinary(n, binary, &index);

        // Open output file in append mode
        FILE *outFile = fopen("output1.txt", "a");
        if (outFile == NULL) {
            printf("Error opening output file.\n");
            fclose(inFile);
            return 1;
        }

        // Print the binary representation to the console
        printf("The binary equivalent of %d is ", num);
        for (int j = 0; j < 16; j++) {
            if (j < 16 - index) {
            printf("0");
            } else {
            printf("%d", binary[j - (16 - index)]);
            }
        }
        printf("\n");

        // Write the binary representation to the output file
        fprintf(outFile, "The binary equivalent of %d is ", num);
        for (int j = 0; j < 16; j++) {
            if (j < 16 - index) {
            fprintf(outFile, "0");
            } else {
            fprintf(outFile, "%d", binary[j - (16 - index)]);
            }
        }
        fprintf(outFile, "\n");
        fclose(outFile);
        }
        fclose(inFile);
        return 0;
}
