#include <iostream>
#include <ctime>
using namespace std;

int a[1000000];
int b[1000000];
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
	/*非随机化版本，选择最后一个作为基准
	增加一个判断用于当全部的元素都相同时那么返回中间值，关键在于增加判断是否所有值都相同*/  
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
		/*基本情况是只有0个元素或者只有一个元素，那么他是有序的，不用采取任何行动*/
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
void insert_sort(int *A, int left,int right)
{
	/*
	用于辅助快速排序，要稍微进行修改，因为快速排序是对局部数组进行排序，所以引入left与right参数
	*/
	int key;
	for (int i = left+1; i < right; i++)
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
void quicksort_limit(int *a, int left, int right,int k)
{
	/*k用来限制数组的最小长度*/
	if ((right - left ) > k)
	{
		int mid = partition(a, left, right);
		quicksort_limit(a, left, mid - 1,k);
		quicksort_limit(a, mid + 1, right,k);
	}
	else
	{
		insert_sort(a, left, right);
	}
}
//void quicksort_insertsort(int *a, int left,int right)
//{
//	
//}
void print_array(int *a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
int main()
{
	clock_t start, end;
	int n = 400000;  
	random_array(a, n, 10000000);
	for (int i = 0; i < n; i++)
		b[i] = a[i];
	start = clock();
	quicksort(a, 0, n - 1);
	end = clock();
	cout << "未限制:" << endl << double(end - start) / (CLOCKS_PER_SEC) << endl;
	start = clock();
	quicksort_limit(a, 0, n - 1, 550);
	end = clock();
	cout << "限制了:" << endl << double(end - start) / (CLOCKS_PER_SEC) << endl;
	system("pause");




	return 0;
}