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
void LCS_length(int m, int n, int *x, int *y,int **c,int **b)
{
	//����һ���Զ����ϵķ�ʽ m��nΪ����ĳ���
	for (int i = 0; i <= m; i++)//�Ƚ��г�ʼ��
		c[i][0] = 0;
	for (int i = 0; i <= n; i++)
		c[0][i] = 0;
	for(int i=1;i<=m;i++)
		for (int j = 1; j <= n; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i-1][j];
				b[i][j] = 2;
			}
			else
			{
				c[i][j] = c[i][j-1];
				b[i][j] = 3;
			}
		}
}
void print_LCS(int **b,int *x,int i,int j)
{
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == 1)
	{
		print_LCS(b, x, i - 1, j - 1);
		cout << x[i - 1] << " ";
	}
	else if (b[i][j] == 2)
	{
		print_LCS(b, x, i - 1, j);
	}
	else
		print_LCS(b, x, i, j - 1);
}
int main()
{
	int x[3] = { 1,1,5 };
	int y[3] = {1,1,4};
	int **b = new int*[10];
	for (int i = 0; i < 10; i++)
		b[i] = new int[10];
	int **c = new int*[10];
	for (int i = 0; i < 10; i++)
		c[i] = new int[10];

	LCS_length(3, 3, x, y, c, b);
	print_LCS(b, x, 3, 3);
	delete[]b;
	delete[]c;

	system("pause");
	return 0;
}