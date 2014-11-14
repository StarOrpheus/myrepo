#include <iostream>
#include <vector>
#include <cstdio>
#include <stdlib.h>

using namespace std;

#define  UNL (1<<31)

int main()
{
	int n;
	cin >> n;
	vector<vector<int> > f(n+1, vector<int>(n+1, UNL));
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++)
		scanf("%ld", &a[i]);
	for(int i = 1; i <= n; i++)
		f[i][i] = (a[i] == 1) ? -1 : 1;
	if(n == 1)
	{
		cout << 1 - a[1] << endl;
		exit(EXIT_SUCCESS);
	}
	for(int i = 1; i <= n-1; i++)
		for(int l = 1; l <= n - i; l++){
			f[l][l + i] = f[l + 1][l + i] + f[l][l];
			//cout << l << " " << l + i << endl;
		}
	vector<long long> s(n+1);
	s[1] = a[1];
	for(int i = 2; i <= n; i++)
		s[i] = s[i-1] + a[i];
	vector<long long> s2(n+1);
	vector<int> m(n+1, -2);
	m[1] = f[1][1];
	for(int j = 2; j <= n; j++)
	{
		m[j] = m[j-1];
		for(int i = 1; i <= j; i++)
			if(m[j] < f[i][j])
				m[j] = f[i][j];
	}

	for(int i = 1; i <= n; i++)
		s2[i] = max(s[i] + m[i], s2[i-1]);
	cout << s2[n] << endl;
	return 0;
}