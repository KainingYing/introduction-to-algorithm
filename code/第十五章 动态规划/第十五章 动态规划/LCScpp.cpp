#include <iostream>
using namespace std;
int LCS_crude(int a, int b,int *x,int *y)
{
	//a��bΪ����ĳ��ȣ�0��ʾ����Ϊ����0����ʾ��һ��Ԫ�أ���ʵ������Ԫ�ص�
	//4��ʾ���鳤��Ϊ4�����Ǳ�ʾ�����Ԫ�ء�
	if(a == -1 || b == -1)//Ϊ�˼��ݣ���-1��ʾ���鳤��Ϊ0
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