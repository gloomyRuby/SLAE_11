#include "lss_27_11.h"

void transpose(int n, double *A);

int is_symmetric(int n, double *A);

int lss_27_11(int n, double *A, double *B, double *X, double *tmp) {

    // Cholesky decomposition works only with symmetric matrix
    if (is_symmetric(n, A) != 0)
        return -1;

    double  temp, sum = 0;

    // tmp[0..n-1] is d matrix
    // tmp[n..2n-1] is Y matrix
    // A = St * tmp * S
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < i; ++k) {
            sum += A[k * n + i] * A[k * n + i] * tmp[k];
        }
        tmp[i] = sgn(A[i * n + i] - sum);
        sum = 0;

        for (int j = 0; j < n; ++j) {
            if (i == j) {
                for (int k = 0; k < i; ++k) {
                    sum += A[k * n + i] * A[k * n + i] * tmp[k];
                }
                temp = sqrt(abs(A[i * n + i] - sum));
                A[i * n + i] = temp;
                sum = 0;
            } else if (i < j) {
                for (int k = 0; k < i; ++k) {
                    sum += A[k * n + i] * tmp[k] * A[k * n + j];
                }
                if (A[i * n + i] * tmp[i] != 0)
                    temp = (A[i * n + j] - sum) / A[i * n + i] * tmp[i];
                else
                    return 1;
                A[i * n + j] = temp;
                sum = 0;
            } else {
                A[i * n + j] = 0;
            }
        }
    }

    // St * tmp = b
    transpose(n, A);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            sum += A[i * n + j] * tmp[n + j] * tmp[j];
        }
        if (A[i * n + i] * tmp[i] != 0)
        tmp[n + i] = (B[i] - sum) / A[i * n + i] * tmp[i];
        else
            return 1;
        sum = 0;
    }

    // tmp * S * X = tmp
    transpose(n, A);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; --j) {
            sum += A[i * n + j] * X[j];
        }
        if (A[i * n + i] != 0)
        X[i] = (tmp[n + i] - sum) / A[i * n + i];
        else
            return 1;
        sum = 0;
    }

    return 0;
}

int lss_memsize_27_11(int n) {
    return n;
}

void transpose(int n, double *A)
{
    double  tmp;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            tmp = A[j * n + i];
            A[j * n + i] = A[i * n + j];
            A[i * n + j] = tmp;
        }
    }
}

int is_symmetric(int n, double *A)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i *n + j] != A[j * n + i])
                return 1;
        }
    }

    return 0;
}
