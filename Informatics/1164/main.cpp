#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdio.h>

using namespace std;

struct __attribute__((packed))  el{
    int n, k;
};

vector<long> h;
int n;
int b;

int inline __attribute__((always_inline)) siftUp(int i)
{
    long x, t = i;
    while(i > 1 && h[i] > h[i / 2])
    {
        x = h[i];
        h[i] = h[i / 2];
        h[i / 2] = x;
        i = i / 2;
	    t = i;
	    //cout << t << endl;
    }
	return t;
}
int inline __attribute__((always_inline)) siftDown(int i)
{
    int j, x, t = i;
    bool finish = false;
    while(2 * i <= n && !finish)
    {
        j = i;
        if(h[2 * i] > h[j])
            j = 2 * i;
        if(2 * i + 1 <= n && h[2 * i + 1] > h[j])
            j = 2 * i + 1;
        if(i == j)
            finish = true;
        else {
            x = h[i];
            h[i] = h[j];
            h[j] = x;
        }
        i = j;
	    t = i;
    }
	return t;
}

el inline __attribute__((always_inline)) extractMax(void)
{
	if(n == 0)
	{
		el a;
		a.n = -1;
		return a;
	} else
	{
		el a;
		a.n = h[1];
		h[1] = h[n];
		n--;
		a.k = siftDown(1);
		return a;
	}
}

int inline __attribute__((always_inline)) add(int x)
{
	if(n >= b)
	{
		return -1;
	} else
	{
		n++;
		h[n] = x;
		return siftUp(n);
	}
}

int inline __attribute__((always_inline))  exdel(int i)
{
	if(n < i)
	{
		return -1;
	} else
	{
		int t = h[i];
		h[i] = h[1] + 1;
		siftUp(i);
		h[1] = h[n];
		n--;
		siftDown(1);
		return t;
	}
}

int main()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	cin >> n;
	h.resize(n+1);
	for(int i = 1; i <= n; i++)
		cin >> h[i];
	for(int i = n; i >= 1; i--)
		siftDown(i);
	for(int i = 1; i <= n; i++)
		cout << h[i] << " ";
	cout << endl;
	int ld = n;
	for(int i = 1; i <= ld-1; i++)
	{
		int t = h[1];
		h[1] = h[n];
		h[n] = t;
		n--;
		siftDown(1);
		for (int j = 1; j <= n; j++)
			cout << h[j] << " ";
		cout << endl;

	}
	n = ld;
	for(int i = 1; i <= n; i++)
		cout << h[i] << " ";
	cout << endl;
	return 0;
}

