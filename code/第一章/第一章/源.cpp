#include <iostream>
#include <limits>
using namespace std;

void insert_sort_version1(int *A,int n)
{
	/*
	第一版本，就是简单实现了p10的伪代码
	*/
	/*
	A是数组A，n为数组的长度
	可以用sizeof()来求出数组的长度，内存空间
	但是作为参数不能获得,传入的参数是一个地址，函数无法判断他的长度
	*/
	int key;
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		key = A[i];
		while (j >= 0 && A[j] >= key)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}
}
int linear_search(int *A, int v,int n)
{
	/*线性查找*/
	int NIL = 500;
	for (int i = 0; i < n; i++)
	{
		if (A[i] == v)
		{
			return i;
		}
	}
	return NIL;
}
void print_array(int *A,int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}
void binary_add(int *a, int *b,int *c, int n)
{
	/*
	第一次想错了，把下标为0的情况想成了最低位，实则这是最高位。
	*/
	int carry = 0;
	for (int i = n-1; i >=0; i--)
	{
		c[i+1] = (a[i] + b[i] + carry)%2;
		carry = (a[i] + b[i] + carry) / 2;
	}
	c[0] = carry;
}
void selection_sort(int *a, int n)
{
	int min,index;
	
	for (int i = 0; i < n-1; i++)
	{
		min = a[i];
		index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < min)
			{
				min = a[j];
				index = j;
			}
		}
		int temp = a[i];
		a[i] = a[index];
		a[index] = temp;
	}
}
void merge_version1(int *a, int p, int q, int r)
{
	/*
	用了一张哨兵牌，用于简化代码，快不快不一定
	*/
	int n1 = q - p + 1;
	int n2 = r - q;
	int *L = new int[n1+1];
	int *R = new int[n2+1];
	for (int i = 0; i < n1; i++)
	{
		L[i] = a[i + p];
	}
	L[n1] = INT16_MAX;
	for (int i = 0; i < n2; i++)
	{
		R[i] = a[i + q + 1];
	}
	R[n2] = INT16_MAX;
	int l = 0, r1 = 0;
	for (int i = 0; i < r - p + 1; i++)
	{
		if (L[l] <= R[r1])
		{
			a[i + p] = L[l];
			l++;
		}
		else
		{
			a[i + p] = R[r1];
			r1++;
		}
	}
	delete[] L;
	delete[] R;
}
void merge_version2(int *a, int p, int q, int r)
{
	/*没有哨兵*/
	int n1 = q - p + 1;
	int n2 = r - q;
	int *L = new int[n1];
	int *R = new int[n2];
	for (int i = 0; i < n1; i++)
	{
		L[i] = a[i + p];
	}
	for (int i = 0; i < n2; i++)
	{
		R[i] = a[i + q + 1];
	}
	int l = 0, r1 = 0;
	int i;
	for (i = 0; i < r - p + 1; i++)
	{
		if (l == n1 || r1 == n2)
		{
			break;
		}
		else 
		{
			if (L[l] <= R[r1])
			{
				a[i + p] = L[l];
				l++;
			}
			else
			{
				a[i + p] = R[r1];
				r1++;
			}
		}
	}
	if (l == n1 )
	{
		for (; i < r-p+1; i++)
		{
			a[i + p] = R[r1];
			r1++;
		}
	}
	else
	{
		for (; i < r - p + 1; i++)
		{
			a[i + p] = L[l];
			l++;
		}
	}
	delete[] L;
	delete[] R;

}
void merge_sort(int *a, int p, int q)
{
	/*具体的归并排序*/
	if (p < q)
	{
		int mid = (p + q) / 2;
		merge_sort(a, p, mid);
		merge_sort(a, mid + 1, q);
		merge_version2(a, p, mid, q);
	}
}
void main()
{
	/*//测试插入排序
	int a[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int n = 10;
	insert_sort_version1(a,n);
	print_array(a,n);
	system("pause");*/
	/*//线性查找
	int a[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	cout << linear_search(a, 6, 10)<<endl;
	system("pause");*/
	// 选择排序
	/*//选择排序
	int a[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	selection_sort(a, 10);
	print_array(a, 10);
	system("pause");*/
	int a[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	merge_sort(a, 0, 9);
	print_array(a, 10);
	system("pause");

}