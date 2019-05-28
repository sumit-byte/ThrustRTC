#include "cuda_wrapper.h"
#include "binary_search.h"

bool TRTC_Lower_Bound(TRTCContext& ctx, const DVVectorLike& vec, const DeviceViewable& value, const Functor& comp, size_t& result, size_t begin, size_t end)
{
	if (end == (size_t)(-1)) end = vec.size();
	if (end <= begin)
	{
		result = begin;
		return true;
	}

	static TRTC_Kernel s_kernel(
		{ "num_grps", "vec", "begin", "value", "comp", "range_out", "size_grp", "div_id" },
		"    size_t id = threadIdx.x+blockIdx.x*blockDim.x;\n"
		"    if (id>=num_grps) return;"
		"    size_t begin_grp = size_grp*id + begin;\n"
		"    size_t end_grp = begin_grp + size_grp;\n"
		"    if (id>=div_id)\n"
		"    {\n"
		"        begin_grp += id - div_id;\n"
		"        end_grp = begin_grp + size_grp + 1;\n"
		"    }\n"
		"    if ( (begin_grp==0 || comp(vec[begin_grp-1],value)) && !comp(vec[end_grp-1], value) )\n"
		"    {\n"
		"        range_out[0] = begin_grp;\n"
		"        range_out[1] = end_grp;\n"
		"    }\n"
	);

	size_t h_range_out[2];
	DVVector dv_range_out(ctx, "size_t", 2);
	int numBlocks;
	{
		DVSizeT _dv_num_grps(end - begin);
		DVSizeT _dv_begin(begin);
		DVSizeT _dv_size_grp(1);
		DVSizeT _dv_div_id((size_t)(-1));
		const DeviceViewable* _args[] = { &_dv_num_grps, &vec, &_dv_begin, &value, &comp, &dv_range_out, &_dv_size_grp, &_dv_div_id };
		s_kernel.calc_number_blocks(ctx, _args, 128, numBlocks);
	}

	size_t s_begin = begin;
	size_t s_end = end;

	do
	{
		size_t n = s_end - s_begin;
		size_t size_grp = 1;
		size_t div_id = (size_t)(-1);
		size_t num_grps = 128 * numBlocks;
		if (num_grps < n)
		{
			size_grp = n / num_grps;
			div_id = (size_grp + 1) * num_grps - n;
		}
		else
		{
			num_grps = n;
			numBlocks = (num_grps + 127) / 128;
		}

		DVSizeT dv_num_grps(num_grps);
		DVSizeT dv_begin(s_begin);
		DVSizeT dv_size_grp(size_grp);
		DVSizeT dv_div_id(div_id);

		h_range_out[0] = end;
		h_range_out[1] = begin;
		cuMemcpyHtoD((CUdeviceptr)dv_range_out.data(), h_range_out, sizeof(size_t) * 2);

		const DeviceViewable* args[] = { &dv_num_grps, &vec, &dv_begin, &value, &comp, &dv_range_out, &dv_size_grp, &dv_div_id };
		if (!s_kernel.launch(ctx, { (unsigned)numBlocks, 1,1 }, { 128, 1, 1 }, args)) return false;
		dv_range_out.to_host(h_range_out);
		s_begin = h_range_out[0];
		s_end = h_range_out[1];
	}
	while (s_end > 0 && s_end > s_begin + 1);

	result = s_begin;
	return true;
}

bool TRTC_Lower_Bound(TRTCContext& ctx, const DVVectorLike& vec, const DeviceViewable& value, size_t& result, size_t begin, size_t end)
{
	return TRTC_Lower_Bound(ctx, vec, value, Functor("Less"), result, begin, end);
}

bool TRTC_Upper_Bound(TRTCContext& ctx, const DVVectorLike& vec, const DeviceViewable& value, const Functor& comp, size_t& result, size_t begin, size_t end)
{
	if (end == (size_t)(-1)) end = vec.size();
	if (end <= begin)
	{
		result = end;
		return true;
	}

	static TRTC_Kernel s_kernel(
		{ "num_grps", "vec", "begin", "value", "comp", "range_out", "size_grp", "div_id" },
		"    size_t id = threadIdx.x+blockIdx.x*blockDim.x;\n"
		"    if (id>=num_grps) return;"
		"    size_t begin_grp = size_grp*id + begin;\n"
		"    size_t end_grp = begin_grp + size_grp;\n"
		"    if (id>=div_id)\n"
		"    {\n"
		"        begin_grp += id - div_id;\n"
		"        end_grp = begin_grp + size_grp + 1;\n"
		"    }\n"
		"    if ( !comp(value, vec[begin_grp]) && (id == num_grps - 1 || comp(value, vec[end_grp]) ) )\n"
		"    {\n"
		"        range_out[0] = begin_grp;\n"
		"        range_out[1] = end_grp;\n"
		"    }\n"
	);

	size_t h_range_out[2];
	DVVector dv_range_out(ctx, "size_t", 2);
	int numBlocks;
	{
		DVSizeT _dv_num_grps(end - begin);
		DVSizeT _dv_begin(begin);
		DVSizeT _dv_size_grp(1);
		DVSizeT _dv_div_id((size_t)(-1));
		const DeviceViewable* _args[] = { &_dv_num_grps, &vec, &_dv_begin, &value, &comp, &dv_range_out, &_dv_size_grp, &_dv_div_id };
		s_kernel.calc_number_blocks(ctx, _args, 128, numBlocks);
	}

	size_t s_begin = begin;
	size_t s_end = end;
	
	do
	{
		size_t n = s_end - s_begin;
		size_t size_grp = 1;
		size_t div_id = (size_t)(-1);
		size_t num_grps = 128 * numBlocks;
		if (num_grps < n)
		{
			size_grp = n / num_grps;
			div_id = (size_grp + 1) * num_grps - n;
		}
		else
		{
			num_grps = n;
			numBlocks = (num_grps + 127) / 128;
		}

		DVSizeT dv_num_grps(num_grps);
		DVSizeT dv_begin(s_begin);
		DVSizeT dv_size_grp(size_grp);
		DVSizeT dv_div_id(div_id);

		h_range_out[0] = end;
		h_range_out[1] = begin;
		cuMemcpyHtoD((CUdeviceptr)dv_range_out.data(), h_range_out, sizeof(size_t) * 2);

		const DeviceViewable* args[] = { &dv_num_grps, &vec, &dv_begin, &value, &comp, &dv_range_out, &dv_size_grp, &dv_div_id };
		if (!s_kernel.launch(ctx, { (unsigned)numBlocks, 1,1 }, { 128, 1, 1 }, args)) return false;
		dv_range_out.to_host(h_range_out);
		s_begin = h_range_out[0];
		s_end = h_range_out[1];
	}
	while (s_end > 0 && s_end > s_begin + 1);

	result = s_end;
	return true;
}

