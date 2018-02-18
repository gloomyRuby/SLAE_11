#include "lss_27_11.h"


int lss_27_11(int n, double* A, double* B, double* X, double* tmp) {


    return 0;
}


int lss_memsize_27_11(int n) {
    return n;
}

void transpose(int n, double **A)
{
    double  tmp;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            tmp = A[j][i];
            A[j][i] = A[i][j];
            A[i][j] = tmp;
        }
    }
