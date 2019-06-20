#include "Header.h"

bool isConsequitiveGrayCode(unsigned char h1, unsigned char h2)
{
	int h1_int = (int)h1;
	int h2_int = (int)h2;
	int res_xor = h1_int ^ h2_int;
	int one_bit_diff_flag = ((res_xor - 1)&res_xor);
	return (one_bit_diff_flag == 0)? true : false;
}

void bin(unsigned char n)
{
	long n_unsgn = (long)n;
	cout << n_unsgn << endl;
	long i;
	int res;
	for (i = 1 << 31; i > 0; i = i / 2)
	{
		(n_unsgn & i) ? res = 1 : res = 0;
		cout << res;
	}
		

	///* step 1 */
	//if (n_unsgn > 1)
	//	bin(n_unsgn / 2);

	///* step 2 */
	//cout << n_unsgn % 2;
}

