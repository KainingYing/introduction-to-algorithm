#include <iostream>
using namespace std;
int array_max(int *a, int n)
{
	int max = -1;//由于计数排序只能排非负整数
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}
void counting_sort(int *a, int *b,int n)
{
	int k = array_max(a, n);
	int *c = new int[k+1];
	for (int i = 0; i <= k; i++)
		c[i] = 0;
	for (int i = 0; i < n; i++)
		c[a[i]] = c[a[i]] + 1;
	for (int i = 1; i <= k; i++)
		c[i] = c[i - 1] + c[i];
	for (int j = n - 1; j >= 0; j--)
	{
		b[c[a[j]]-1] = a[j];//减一的目的是为了与从0开始的数据数据相契合
		c[a[j]]--;
	}
	delete[]c;
}
int counting_sort_interval(int *a, int *b, int n,int d,int g)//返回d，g之间的数个数
{
	int k = array_max(a, n);
	int *c = new int[k + 1];
	for (int i = 0; i <= k; i++)
		c[i] = 0;
	for (int i = 0; i < n; i++)
		c[a[i]] = c[a[i]] + 1;
	for (int i = 1; i <= k; i++)
		c[i] = c[i - 1] + c[i];
	return c[g] - c[d - 1];
}

void print_array(int *a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
int main()
{
	int a[8] = { 9,1,2,3,10,2,0,8 };
	int b[8];
	cout << counting_sort_interval(a, b, 8, 1, 3) << endl;
	//print_array(b, 8);
	system("pause");
	return 0;
}