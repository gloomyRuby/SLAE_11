//
// Created by Oysha on 18/02/2018.
//

#include "lss_27_11.h"


int main() {

    int n;
    FILE *input = fopen("in.txt", "r");
    fscanf(input, "%d", &n);

    double A[n * n], B[n], X[n], tmp[2 * lss_memsize_27_11(n)];

    for (int i = 0; i < n * n; ++i) {
        fscanf(input, "%lf", A + i);
    }
    for (int k = 0; k < n; ++k) {
        fscanf(input, "%lf", B + k);
    }
    fclose(input);

    clock_t begin = clock();
    int answ = lss_27_11(n, A, B, X, tmp);
    clock_t end = clock();
    double time = (double)(end - begin) / CLOCKS_PER_SEC;

    FILE *output = fopen("out_27_11.txt", "w");
    if (answ == 0) {
        fprintf(output, "%d\n", n);
        for (int i = 0; i < n; ++i) {
            fprintf(output, "%lf\n", X[i]);
        }
    } else if (answ == 1) {
        fprintf(output, "0");
    } else {
        fprintf(output, "-1");
    }
    fclose(output);

    return 0;
}

