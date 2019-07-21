#include <iostream>
using namespace std;

void insert_sort_version1(int *A)
{
	/*
	A是数组A，n为数组的长度
	可以用sizeof()来求出数组的长度，内存空间
	*/
	int length = sizeof(A)/sizeof(int);
	int key;
	for (int i = 1; i < length; i++)
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

void print_array(int *A)
{
	int length = sizeof(A) / sizeof(int);
	for (int i = 0; i < length; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

void main()
{
	int A[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	insert_sort_version1(A);
	print_array(A);
	/*cout << sizeof(A) / sizeof(int) << endl;*/
	system("pause");
}