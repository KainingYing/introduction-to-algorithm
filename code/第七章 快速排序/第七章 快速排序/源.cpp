#include <iostream>
#include <ctime>
using namespace std;
int a[10000];
int b[10000];


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
int partition_hoare(int *a, int left, int right)
{
	/*Hoare����*/
	int x = a[left];
	int l = left-1 ;
	int r = right+1;
	while (true)
	{
		do l++; while (a[l] < x);
		do r--; while (a[r] > x);
		//for (; x > a[l]&&l<=right; l++);
		//for (; x < a[r]&&r>=left; r--);
		if (r > l)
		{
			int temp = a[l];
			a[l] = a[r];
			a[r] = temp;
		}
		else
			return r;
	}
}
int hoare_partition(int A[], int p, int r) {
	int x = A[p],
		i = p - 1,
		j = r+1,
		tmp;
	while (true) {
		do { j--; } while (!(A[j] <= x));
		do { i++; } while (!(A[i] >= x));
		if (i < j) {
			tmp = A[i]; A[i] = A[j]; A[j] = tmp;
		}
		else {
			return j;
		}
	}
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
void quicksort_hoare(int *a, int left, int right)
{
	if (left < right)
	{
		int mid =partition_hoare(a, left, right);
		quicksort_hoare(a, left, mid);
		quicksort_hoare(a, mid + 1, right);
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
	���ڸ�����������Ҫ��΢�����޸ģ���Ϊ���������ǶԾֲ��������������������left��right����
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
	/*k���������������С����*/
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
	int n = 10000;  
	random_array(a, n, 100);

	for (int i = 0; i < n; i++)
		b[i] = 2;
	start = clock();
	quicksort_random(a, 0, n - 1);
	end = clock();
	cout << "�����:" << endl << double(end - start) / (CLOCKS_PER_SEC) << endl;
	start = clock();
	quicksort_random(b, 0, n - 1);
	end = clock();
	cout << "ȫ����ͬ:" << endl << double(end - start) / (CLOCKS_PER_SEC) << endl;
	/*print_array(a, n);
	quicksort_hoare(a, 0, n - 1); 
	print_array(a, n);*/
	/*cout << hoare_partition(a, 0, n - 1);*/
	system("pause");
	return 0;
}