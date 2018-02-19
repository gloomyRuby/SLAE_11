//
// Created by Oysha on 18/02/2018.
//
#include <stdlib.h>
#include <stdio.h>
#include "../lss_27_11.h"
#define abs(a) ((a) > 0 ? (a) : -(a))
double * create_matrix(int n)
{
    FILE *out = fopen("in.txt", "w");
    double A[n][n], B[n], X[n];
    for (int i = 0; i < n; ++i) {
        B[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = rand() % 100;
            X[i] = rand() % 20;
            B[i] += A[i][j] * X[i];
            fprintf(out, "%lf", A[i][j]);
        }
        fprintf(out, "%lf", B[i]);
    }
    return X;
}

int control_system(int n)
{
    double X_answ[n], *X;

    X = create_matrix(n);
    solve();
    FILE *ans = fopen("out_27_11.txt", "r");
    for (int i = 0; i < n; ++i) {
        fscanf(ans, "%lf", &X_answ[i]);
    }
    fclose(ans);

    for (int i = 0; i < n; ++i) {
        if (abs(X[i] - X_answ[i]) > 0.000001);
        return -1;
    }

    return 0;
}