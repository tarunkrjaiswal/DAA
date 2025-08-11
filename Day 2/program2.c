/*.3 Aim of the program: Write a program in C to find GCD of two numbers using recursion.
Read all pair of numbers from a file and store the result in a separate file.
Note# Source file name and destination file name taken from command line arguments. The
source file must contain at least 20 pairs of numbers.
Give the contents of the input disc file “inGcd.dat” as 8 12 20 45 30 80
Contents of the output disc file “outGcd.dat” as
The GCD of 8 and 12 is 4
The GCD of 20 and 45 is 5
The GCD of 30 and 80 is 10
Terminal Input:
$gcc lab2q2.c -o lab2q2
$./lab2q2 inGcd.dat outGcd.dat
Output: Display the gcd stored in the output file outGcd.dat
*/
#include <stdio.h>
#include <stdlib.h>

// Recursive function to find GCD
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int a, b;
    FILE *inFile;
    inFile = fopen("input2.txt", "r");
    if (inFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    while (fscanf(inFile, "%d %d", &a, &b) == 2) {
        int result = gcd(a, b);

        // Open output file in append mode
        FILE *outFile = fopen("output2.txt", "a");
        if (outFile == NULL) {
            printf("Error opening output file.\n");
            fclose(inFile);
            return 1;
        }

        // Print the GCD to the console
        printf("The GCD of %d and %d is %d\n", a, b, result);

        // Write the GCD to the output file
        fprintf(outFile, "The GCD of %d and %d is %d\n", a, b, result);

        fclose(outFile);
    }
    fclose(inFile);
    return 0;
}