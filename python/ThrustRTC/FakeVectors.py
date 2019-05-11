from . import PyThrustRTC as native
from .DVVector import DVVectorLike

class DVConstant(DVVectorLike):
	def __init__(self, ctx, dvobj, size = -1):
		self.m_dvobj = dvobj
		self.m_cptr = native.n_dvconstant_create(ctx.m_cptr, dvobj.m_cptr, size)

class DVCounter(DVVectorLike):
	def __init__(self, ctx, dvobj_init, size = -1):
		self.m_dvobj_init = dvobj_init
		self.m_cptr = native.n_dvcounter_create(ctx.m_cptr, dvobj_init.m_cptr, size)

class DVDiscard(DVVectorLike):
	def __init__(self, ctx, elem_cls, size = -1):
		self.m_cptr = native.n_dvdiscard_create(ctx.m_cptr, elem_cls, size)

class DVPermutation(DVVectorLike):
	def __init__(self, ctx, vec_value, vec_index):
		self.m_vec_value = vec_value
		self.m_vec_index = vec_index
		self.m_cptr = native.n_dvpermutation_create(ctx.m_cptr, vec_value.m_cptr, vec_index.m_cptr)

class DVReverse(DVVectorLike):
	def __init__(self, ctx, vec_value):
		self.m_vec_value = vec_value
		self.m_cptr = native.n_dvreverse_create(ctx.m_cptr, vec_value.m_cptr)

class DVTransform(DVVectorLike):
	def __init__(self, ctx, vec_in, elem_cls, op):
		self.m_vec_in = vec_in
		self.m_op = op
		self.m_cptr = native.n_dvtransform_create(ctx.m_cptr, vec_in.m_cptr, elem_cls, op.m_cptr)

class DVZipped(DVVectorLike):
	def __init__(self, ctx, vecs, elem_names):
		self.m_vecs = vecs
		self.m_cptr = native.n_dvzipped_create(ctx.m_cptr, [item.m_cptr for item in vecs], elem_names)
