#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BIN_WIDTH 16

// Recursive function to convert decimal to binary string (two's complement for negatives)
void decToBin(unsigned short n, char *bin, int idx) {
    if (idx < 0) return;
    bin[idx] = (n % 2) ? '1' : '0';
    decToBin(n / 2, bin, idx - 1);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <n> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    char *input_file = argv[2];
    char *output_file = argv[3];

    FILE *fin = fopen(input_file, "r");
    if (!fin) {
        perror("Error opening input file");
        return 1;
    }

    FILE *fout = fopen(output_file, "w");
    if (!fout) {
        perror("Error opening output file");
        fclose(fin);
        return 1;
    }

    int count = 0, num;
    while (count < n && fscanf(fin, "%d", &num) == 1) {
        char bin[BIN_WIDTH + 1] = {0};
        decToBin((unsigned short)num, bin, BIN_WIDTH - 1);
        bin[BIN_WIDTH] = '\0';
        fprintf(fout, "The binary equivalent of %d is %s\n", num, bin);
        count++;
    }

    fclose(fin);
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
