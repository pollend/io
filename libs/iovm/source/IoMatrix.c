//
// Created by michaelpollind on 4/9/17.
//
#include "IoMatrix.h"
#include <Matrix.h>
#include "IoList.h"
#include "IoNumber.h"
#include "List.h"
#include "IoObject.h"

static const char *protoId = "Matrix";

#define DATA(self) ((Matrix*)(IoObject_dataPointer(self)))

IoTag *IoMatrix_newTag(void *state)
{
    IoTag *tag = IoTag_newWithName_(protoId);
    IoTag_state_(tag, state);
    IoTag_freeFunc_(tag, (IoTagFreeFunc *)IoMatrix_free);
    IoTag_cloneFunc_(tag, (IoTagCloneFunc *)IoMatrix_rawClone);
    IoTag_markFunc_(tag, (IoTagMarkFunc *)IoMatrix_mark);
    IoTag_compareFunc_(tag, (IoTagCompareFunc *)IoMatrix_compare);
    return tag;
}

IoMatrix *IoMatrix_proto(void *state)
{
    IoMethodTable methodTable[] ={
            {"set", IoMatrix_set},

            {"rowCount",IoMatrix_rowCount},
            {"columnCount",IoMatrix_columnCount},

            {"at",IoMatrix_at},

            {"row",IoMatrix_row},
            {"column",IoMatrix_column},
            {"transpose",IoMatrix_transpose},


            {"*",IoMatrix_multiply},
            {"+",IoMatrix_add},
            {"-",IoMatrix_subtract},

            {"toList",IoMatrix_toList},

            {NULL,NULL}
    };

    IoObject *self = IoObject_new(state);
    IoObject_tag_(self,IoMatrix_newTag(state));

    IoObject_setDataPointer_(self,UArray_new());
    IoState_registerProtoWithId_((IoState *)state,self,protoId);

    // IoSeq_addImmutableMethods(state);
    IoObject_addMethodTable_(self,methodTable);
    return  self;

}

int IoMatrix_compare(IoObject *self, IoObject *otherObject)
{
    if(!IS_MATRIX(otherObject))
    {
        return IoObject_defaultCompare(self,otherObject);
    } else
    {
        return  1;
    }
}

void IoMatrix_mark(IoMatrix *self)
{
    IoObject_shouldMark(self);
}


IoMatrix *IoMatrix_rawClone(IoMatrix *proto)
{
    IoObject *self = IoObject_rawClonePrimitive(proto);
    IoObject_tag_(self, IoObject_tag(proto));
    IoObject_setDataPointer_(self, Matrix_clone(DATA(proto)));
    return self;

}

IOVM_API IoMatrix *IoMatrix_new(void *state)
{
    IoObject *proto = IoState_protoWithId_((IoState *)state, protoId);
    return IOCLONE(proto);
}

//a := Matrix clone set(list(list(1,2),list(2,3))) row(1)
void IoMatrix_free(IoMatrix *self)
{
    if (NULL == DATA(self))
    {
        printf("IoMatrix_free(%p) already freed\n", (void *)self);
        exit(1);
    }
    //printf("IoList_free(%p) List_free(%p)\n", (void *)self, (void *)DATA(self));

    Matrix_free(DATA(self));
    IoObject_setDataPointer_(self, NULL);
}


IO_METHOD(IoMatrix, set)
{
    IoList* ioObject = IoMessage_locals_listArgAt_(m,locals,0);
    List* list = IoList_rawList(ioObject);

    size_t max_rows = List_size(IoList_rawList(LIST_AT_(list,0)));
    size_t max_columns = List_size(list);
    Matrix* matrix = Matrix_new(max_columns,max_rows);

    for(size_t x = 0; x < max_columns; x++)
    {
        List* row =  IoList_rawList(LIST_AT_(list,x));
        if(List_size(row) != max_rows)
        {
            Matrix_free(matrix);
            IOASSERT(0,"Mismatching columns");
        }
        for(size_t y = 0; y < max_rows; y++)
        {
            double number = CNUMBER(LIST_AT_(row,y));
            Matrix_put_(matrix,x,y,number);
        }
    }

    IoMatrix* out = (IoMatrix*)IoMatrix_new(IOSTATE);
    IoObject_setDataPointer_(out, matrix);
    IoObject_isDirty_(out,1);
    return out;
}

IO_METHOD(IoMatrix, rowCount)
{
    Matrix* m1 =  DATA(self);
    return IONUMBER(Matrix_row_count_(m1));
}
IO_METHOD(IoMatrix, columnCount)
{
    Matrix* m1 =  DATA(self);
    return IONUMBER(Matrix_column_count_(m1));
}

