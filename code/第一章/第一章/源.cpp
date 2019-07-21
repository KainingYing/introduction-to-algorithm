#include <iostream>
using namespace std;

void insert_sort_version1(int *A,int n)
{
	/*
	��һ�汾�����Ǽ�ʵ����p10��α����
	*/
	/*
	A������A��nΪ����ĳ���
	������sizeof()���������ĳ��ȣ��ڴ�ռ�
	������Ϊ�������ܻ��,����Ĳ�����һ����ַ�������޷��ж����ĳ���
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

void main()
{
	/*//���Բ�������
	int a[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int n = 10;
	insert_sort_version1(a,n);
	print_array(a,n);
	system("pause");*/
	int a[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	cout << linear_search(a, 6, 10)<<endl;
	system("pause");
}