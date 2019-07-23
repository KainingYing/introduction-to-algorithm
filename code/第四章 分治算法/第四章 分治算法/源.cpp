#include <iostream>
#include <limits>
#include <time.h>
using namespace std;


struct answer
{
	int left, right;
	int sum;
};
int max(answer a, answer b, answer c)
{
	int max = a.sum;
	max=max < b.sum ? b.sum : max;
	max=max < c.sum ? c.sum : max;
	return max;
}
answer maximum_subarray_crossing(int *a, int left, int right, int mid)
{
	/*最大值横跨中间值mid*/
	answer result;
	int left_max = INT32_MIN;
	int sum = 0;
	int l, r;
	for (int i = mid; i >= left; i--)
	{
		sum += a[i];
		if (sum > left_max)
		{
			left_max = sum;
			l = i;
		}
	}
	int right_max = INT32_MIN;
	sum = 0;
	for (int i = mid + 1; i <= right; i++)
	{
		sum += a[i];
		if (sum > right_max)
		{
			right_max = sum;
			r = i;
		}
	}
	result.left = l;
	result.right = r;
	result.sum = left_max + right_max;
	return result;
}
answer maximum_subarray_violence(int *a,int n)
{
	/*暴力求解*/
	answer result;
	int left=0, right=0;
	int sum = 0;
	int max;
	max = 0;
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += a[j];
			if (sum > max)
			{
				max = sum;
				right = j;
				left = i;
			}
		}
	}
	result.left = left;
	result.right = right;
	result.sum = max;
	return result;
}
answer maximum_subarry_recursion(int *a, int left, int right)
{
	answer result;
	/*递归版本，总共有三种情况*/
	if (left == right)
	{
		result.left = left;
		result.right = right;
		result.sum =a[left];
		return result;
	}
	else
	{
		int mid = (left + right) / 2;
		answer left_result = maximum_subarry_recursion(a, left, mid);
		answer right_result = maximum_subarry_recursion(a, mid+1, right);
		answer crossing_result = maximum_subarray_crossing(a, left, right, mid);
		if (max(left_result, right_result, crossing_result) == left_result.sum)
			return left_result;
		else if (max(left_result, right_result, crossing_result) == right_result.sum)
			return right_result;
		else
			return crossing_result;
	}
}
void print_answer(answer result)
{
	cout <<"左下标为："<< result.left << endl;
	cout << "右下标位：" << result.right << endl;
	cout << "最大字串的值位:" << result.sum << endl;
}
void random_array(int *a, int n,int range)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % range + 1;
	}
}
answer maximum_subarray_linear(int *a, int index)
{
	answer result;
	if (index == 0)
	{
		result.left = 0;
		result.right = 0;
		result.sum = a[index];
		return result;
	}
	else
	{
		answer pre_result = maximum_subarray_linear(a, index - 1);
		answer current_result;
		int max=INT32_MIN, sum=0;
		for (int i = index; i >= 0; i--)
		{
			sum += a[i];
			if (sum > max)
			{
				max = sum;
				current_result.left = i;
				current_result.right = index;
				current_result.sum = max;
			}
		}
		if (current_result.sum > pre_result.sum)
		{
			return current_result;
		}
		else
		{
			return pre_result;
		}
	}
}
int main()
{
	/*int a[1000];
	int n =50 ;
	random_array(a, n, 100);*/
	//time_t begin, end;
	//begin = clock();
	//maximum_subarray_violence(a, n-1);
	//end = clock();
	//cout << "暴力法:" << double(end - begin) / CLOCKS_PER_SEC*100000000 << endl;
	//begin = clock();
	//maximum_subarry_recursion(a, 0, n-1);
	///*for (int i = 0; i < 10000; i++)
	//{
	//	for (int j = 0; j < 100; j++)
	//		i*j;
	//}*/
	//end = clock();
	//cout << "分治法:" << double(end - begin) / CLOCKS_PER_SEC*100000000 << endl;
	int a[6] = { -23,18,20,-7,12,8 };
	print_answer(maximum_subarray_linear(a, 5));
	system("pause");
	return 0;
}