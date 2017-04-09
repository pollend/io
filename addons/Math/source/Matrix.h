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


#ifdef __cplusplus
}
#endif

#endif //IOLANGUAGE_MATRIX_H
