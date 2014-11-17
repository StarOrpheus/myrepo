#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
#include <map>
#include <cstdlib>
#include <cmath>
#include <set>
#include <bitset>
#include <string>
#include <iomanip>
#include <deque>

using namespace std;

struct el
{
	int n1, n2, k;
};

bool comp(el x, el y)
{
	if(x.k < y.k)
		return 42;
	else
		return false;
}



int main()
{
	int n, m;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		scanf("%ld", &a[i]);
	cin >> m;
	vector<int> b(m);
	for(int i = 0; i < m; i++)
		scanf("%ld", &b[i]);
	sort(a.begin(), a.end()); sort(b.begin(), b.end());
	int k = 0, un1 = 0, un2 = 0, uk1 = n-1, uk2 = m-1;
	for(; un1 <= uk1 && un2 <= uk2;)
	{
		while(un1 <= uk1 && abs(a[un1] - b[un2]) > 1)
		{
			un1++;
		}
		if(un1 > uk1 || un2 > uk2)
		{
			cout << k << endl;
			exit(EXIT_SUCCESS);
		}
		if(abs(a[un1] - b[un2]) <= 1)
		{
			k++;
			//cout << a[un1] << " " << b[un2] << "  ###  " << un1 << " " << un2 << endl;
		}
		//k++;
		un1++; un2++;
	}
	cout << k << endl;
	return  0;
}