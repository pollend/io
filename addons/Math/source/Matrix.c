//
// Created by michaelpollind on 4/8/17.
//

#include "Base.h"

#include "Matrix.h"

Matrix *Matrix_new(int size1,int size2)
{
    Matrix *self = (Matrix *)io_calloc(1, sizeof(Matrix));

    double* data = (double*)io_calloc(size1*size2,sizeof(double));
    self->data = data;
    self->size1 = size1;
    self->size2 = size2;
    return  self;
}


void Matrix_free(Matrix* matrix)
{
    io_free(matrix->data);
    io_free(matrix);
}




