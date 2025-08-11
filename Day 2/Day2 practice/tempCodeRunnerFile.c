#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 200

// Recursive function to find GCD
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];

    FILE *fin = fopen(input_file, "r");
    if (!fin) {
        perror("Error opening input file");
        return 1;
    }

    int nums[MAX_NUMBERS], count = 0;
    while (count < MAX_NUMBERS && fscanf(fin, "%d", &nums[count]) == 1) {
        count++;
    }
    fclose(fin);

    if (count < 2 || count % 2 != 0) {
        printf("Source file must contain an even number of elements (at least 2).\n");
        return 1;
    }

    FILE *fout = fopen(output_file, "w");
    if (!fout) {
        perror("Error opening output file");
        return 1;
    }

    // Process all pairs
    for (int i = 0; i < count; i += 2) {
        int result = gcd(nums[i], nums[i+1]);
        fprintf(fout, "The GCD of %d and %d is %d\n", nums[i], nums[i+1], result);
    }
    fclose(fout);

    // Display output file contents
    fout = fopen(output_file, "r");
    if (!fout) {
        perror("Error opening output file for reading");
        return 1;
    }
    char line[100];
    while (fgets(line, sizeof(line), fout)) {
        printf("%s", line);
    }
    fclose(fout);

    return 0;
}
