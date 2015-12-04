#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
#include <cctype>

using namespace std;

#define mkp(a, b) make_pair((a), (b))
#define F first
#define S second

vector<int> t;
int n, m;
vector<int> a;

void build(vector<int>& v)
{
//	n = v.size();
	t.resize(n << 1 | 1);
	for (int i = 0; i < n; i++)   
		t[i+n] = v[i];
	for (int i = n-1; i > 0; i--)
		t[i] = t[i << 1] + t[i<<1 | 1];    
}

int query(int l, int r)
{
	int res = 0;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1)
	{
		if(l & 1)
			res += t[l++];
		if(r & 1)
			res += t[--r];
	}
	return res;
}


int main(int argc, char *argv[])
{
	scanf("%d", &n);   
    a.resize(n);   
	for (int i = 0; i < n; i++)	
		scanf("%d", &a[i]);
	scanf("%d", &m);

	build(a);
	
	while(m--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", query(x-1, y));
	}
    return 0;
}

