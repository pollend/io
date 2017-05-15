//
// Created by michaelpollind on 4/8/17.
//

#include "Matrix.h"

Matrix *Matrix_new(int size1,int size2)
{
    Matrix *self = (Matrix *)io_calloc(1, sizeof(Matrix));

    double* data = (double*)io_calloc(1,sizeof(double)*size1*size2);
    self->data = data;
    self->size1 = size1;
    self->size2 = size2;
    return  self;
}

Matrix* Matrix_clone(Matrix* matrix)
{
    Matrix *s = cpalloc(matrix,sizeof(Matrix));
    s->data = cpalloc(matrix->data,sizeof(double)*s->size2*s->size1);
    return s;
}

Matrix* Matrix_add(Matrix* m1, Matrix* m2)
{
    Matrix* result = Matrix_clone(m1);
    for(int x = 0; x < result->size1; ++x)
    {
        for(int y = 0; y < result->size2; y++)
        {
           Matrix_put_(result,x,y,Matrix_at_(m1,x,y) + Matrix_at_(m2,x,y));
        }
    }
    return  result;
}
Matrix* Matrix_subtract(Matrix* m1, Matrix* m2)
{
    Matrix* result = Matrix_new(m1->size1,m1->size2);
    for(int x = 0; x < result->size1; ++x)
    {
        for(int y = 0; y < result->size2; y++)
        {
            Matrix_put_(result,x,y,Matrix_at_(m1,x,y) - Matrix_at_(m2,x,y));
        }
    }
    return  result;
}
Matrix* Matrix_multiply(Matrix* m1, Matrix* m2)
{
    Matrix* result = Matrix_new(m1->size2,m2->size1);
    for(int x = 0; x < result->size1; ++x)
    {
        for(int y = 0; y < result->size2; y++)
        {
            double out = 0.0;
            for(int z = 0; z < m1->size1; ++z)
            {
                out += Matrix_at_(m2,x,z)*Matrix_at_(m1,z,y)
            }

            Matrix_put_(result,x,y,out);
        }
    }
    return result;
}

Matrix* Matrix_transpose(Matrix* m1)
{
    Matrix* result = Matrix_new(m1->size1,m1->size2);
    for(int x = 0; x < result->size1; ++x)
    {
        for(int y = 0; y < result->size2; ++y)
        {
          double out = Matrix_at_(m1,x,y)

          Matrix_put_(result,y,x,out);
        }
    }
    return result;
}

double Matrix_Determinant(Matrix* m1)
{
    double determinant;

    if (m1->size1 == m1->size2 == 1)
    {
      return Matrix_at_(m1,0,0);
    }
    else if (m1->size1 == m1->size2 == 2)
    {
      determinant = Matrix_at_(m1,0,0)*Matrix_at_(m1,1,1) - Matrix_at_(m1,1,0)*Matrix_at_(m1,0,1);
    }
    else if (m1->size1 == m1->size2 == 3)
    {
      determinant = Matrix_at_(m1,0,0)*((Matrix_at_(m1,1,1)*Matrix_at_(m1,2,2)) - (Matrix_at_(m1,2,1)*Matrix_at_(m1,1,2)))-Matrix_at_(m1,0,1)*((Matrix_at_(m1,1,0)*Matrix_at_(m1,2,2))-(Matrix_at_(m1,2,0)*Matrix_at_(m1,1,2)))+Matrix_at_(m1,0,2)*((Matrix_at_(m1,1,0)*Matrix_at_(m1,2,1))-(Matrix_at_(m1,2,0)*Matrix_at_(m1,1,1)));
    }
    else {
      printf("invalid matrix dimensions");
      return 0;
    }

    return determinant;
}

void Matrix_put_(Matrix* m1,int x, int y, double value)
{
    m1->data[(x * m1->size1) + y] = value;
}

double Matrix_at_(Matrix* m1,int x,int y)
{
    return m1->data[(x * m1->size1) + y];
}

void Matrix_free(Matrix* matrix)
{
    io_free(matrix->data);
    io_free(matrix);
}
