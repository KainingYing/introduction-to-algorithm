#include <iostream>
using namespace std;

int partition(int *a, int left, int right)
{
	/*非随机化版本，选择最后一个作为基准
	增加一个判断用于当全部的元素都相同时那么返回中间值，关键在于增加判断是否所有值都相同*/  
	bool flag = true;
	int key = a[right];
	int i = left - 1;
	for (int j = left; j <= right - 1; j++)
	{ 
		if (a[j] > key)
		{
			i++;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			flag = false;
		}
		else if (a[j] < key)
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
void print_array(int *a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
int main()
{
	int a[8] = { 1,2,3,4,5,6,7,8 };
	quicksort(a, 0, 7);
	print_array(a, 8); 
	//cout << partition(a, 0, 7);
	/*print_array(a, 3);*/
	system("pause");




	return 0;
}