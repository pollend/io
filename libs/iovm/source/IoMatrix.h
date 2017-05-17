//
// Created by michaelpollind on 4/9/17.
//

#ifndef IoMatrix_DEFINED
#define IoMatrix_DEFINED 1

#include "IoObject.h"

#ifdef __cplusplus
extern "C" {
#endif

#define IS_MATRIX(self) \
	IoObject_hasCloneFunc_(self, (IoTagCloneFunc *)IoMatrix_rawClone)


typedef IoObject IoMatrix;

IOVM_API IoMatrix *IoMatrix_proto(void *state);
IOVM_API IoMatrix *IoMatrix_rawClone(IoMatrix *self);
IOVM_API IoMatrix *IoMatrix_new(void *state);
IOVM_API void IoMatrix_free(IoMatrix *self);
IOVM_API void IoMatrix_mark(IoMatrix *self);
IOVM_API int IoMatrix_compare(IoMatrix *self, IoObject *otherObject);
IOVM_API int IoMatrix_compare(IoMatrix *self, IoObject *otherObject);

IOVM_API IO_METHOD(IoMatrix, set);
IOVM_API IO_METHOD(IoMatrix, rowCount);
IOVM_API IO_METHOD(IoMatrix, columnCount);
IOVM_API IO_METHOD(IoMatrix, at);

IOVM_API IO_METHOD(IoMatrix, multiply);
IOVM_API IO_METHOD(IoMatrix, add);
IOVM_API IO_METHOD(IoMatrix, subtract);

IOVM_API IO_METHOD(IoMatrix, row);
IOVM_API IO_METHOD(IoMatrix, column);





#ifdef __cplusplus
}
#endif
#endif //IOLANGUAGE_IOMATRIX_H
