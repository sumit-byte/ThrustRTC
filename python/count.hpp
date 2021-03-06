#include <Python.h>
#include "TRTCContext.h"
#include "count.h"

static PyObject* n_count(PyObject* self, PyObject* args)
{
	DVVectorLike* vec = (DVVectorLike*)PyLong_AsVoidPtr(PyTuple_GetItem(args, 0));
	DeviceViewable* value = (DeviceViewable*)PyLong_AsVoidPtr(PyTuple_GetItem(args, 1));
	size_t res;
	if (TRTC_Count(*vec, *value, res))
		return PyLong_FromUnsignedLongLong((unsigned long long)res);
	else
		Py_RETURN_NONE;
	
}

static PyObject* n_count_if(PyObject* self, PyObject* args)
{
	DVVectorLike* vec = (DVVectorLike*)PyLong_AsVoidPtr(PyTuple_GetItem(args, 0));
	Functor* pred = (Functor*)PyLong_AsVoidPtr(PyTuple_GetItem(args, 1));
	size_t res;
	if (TRTC_Count_If(*vec, *pred, res))
		return PyLong_FromUnsignedLongLong((unsigned long long)res);
	else
		Py_RETURN_NONE;
}
