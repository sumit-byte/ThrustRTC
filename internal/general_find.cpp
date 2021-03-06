#include "general_find.h"

bool general_find(size_t n, const Functor src, size_t& result)
{
	static TRTC_Kernel s_kernel(
		{ "src", "result", "begin", "end" },
		"    __shared__ unsigned long long s_result;"
		"    if (threadIdx.x == 0) s_result = (unsigned long long)(-1);\n"
		"    __syncthreads();\n"
		"    unsigned long long id = threadIdx.x+blockIdx.x*blockDim.x + begin;\n"
		"    if (id<end && src(id))\n"
		"       atomicMin(&s_result, id);\n"
		"    __syncthreads();\n"
		"    if (threadIdx.x == 0 && s_result!= (unsigned long long)(-1))\n"
		"        atomicMin(&result[0], s_result);\n"
	);

	result = (size_t)(-1);
	DVVector dvresult("unsigned long long", 1, &result);
	int numBlocks;
	{
		DVSizeT _dvbegin(0);
		DVSizeT _dvend(n);
		const DeviceViewable* _args[] = { &src, &dvresult, &_dvbegin, &_dvend };
		s_kernel.calc_number_blocks(_args, 128, numBlocks);
	}
	unsigned trunk_size = (unsigned)numBlocks * 128;
	size_t trunk_begin = 0;
	while (trunk_begin < n)
	{
		size_t trunk_end = trunk_begin + trunk_size;
		if (trunk_end > n) trunk_end = n;
		DVSizeT dvbegin(trunk_begin);
		DVSizeT dvend(trunk_end);
		const DeviceViewable* args[] = { &src, &dvresult, &dvbegin, &dvend };
		numBlocks = (int)((trunk_end - trunk_begin + 127) / 128);
		if (!s_kernel.launch({ (unsigned)numBlocks, 1,1 }, { 128, 1, 1 }, args)) return false;
		dvresult.to_host(&result);
		if (result != (size_t)(-1)) break;
		trunk_begin = trunk_end;
	}
	return true;
}
