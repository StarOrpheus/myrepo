#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
using namespace std;



int main()
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	register int v = 9 * 3600;
	int x;
	cin >> x;
	v += x * 45 * 60;
	for(int i = 1; i < x; i++)
	{
		if(i % 2 == 0)
		{
			v += 15 * 60;
		} else
		{
			v += 300;
		}
	}
	cout << v / 3600 << " " << v % 3600 / 60 << endl;
	return 0;
}