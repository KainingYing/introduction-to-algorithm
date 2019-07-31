#include <iostream>
#include <limits>
using namespace std;
void matrix_chain_order(int *p, int n,int **m, int **s)
{
	for (int i = 0; i < n; i++)
		m[i][i] = 0;//这个是长度为1的矩阵链
	for (int l = 2; l <= n; l++)//l为矩阵链的长度，从小到大的求，有点自底向上的赶脚
	{
		for (int i = 0; i <= n - l; i++)//j为起始矩阵的起始下标
		{
			int j = i + l-1;//j为最后一个矩阵的下标
			m[i][j] = INT32_MAX;
			for (int k = i; k < j; k++)//这个循环是在寻找最好的划分
			{
				if (m[i][j] > (m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1]))
				{
					m[i][j] = (m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1]);
					s[i][j] = k;
				}
			}
		}
	}
}
void print_optimal_parens(int **s, int i, int j)
{
	if (i == j)
		cout << i;
	else
	{
		cout << "(";
		print_optimal_parens(s, i, s[i][j]);
		print_optimal_parens(s, s[i][j] + 1, j);
		cout << ")";
	}
}
int main()
{
	int p[7] = { 30,35,15,5,10,20,25 };
	int **m = new int*[10];
	for (int i = 0; i < 10; i++)
		m[i] = new int[10];
	int **s = new int*[10];
	for (int i = 0; i < 10; i++)
		s[i] = new int[10];
	matrix_chain_order(p, 6, m, s);
	print_optimal_parens(s, 0, 5);
	for (int i = 0; i < 10; i++)
		delete[]m[i];
	delete[]m;
	for (int i = 0; i < 10; i++)
		delete[]s[i];
	delete[]s;

	system("pause");
	return 0;
}