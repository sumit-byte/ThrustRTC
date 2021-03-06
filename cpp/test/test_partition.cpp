#include <stdio.h>
#include "TRTCContext.h"
#include "DVVector.h"
#include "partition.h"

int main()
{
	

	Functor is_even = { {},{ "x" }, "        return x % 2 == 0;\n" };

	{
		int h_value[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		DVVector d_value("int32_t", 10, h_value);
		TRTC_Partition(d_value, is_even);
		d_value.to_host(h_value);
		printf("%d %d %d %d %d ", h_value[0], h_value[1], h_value[2], h_value[3], h_value[4]);
		printf("%d %d %d %d %d\n", h_value[5], h_value[6], h_value[7], h_value[8], h_value[9]);
	}

	{
		int h_value[10] = { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 };
		DVVector d_value("int32_t", 10, h_value);
		int h_stencil[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		DVVector d_stencil("int32_t", 10, h_stencil);
		TRTC_Partition_Stencil(d_value, d_stencil, is_even);
		d_value.to_host(h_value);
		printf("%d %d %d %d %d ", h_value[0], h_value[1], h_value[2], h_value[3], h_value[4]);
		printf("%d %d %d %d %d\n", h_value[5], h_value[6], h_value[7], h_value[8], h_value[9]);
	}

	{
		int h_value[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		DVVector d_value("int32_t", 10, h_value);
		int h_evens[10];
		DVVector d_evens("int32_t", 10);
		int h_odds[10];
		DVVector d_odds("int32_t", 10);
		uint32_t count = TRTC_Partition_Copy(d_value, d_evens, d_odds, is_even);
		d_evens.to_host(h_evens, 0, count);
		d_odds.to_host(h_odds, 0, 10 - count);
		for (uint32_t i = 0; i < count; i++)
			printf("%d ", h_evens[i]);
		puts("");
		for (uint32_t i = 0; i < 10-count; i++)
			printf("%d ", h_odds[i]);
		puts("");
	}

	{
		int h_value[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		DVVector d_value("int32_t", 10, h_value);
		int h_stencil[10] = { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 };
		DVVector d_stencil("int32_t", 10, h_stencil);
		int h_evens[10];
		DVVector d_evens("int32_t", 10);
		int h_odds[10];
		DVVector d_odds("int32_t", 10);
		uint32_t count = TRTC_Partition_Copy_Stencil(d_value, d_stencil, d_evens, d_odds, Functor("Identity"));
		d_evens.to_host(h_evens, 0, count);
		d_odds.to_host(h_odds, 0, 10 - count);
		for (uint32_t i = 0; i < count; i++)
			printf("%d ", h_evens[i]);
		puts("");
		for (uint32_t i = 0; i < 10 - count; i++)
			printf("%d ", h_odds[i]);
		puts("");
	}

	{
		int h_value[10] = { 2, 4, 6, 8, 10, 1, 3, 5, 7, 9 };
		DVVector d_value("int32_t", 10, h_value);
		size_t pp;
		TRTC_Partition_Point(d_value, is_even, pp);
		printf("%zu\n", pp);
	}

	{
		int h_value[10] = { 2, 4, 6, 8, 10, 1, 3, 5, 7, 9 };
		DVVector d_value("int32_t", 10, h_value);
		bool res;
		TRTC_Is_Partitioned(d_value, is_even, res);
		puts(res ? "true" : "false");
	}

	{
		int h_value[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		DVVector d_value("int32_t", 10, h_value);
		bool res;
		TRTC_Is_Partitioned(d_value, is_even, res);
		puts(res ? "true" : "false");
	}

	return 0;
}
