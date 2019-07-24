#include <iostream>
using namespace std;

int partition(int *a, int left, int right)
{
	/*��������汾��ѡ�����һ����Ϊ��׼
	����һ���ж����ڵ�ȫ����Ԫ�ض���ͬʱ��ô�����м�ֵ���ؼ����������ж��Ƿ�����ֵ����ͬ*/  
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
		/*���������ֻ��0��Ԫ�ػ���ֻ��һ��Ԫ�أ���ô��������ģ����ò�ȡ�κ��ж�*/
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