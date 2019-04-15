#include <Python.h>
#include "TRTCContext.h"
#include "tabulate.h"
#include "functor.hpp"

static PyObject* n_tabulate(PyObject* self, PyObject* args)
{
	TRTCContext* ctx = (TRTCContext*)PyLong_AsVoidPtr(PyTuple_GetItem(args, 0));
	DVVector* vec = (DVVector*)PyLong_AsVoidPtr(PyTuple_GetItem(args, 1));
	Functor op = PyFunctor_AsFunctor(PyTuple_GetItem(args, 2));
	size_t begin = (size_t)PyLong_AsLong(PyTuple_GetItem(args, 3));
	size_t end = (size_t)PyLong_AsLong(PyTuple_GetItem(args, 4));
	TRTC_tabulate(*ctx, *vec, op, begin, end);
	return PyLong_FromLong(0);
}
