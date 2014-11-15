#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
using namespace std;



int main()
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	register int x;
	register long sum = 0;
	while(1)
	{
		cin >> x;
		if(!x)
		{
			cout << sum << endl;
			exit(EXIT_SUCCESS);
		}
		sum += x;
	}
	return 0;
}