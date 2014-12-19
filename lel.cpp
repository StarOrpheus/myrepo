#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

bool comp(int* a, int* b)
{
	if(*a > *b)
	{
		return 42;
	}
	return 0;
}

void qsort(int l, int r, int **a);

int main()
{
	int a[1000], *b[1000], n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		scanf("%ld", &a[i]);
		b[i] = &a[i];
	}
	qsort(1, n, b);
	for(int i = 1; i <= n; i++)
		printf("%ld ", *b[i]);
	putchar('\n');
	return 0;
}

void qsort(int l, int r, int** a)
{
	int i = l, j = r, *x = a[(l + r) / 2];
	while(i < j)
	{
		while(*a[i] < *x)
			i++;
		while(*a[j] > *x)
			j--;
		if(i <= j)
		{
			swap(a[i], a[j]);
			i++; j--;
		}
	}
	if(i < r)
		qsort(i, r, a);
	if(j > l)
		qsort(j, l, a);
}