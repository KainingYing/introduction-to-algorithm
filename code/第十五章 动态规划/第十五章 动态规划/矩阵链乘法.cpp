#include <iostream>
#include <limits>
using namespace std;
void matrix_chain_order(int *p, int n,int **m, int **s)
{
	for (int i = 0; i < n; i++)
		m[i][i] = 0;//����ǳ���Ϊ1�ľ�����
	for (int l = 2; l <= n; l++)//lΪ�������ĳ��ȣ���С��������е��Ե����ϵĸϽ�
	{
		for (int i = 0; i <= n - l; i++)//jΪ��ʼ�������ʼ�±�
		{
			int j = i + l-1;//jΪ���һ��������±�
			m[i][j] = INT32_MAX;
			for (int k = i; k < j; k++)//���ѭ������Ѱ����õĻ���
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