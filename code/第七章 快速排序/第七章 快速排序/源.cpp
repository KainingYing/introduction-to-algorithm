#include <iostream>
using namespace std;

int partition(int *a, int left, int right)
{
	/*��������汾��ѡ�����һ����Ϊ��׼*/
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
		}
	}
	int temp = a[right];
	a[right] = a[i + 1];
	a[i + 1] = temp;
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
	int a[8] = { 2,8,7,1,3,5,6,4 };
	quicksort(a, 0, 7);
	print_array(a, 8); 
	//cout << partition(a, 0, 2);
	print_array(a, 3);
	system("pause");




	return 0;
}