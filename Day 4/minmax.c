#include <stdio.h>

struct Pair {
    int min;
    int max;
};

struct Pair MinMax(int a[], int i, int j) {
    struct Pair result, left, right;

    // Base case: only one element
    if (i == j) {
        result.min = a[i];
        result.max = a[i];
        return result;
    }
    // Base case: two elements
    if (i == j - 1) {
        if (a[i] < a[j]) {
            result.min = a[i];
            result.max = a[j];
        } else {
            result.min = a[j];
            result.max = a[i];
        }
        return result;
    }

    // Divide the array
    int mid = (i + j) / 2;

    // Conquer
    left = MinMax(a, i, mid);
    right = MinMax(a, mid + 1, j);

    // Combine results
    result.min = (left.min < right.min) ? left.min : right.min; //result.min=left.min if true
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    struct Pair ans = MinMax(a, 0, n - 1);

    printf("Minimum element: %d\n", ans.min);
    printf("Maximum element: %d\n", ans.max);

    return 0;
}
