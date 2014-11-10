#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <iostream>

#define UNL (1 << 31) - 1


using namespace std;


struct __attribute__((packed))  el{
	int n, k;
};

vector<vector<el> > a;
vector<el> h;

int n = 0;
void inline __attribute__((always_inline)) siftUp(int i)
{
	register long x;
	while(i > 1 && h[i].k < h[i / 2].k)
	{
		x = h[i].k;
		h[i].k = h[i / 2].k;
		h[i / 2].k = x;
		long i1 = x = h[i].n;
		h[i].n = h[i / 2].n;
		h[i / 2].n = x;
		i /= 2;
	}
}
void inline __attribute__((always_inline)) siftDown(int i)
{
	register int j, x;
	while(2 * i <= n)
	{
		j = i;
		if(h[2 * i].k < h[j].k)
			j = 2 * i;
		if(2 * i + 1 <= n && (h[2 * i + 1].k < h[j].k))
			j = 2 * i + 1;
		if(i == j)
			break;
		x = h[i].k; h[i].k = h[j].k; h[j].k = x;
		x = h[i].n; h[i].n = h[j].n; h[j].n = x;
		i = j;
	}
}


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	register int s = 1, f, m, p;
	scanf("%ld", (long *) &n);
	//vector<int> pr(n+1);
	h.resize((unsigned int) (n+1));
	for(int i = 1; i <= n; i++)
		h[i].n = i;
	a.resize((unsigned int) (n+1));
	for(int i = 1; i <= n; i++)
		h[i].k = UNL;
	scanf("%ld", (long *) &m);
	el t_el;
	for(int i = 0; i < m; i++)
	{
		int x, y, z;
		scanf("%ld %ld %ld\n", &x, &y, &z);
		t_el.k = z;
		t_el.n = y;
		a[x].push_back(t_el);
	}
	cout << " ended " << endl;
	s = 1; f = n;
	for(int i = 1; i <= a[s].size() ; i++)
		h[a[s][i-1].n].k = (h[a[s][i-1].n].k > a[s][i-1].k) ? a[s][i-1].k : h[a[s][i-1].n].k;
	h[s].k = 0; p = s;

	for(int i = n / 2; i >= 1; i--)
		siftDown(i);

	register int ld = n;
	int t;
	for(int i = 1; i <= ld; i++)
	{
		//long min = h[1].k, nmin = h[1].n;
		//p = 1;
		if(h[1].n == f)
		{
			printf("%ld\n", h[1].k);
			exit(EXIT_SUCCESS);
		}

		for(int j = 2; j <= n; j++)
		{
			register int nn = 0;
			register bool found = false;

			for(int l = 0; !found && l < a[h[1].n].size(); l++)
				if(h[j].n == a[h[1].n][l].n)
				{
					nn = l;
					found = true;
				}
			if(found && h[1].k + a[h[1].n][nn].k <= h[j].k)
			{
				h[j].k = h[1].k + a[h[1].n][nn].k;
				// cout << j << " " << a[p][j] << endl;
				//pr[h[j].n] = h[1].n;
				siftUp(j);
			}
		}

		t = h[1].k;
		h[1].k = h[n].k;
		h[n].k = t;
		t = h[1].n;
		h[1].n = h[n].n;
		h[n].n = t;
		n--;
		siftDown(1);
		/*
		for(int j = n; j >= 1; j--)
			siftUp(j);*/
		/*
		for(int i = 1; i <= n; i++)
			cout << h[i].n << " " << h[i].k << endl;
		cout << endl << endl << endl << endl;*/
	}
	printf("-1\n");
	return 0;
}
