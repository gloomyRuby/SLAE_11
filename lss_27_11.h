//
// Created by Oysha on 18/02/2018.
//

#ifndef LSS_27_11_LSS_27_11_H
#define LSS_27_11_LSS_27_11_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#pragma warning (4996:disable)

#define sgn(a)  ((a) > 0 ? (1) : -(1))
#define abs(a)  ((a) > 0 ? (a) : -(a))

int lss_27_11(int n, double* A, double* B, double* X, double* tmp);
int lss_memsize_27_11(int n);
void transpose(int n, double **A);

void solve();

#endif //LSS_27_11_LSS_27_11_H
