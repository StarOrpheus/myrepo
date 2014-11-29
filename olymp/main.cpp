#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define INF ((1<<30)-1)

struct __attribute__((packed)) vf
{
	int v, weight;
};

vf inline __attribute__((always_inline)) makev(int v, int weight)
{
	vf temp;
	temp.v = v;
	temp.weight = weight;
	return temp;
}

int main()
{
	int n, m, s;
	cin >> n >> m >> s;
	vector<vf> g(m+1, makev(0, -1));
	register int x, y;
	for(int i = 1; i <= n; i++)
	{
		scanf("%ld %ld", &x, &y);
		if(g[y].v == 0)
		{
			g[y].v = x;
			g[y].weight = i;
		}
	}
	vector<int> f(m+1, INF);
	f[s] = 0;
	vector<int> q(n+1, 0);
	int un = 0, uk = 1;
	q[un] = s;
	while(un <= uk)
	{
		int k = q[un];
		un++;
		if(g[k].v == 0)
		{
			cout << f[k] << endl;
			exit(EXIT_SUCCESS);
		}
		if(f[g[k].v] != INF) {
			cout << -1 << endl;
			exit(EXIT_SUCCESS);
		}
		q[uk] = g[k].v;
		uk++;
		f[g[k].v] = f[k] + 1;
	}




	return 0;
}
