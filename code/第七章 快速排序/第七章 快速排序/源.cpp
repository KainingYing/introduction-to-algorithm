#include <iostream>
#include <ctime>
using namespace std;

int a[100000];
int b[100000];
void random_array(int *a, int n, int range)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % range + 1;
	}
}
int partition(int *a, int left, int right)
{
	/*��������汾��ѡ�����һ����Ϊ��׼
	����һ���ж����ڵ�ȫ����Ԫ�ض���ͬʱ��ô�����м�ֵ���ؼ����������ж��Ƿ�����ֵ����ͬ*/  
	bool flag = true;
	int key = a[right];
	int i = left - 1;
	for (int j = left; j <= right - 1; j++)
	{ 
		if (a[j] < key)
		{
			i++;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			flag = false;
		}
		else if (a[j] > key)
			flag = false;
		else;
	}
	int temp = a[right];
	a[right] = a[i + 1];
	a[i + 1] = temp;
	if (flag == true)
		return (left + right) / 2;
	else
		return i + 1;
}
void quicksort(int *a, int left, int right)
{
	if (left < right)
	{
		/*���������ֻ��0��Ԫ�ػ���ֻ��һ��Ԫ�أ���ô��������ģ����ò�ȡ�κ��ж�*/
		int mid = partition(a, left, right);
		quicksort(a, left, mid - 1);
		quicksort(a, mid + 1, right);
	}
}
int partition_random(int *a, int left, int right)
{
	srand(time(0));
	int index = rand() % (right - left + 1) + left;
	int temp = a[index];
	a[index] = a[right];
	a[right] = temp;
	return partition(a, left, right);
}
void quicksort_random(int *a, int left, int right)
{
	if (left < right)
	{
		int mid = partition_random(a, left, right);
		quicksort_random(a, left, mid - 1);
		quicksort_random(a, mid + 1, right);
	}
}
void insert_sort(int *A, int n)
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
void print_array(int *a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
int main()
{
	clock_t start, end;
	int n = 1000;  
	/*random_array(a, n, 10000000);*/
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
		b[i] = i;
	}
	for (int i = 0; i < n; i++)
		b[i] = a[i];
	start = clock();
	quicksort(a, 0, n - 1);
	end = clock();
	cout << "����������㷨:" << endl << double(end - start) / (CLOCKS_PER_SEC) << endl;
	start = clock();
	quicksort_random(b, 0, n - 1);
	end = clock();
	cout << "��������㷨:" << endl << double(end - start) / (CLOCKS_PER_SEC) << endl;
	///*print_array(a, 3);*/
	system("pause");




	return 0;
}