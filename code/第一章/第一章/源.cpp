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
	/*���Բ���*/
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
	��һ������ˣ����±�Ϊ0�������������λ��ʵ���������λ��
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
void main()
{
	/*//���Բ�������
	int a[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int n = 10;
	insert_sort_version1(a,n);
	print_array(a,n);
	system("pause");*/
	/*//���Բ���
	int a[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	cout << linear_search(a, 6, 10)<<endl;
	system("pause");*/
	// ѡ������
	int a[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	selection_sort(a, 10);
	print_array(a, 10);
	system("pause");
}