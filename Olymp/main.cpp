#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

bool inline comp(int x, int y)
{
	return (x < y) ? true : false;
}

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	vector<int> a, b;
	int n, m;
	cin >> n >> m;
	register int x;
	for(int i = 0; i < n; i++)
	{
		scanf("%ld", &x);
		a.push_back(x);
	}
	for(int i = 0; i < m; i++)
	{
		scanf("%ld", &x);
		b.push_back(x);
	}
	int k = 0;
	int uk1 = n - 1, uk2 = m - 1;
	sort(a.begin(), a.end(), comp);
	sort(b.begin(), b.end(), comp);
	k += n;
	for(; uk1 >= 0 && uk2 >= 0; uk1--)
	{
		for(; uk2 >= 0 && a[uk1] <= b[uk2]; uk2--);
		if(a[uk1] > b[uk2])
		{
			k++;
			//cout << a[uk1] << " # " << b[uk2] << endl;
			uk2--;
			continue;
		}
		//cout << uk1 << " @ " << uk2 << endl;
	}
	cout << k << endl;
	return 0;
}