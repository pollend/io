//
// Created by michaelpollind on 4/8/17.
//

#ifndef IOLANGUAGE_MATRIX_H
#define IOLANGUAGE_MATRIX_H

#include "Common.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    size_t size1;
    size_t size2;
    double* data;
} Matrix;

Matrix *Matrix_new(int size1,int size2);
void Matrix_free(Matrix* matrix);
Matrix* Matrix_clone(Matrix* matrix);

Matrix* Matrix_add(Matrix* m1, Matrix* m2);
Matrix* Matrix_subtract(Matrix* m1, Matrix* m2);
Matrix* Matrix_multiply(Matrix* m1, Matrix* m2);

double Matrix_at_(Matrix* m1,int x, int y);
void Matrix_put_(Matrix* m1,int x, int y, double value);

Matrix* Matrix_transpose(Matrix* m1);
#ifdef __cplusplus
}
#endif

#endif //IOLANGUAGE_MATRIX_H
