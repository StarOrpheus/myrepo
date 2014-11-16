#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stdio.h>

using namespace std;

vector<vector<int> > a;
int x, y, n;
vector<char> cl;
vector<int> p;
int ans = 0;

void dfs(int v, int pred)
{
	//cout << v << " " << pred << endl;
	if(cl[v] == 1)
	{
		ans++;
		return;
	}
	if (cl[v]==2)
		return;
	cl[v] = 1;
	for(int i = 0; i < a[v].size(); i++)
	{
		int to = a[v][i];
		if(to == pred)
			continue;
		dfs(to,v);
	}
	cl[v] = 2;
	return;
}


int main()
{
	cin >> n;
	a.resize(n+1);
	for(int i = 1; i <= n; i++)
		scanf("%ld %ld", &x, &y);
	int m;
	cin >> m;
	for(int i = 1; i <= m; i++)
	{
		scanf("%ld %ld", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	p.assign(n + 1, -1);
	cl.resize(n+1, 0);
	//cycle_st = -1;
	//int s = 0;
	for(int i = 1; i <= n; i++)
		if (cl[i] == 0)
			dfs(i,i);
	ans++;
	cout << ans <<  endl;
	return 0;
}