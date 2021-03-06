#include <stdio.h>
#include "TRTCContext.h"
#include "DVVector.h"
#include "inner_product.h"

int main()
{
	{
		float h_vec1[3] = { 1.0f, 2.0f, 5.0f };
		float h_vec2[3] = { 4.0f, 1.0f, 5.0f };

		DVVector d_vec1("float", 3, h_vec1);
		DVVector d_vec2("float", 3, h_vec2);

		ViewBuf res;
		TRTC_Inner_Product(d_vec1, d_vec2, DVFloat(0.0f), res);
		printf("%f\n", *(float*)res.data());
	}

	{
		float h_vec1[3] = { 1.0f, 2.0f, 5.0f };
		float h_vec2[3] = { 4.0f, 1.0f, 5.0f };

		DVVector d_vec1("float", 3, h_vec1);
		DVVector d_vec2("float", 3, h_vec2);

		ViewBuf res;
		TRTC_Inner_Product(d_vec1, d_vec2, DVFloat(0.0f), res, Functor("Plus"), Functor("Multiplies"));
		printf("%f\n", *(float*)res.data());

	}

	return 0;
}