IO_METHOD(IoMatrix, at)
{
    int columns = IoMessage_locals_intArgAt_(m,locals,0);
    int rows = IoMessage_locals_intArgAt_(m,locals,1);

    Matrix* matrix =  DATA(self);
    if(rows < 0 || rows > Matrix_row_count_(matrix))
        return IONIL(self);

    if(columns < 0 || columns > Matrix_column_count_(matrix))
        return IONIL(self);

    return IONUMBER(Matrix_at_(matrix,columns,rows));

}

IO_METHOD(IoMatrix, multiply)
{
    Matrix* m1 =  DATA(self);
    Matrix* m2 =  DATA(IoMessage_locals_MatrixArgAt_(m,locals,0));

    IOASSERT(Matrix_row_count_(m1) == Matrix_column_count_(m2), "Matrix rows and columns have to match");
    Matrix* m3 = Matrix_multiply(m1,m2);

    IoMatrix* out = (IoMatrix*)IoMatrix_new(IOSTATE);
    IoObject_setDataPointer_(out, m3);
    IoObject_isDirty_(out,1);
    return out;
}

//Matrix clone set(list(list(1,2),list(2,3))) transpose + Matrix clone set(list(list(1,2),list(2,3)))
IO_METHOD(IoMatrix, add)
{
    Matrix* m1 =  DATA(self);
    Matrix* m2 =  DATA(IoMessage_locals_MatrixArgAt_(m,locals,0));

    IOASSERT(Matrix_row_count_(m1) == Matrix_row_count_(m2), "Matrix rows mismatch");
    IOASSERT(Matrix_column_count_(m1) == Matrix_column_count_(m2), "Matrix columns mismatch");

    Matrix* m3 = Matrix_add(m1,m2);

    IoMatrix* out = (IoMatrix*)IoMatrix_new(IOSTATE);
    IoObject_setDataPointer_(out, m3);
    IoObject_isDirty_(out,1);
    return out;
}

IO_METHOD(IoMatrix, subtract)
{
    Matrix* m1 =  DATA(self);
    Matrix* m2 =  DATA(IoMessage_locals_MatrixArgAt_(m,locals,0));

    IOASSERT(Matrix_row_count_(m1) == Matrix_row_count_(m2), "Matrix rows mismatch");
    IOASSERT(Matrix_column_count_(m1) == Matrix_column_count_(m2), "Matrix columns mismatch");

    Matrix* m3 = Matrix_subtract(m1,m2);

    IoMatrix* out = (IoMatrix*)IoMatrix_new(IOSTATE);
    IoObject_setDataPointer_(out, m3);
    IoObject_isDirty_(out,1);
    return out;
}



IO_METHOD(IoMatrix, row)
{
    Matrix* m1 = DATA(self);
    int index = IoMessage_locals_intArgAt_(m,locals,0);

    List* list = List_new();
    IoList* ioList = IoList_new(IOSTATE);
    size_t row_count = Matrix_row_count_(m1);

    for(size_t x = 0; x < row_count; ++x)
    {
        List_append_(list,IONUMBER(Matrix_at_(m1,x,index)));
    }

    IoObject_setDataPointer_(ioList, list);
    IoObject_isDirty_(ioList,1);
    return ioList;
}

IO_METHOD(IoMatrix, column)
{
    Matrix* m1 = DATA(self);
    int index = IoMessage_locals_intArgAt_(m,locals,0);

    List* list = List_new();
    IoList* ioList = IoList_new(IOSTATE);
    size_t row_count = Matrix_row_count_(m1);

    for(size_t x = 0; x < row_count; ++x)
    {
        List_append_(list,IONUMBER(Matrix_at_(m1,index,x)));
    }

    IoObject_setDataPointer_(ioList, list);
    IoObject_isDirty_(ioList,1);
    return ioList;
}

IO_METHOD(IoMatrix, toList)
{
    Matrix* m1 = DATA(self);

    List* list = List_new();
    IoList* ioList = IoList_new(IOSTATE);

    List* out = List_new();

    for(size_t x = 0; x < Matrix_column_count_(m1); ++x)
    {
        List* temp = List_new();
        IoList* ioTempList = IoList_new(IOSTATE);
        for(size_t y = 0; y < Matrix_row_count_(m1); ++y)
        {
            List_append_(temp,IONUMBER(Matrix_at_(m1,x,y)));
        }
        IoObject_setDataPointer_(ioTempList, temp);
        IoObject_isDirty_(ioTempList,1);

        List_append_(out,ioTempList);
    }

    IoList* ioResult = IoList_new(IOSTATE);
    IoObject_setDataPointer_(ioResult, out);
    IoObject_isDirty_(ioResult,1);
    return ioResult;
}

IO_METHOD(IoMatrix, transpose)
{
    Matrix* m1 = DATA(self);

    Matrix* result = Matrix_transpose(m1);

    IoMatrix* out = (IoMatrix*)IoMatrix_new(IOSTATE);
    IoObject_setDataPointer_(out, result);
    IoObject_isDirty_(out,1);
    return out;
}