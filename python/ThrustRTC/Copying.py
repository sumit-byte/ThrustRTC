from . import PyThrustRTC as native

def Gather(vec_map, vec_in, vec_out):
	native.n_gather(vec_map.m_cptr, vec_in.m_cptr, vec_out.m_cptr)

def Gather_If(vec_map, vec_stencil, vec_in, vec_out, pred = None):
	cptr_pred = None
	if pred!=None:
		cptr_pred = pred.m_cptr
	native.n_gather_if(vec_map.m_cptr, vec_stencil.m_cptr, vec_in.m_cptr, vec_out.m_cptr, cptr_pred)

def Scatter(vec_in, vec_map, vec_out):
	native.n_scatter(vec_in.m_cptr, vec_map.m_cptr, vec_out.m_cptr)

def Scatter_If(vec_in, vec_map, vec_stencil, vec_out, pred = None):
	cptr_pred = None
	if pred!=None:
		cptr_pred = pred.m_cptr
	native.n_scatter_if(vec_in.m_cptr, vec_map.m_cptr, vec_stencil.m_cptr, vec_out.m_cptr, cptr_pred)

def Copy(vec_in, vec_out):
	native.n_copy(vec_in.m_cptr, vec_out.m_cptr)

def Swap(vec1, vec2):
	native.n_swap(vec1.m_cptr, vec2.m_cptr)	
