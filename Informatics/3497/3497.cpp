#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int p(int x, int st)
{
	if(st == 1)
		return x;
	if(st == 0)
		return 1;
	return p(x, st-1) * x;
}

int main()
{
	int a, b, c, d, k;
	cin >> a >> b >> c;
	d = a;
	for(k = 0; d != 0; k++, d /= 10);
	//k++;
	//cout << k << endl;
	b *= p(10, k);
	a += b;
	//cout << a << " " << b << endl;
	k++;
	c *= p(10, k);
	a += c;
	cout << a << endl;
	//cin >> d;
	return 0;
}