#include <stdio.h>
#include "TRTCContext.h"
#include "DVVector.h"
#include "equal.h"

int main()
{
	int harr1[7] = { 3, 1, 4, 1, 5, 9, 3 };
	int harr2[7] = { 3, 1, 4, 2, 8, 5, 7 };
	DVVector darr1("int32_t", 6, harr1);
	DVVector darr2("int32_t", 6, harr2);
	DVVector darr3("int32_t", 6, harr1);

	bool res1, res2;
	TRTC_Equal(darr1, darr2, res1);
	TRTC_Equal(darr1, darr3, res2);

	printf("%d %d\n", res1, res2);

	Functor compare_modulo_two = { {},{ "x", "y" }, "        return (x % 2) == (y % 2);\n" };
	int x[6] = { 1, 2, 3, 4, 5, 6 };
	int y[6] = { 7, 8, 9, 10, 11, 12 };
	DVVector dx("int32_t", 6, x);
	DVVector dy("int32_t", 6, y);
	bool res3;
	TRTC_Equal(dx, dy, compare_modulo_two, res3);

	printf("%d\n", res3);

	return 0;
}
