#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	long long a, ans;
	cin >> a;
	for(int i = 1;; i++)
	{
		long long x = a + i;
		x = abs(x);
		while(x != 0 && x != 1)
		{
			if(x % 10 == 8)
			{
				cout << i << endl;
				exit(EXIT_SUCCESS);
			}
			x /= 10;
		}
	}
	return 0;
}