bool TRTC_Upper_Bound(TRTCContext& ctx, const DVVectorLike& vec, const DeviceViewable& value, size_t& result, size_t begin, size_t end)
{
	return TRTC_Upper_Bound(ctx, vec, value, Functor("Less"), result, begin, end);
}


bool TRTC_Binary_Search(TRTCContext& ctx, const DVVectorLike& vec, const DeviceViewable& value, const Functor& comp, bool& result, size_t begin, size_t end)
{
	if (end == (size_t)(-1)) end = vec.size();
	if (end <= begin)
	{
		result = (size_t)-1;
		return true;
	}

	static TRTC_Kernel s_kernel(
		{ "num_grps", "vec", "begin", "value", "comp", "range_out", "size_grp", "div_id" },
		"    size_t id = threadIdx.x+blockIdx.x*blockDim.x;\n"
		"    if (id>=num_grps) return;"
		"    size_t begin_grp = size_grp*id + begin;\n"
		"    size_t end_grp = begin_grp + size_grp;\n"
		"    if (id>=div_id)\n"
		"    {\n"
		"        begin_grp += id - div_id;\n"
		"        end_grp = begin_grp + size_grp + 1;\n"
		"    }\n"
		"    if ( !comp(value, vec[begin_grp]) && !comp(vec[end_grp-1], value) )\n"
		"    {\n"
		"        range_out[0] = begin_grp;\n"
		"        range_out[1] = end_grp;\n"
		"    }\n"
	);

	size_t h_range_out[2];
	DVVector dv_range_out(ctx, "size_t", 2);
	int numBlocks;
	{
		DVSizeT _dv_num_grps(end - begin);
		DVSizeT _dv_begin(begin);
		DVSizeT _dv_size_grp(1);
		DVSizeT _dv_div_id((size_t)(-1));
		const DeviceViewable* _args[] = { &_dv_num_grps, &vec, &_dv_begin, &value, &comp, &dv_range_out, &_dv_size_grp, &_dv_div_id };
		s_kernel.calc_number_blocks(ctx, _args, 128, numBlocks);
	}
	size_t s_begin = begin;
	size_t s_end = end;

	do
	{
		size_t n = s_end - s_begin;
		size_t size_grp = 1;
		size_t div_id = (size_t)(-1);
		size_t num_grps = 128 * numBlocks;
		if (num_grps < n)
		{
			size_grp = n / num_grps;
			div_id = (size_grp + 1) * num_grps - n;
		}
		else
		{
			num_grps = n;
			numBlocks = (num_grps + 127) / 128;
		}

		DVSizeT dv_num_grps(num_grps);
		DVSizeT dv_begin(s_begin);
		DVSizeT dv_size_grp(size_grp);
		DVSizeT dv_div_id(div_id);

		h_range_out[0] = (size_t)(-1);
		h_range_out[1] = 0;
		cuMemcpyHtoD((CUdeviceptr)dv_range_out.data(), h_range_out, sizeof(size_t) * 2);

		const DeviceViewable* args[] = { &dv_num_grps, &vec, &dv_begin, &value, &comp, &dv_range_out, &dv_size_grp, &dv_div_id };
		if (!s_kernel.launch(ctx, { (unsigned)numBlocks, 1,1 }, { 128, 1, 1 }, args)) return false;
		dv_range_out.to_host(h_range_out);
		s_begin = h_range_out[0];
		s_end = h_range_out[1];

	} while (s_end - s_begin > 1);

	result = s_begin!=(size_t)-1;
	return true;

}


bool TRTC_Binary_Search(TRTCContext& ctx, const DVVectorLike& vec, const DeviceViewable& value, bool& result, size_t begin, size_t end)
{
	return TRTC_Binary_Search(ctx, vec, value, Functor("Less"), result, begin, end);
}
