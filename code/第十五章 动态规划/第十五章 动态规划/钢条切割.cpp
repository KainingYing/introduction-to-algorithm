//#include <iostream>
//using namespace std;
//int max(int a, int b)
//{
//	return a > b ? a : b;
//}
//int memoized_cut_rod_aux(int *p, int n, int *r)
//{
//	if (r[n] >= 0)
//		return r[0];
//	if (n == 0)
//		return 0;
//	else
//	{
//		int q = -1;
//		for (int i = 1; i <= n; i++)
//			q = max(q, p[i] + memoized_cut_rod_aux(p, n - i, r));
//		r[n] = q;
//		return  q;
//	}
//}
//int memoized_cut_rod(int *p, int n,int *r)
//{
//	for (int i = 0; i < n; i++)
//	{
//		r[i] = -1;
//	}
//	return memoized_cut_rod_aux(p, n, r);
//}
//int bottom_up_cut_rod(int *p,int n,int *r)
//{
//	if (n == 0)
//		return 0;
//	else
//	{
//		int q=-1;
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= i; j++)
//				q = max(q, p[j] + r[i-j]);
//			r[i] = q;
//		}
//	}
//	return r[n];
//}
//int extended_bottom_up_rod(int *p, int n,int *r,int *s)
//{
//	r[0] = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		int q = -1;
//		for (int j = 1; j <= i; j++)
//		{
//			if (q < r[i - j] + p[j])
//			{
//				q = r[i - j] + p[j];
//				s[i] = j;
//			}
//		}
//		r[i] = q;
//	}
//	return r[n];
//}
//int cost_cut(int *p, int n, int *r, int *s,int c)
//{
//	r[0] = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		int q = -1;
//		for (int j = 1; j <= i; j++)
//		{
//			if (j == i)
//			{
//				q = (q < p[i] ? p[i] : q);
//				s[i] = j;
//			}
//			else
//			{
//				if (q < r[i - j] + p[j]-c)
//				{
//					q = r[i - j] + p[j]-c;
//					s[i] = j;
//				}
//			}
//		}
//		r[i] = q;
//	}
//	return r[n];
//}
//void print_cut_rod_solution(int *p, int n,int *r,int *s)
//{
//	cost_cut(p, n, r, s,0);
//	while (n > 0)
//	{
//		cout << s[n] << ' ';
//		n = n - s[n];
//	}
//}
//int extended_memoized_cut_rod_aux(int *p, int n, int *r, int *s)
//{
//	if (r[n] >= 0)
//		return r[n];
//	int q;
//	if (n == 0)
//		q = 0;
//	else
//	{
//		q = -1;
//		for (int i = 0; i <= n; i++)
//		{
//			int value = extended_memoized_cut_rod_aux(p, n - i, r, s);
//			if (q < p[i] + value)
//			{
//				q = value;
//				s[n] = i;
//				r[n] = q;
//			}
//		}
//	}
//	return r[n];
//}
//int extended_memoized_cut_rod(int *p, int n, int *r, int *s)
//{
//	for (int i = 0; i <= n; i++)
//		r[i] = -1;
//	return extended_memoized_cut_rod_aux(r, n, r, s);
//}
//void print_momorized_cut_rod_solution(int *p, int n, int *r, int *s)
//{
//	extended_bottom_up_rod(p,n,r,s);
//	while (n > 0)
//	{
//		cout << s[n] << ' ';
//		n = n - s[n];
//	}
//}
//int main()
//{
//	int p[11] = { 0,1,5,8,9,10,17,17,20,24,30 };
//	int *r = new int[100];
//	int *s = new int[100];
//	print_momorized_cut_rod_solution(p, 7, r, s);
//
//
//	system("pause");
//	delete[]r;
//	delete[]s;
//
//	system("pause");
//
//
//
//	return 0;
//}