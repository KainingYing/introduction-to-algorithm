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
void LCS_length(int m, int n, int *x, int *y,int **c,int **b)
{
	//这是一个自顶、底向上的方式 m与n为数组的长度
	for (int i = 0; i <= m; i++)//先进行初始化
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
void print_LCS_version2(int **c, int *x, int i, int j)
{
	//不用表b，直接用表c就可以完成最优解的构造
	//构造出来的答案与版本一有区别
	if (i == 0 || j == 0)
		return;
	else if (c[i][j] == c[i - 1][j - 1] + 1)//第一种情况
	{
		print_LCS_version2(c, x, i - 1, j - 1);
		cout << x[i - 1] << ' ';
	}
	else if (c[i][j] == c[i - 1][j])
		print_LCS_version2(c, x, i - 1, j);
	else
		print_LCS_version2(c, x, i, j - 1);
}
int LCS_length_up2down_aux(int m, int n, int **c, int *x, int *y)
{
	if (c[m][n] != -1)
		return c[m][n];
	else
	{
		if (m == 0 || n == 0)
		{
			c[m][n] = 0;
			return c[m][n];
		}
		else if (x[m-1] == y[n-1])
		{
			c[m][n] = LCS_length_up2down_aux(m - 1, n - 1, c, x, y)+1;
			return c[m][n];
		}
		else
		{
			int a = LCS_length_up2down_aux(m, n - 1, c, x, y);
			int b = LCS_length_up2down_aux(m - 1, n, c, x, y);
			c[m][n] = a > b ? a : b;
			return c[m][n];
		}
	}

}
void LCS_length_up2down(int m, int n, int **c, int *x, int *y)
{
	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= n; j++)
			c[i][j] = -1;
	LCS_length_up2down_aux(m, n, c, x, y);
	
}
int main()
{
	int x[8] = { 1,0,0,1,0,1,0,1 };
	int y[9] = {0,1,0,1,1,0,1,1,0};
	int **b = new int*[10];
	for (int i = 0; i < 10; i++)
		b[i] = new int[10];
	int **c = new int*[10];
	for (int i = 0; i < 10; i++)
		c[i] = new int[10];

	LCS_length_up2down(8, 9, c, x, y);
	//print_LCS(b, x, 3, 3);
	cout << endl;
	//print_LCS_version2(c, x, 3,3);
	delete[]b;
	delete[]c;

	system("pause");
	return 0;
}