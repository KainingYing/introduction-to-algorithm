#include <iostream>
using namespace std;
int LCS_crude(int a, int b,int *x,int *y)
{
	//a与b为数组的长度，0表示数组为长度0，表示第一个元素，其实还是有元素的
	//4表示数组长度为4，但是表示第五个元素。
	if(a == -1 || b == -1)//为了兼容，用-1表示数组长度为0
		return 0;
	else if (x[a] == y[b])
	{
		return LCS_crude(a - 1, b - 1, x, y)+1;
	}
	else
	{
		int c = LCS_crude(a, b - 1, x, y);
		int d = LCS_crude(a - 1, b, x, y);
		return (c > d ? c : d);
	}
}
int main()
{
	int x[3] = { 1,1,5 };
	int y[3] = {1,1,4};
	cout << LCS_crude(2, 2, x, y) << endl;
	system("pause");

	return 0;
}