#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	if(a == b)
	{
		cout << "infinity\n";
		exit(EXIT_SUCCESS);
	}
	int t = a - b;
	int k = 0;
	int d = 2;
	while(d * d < t)
	{
		if(t % d == 0)
		{
			if(d > b)
				k++;
			if(t / d > b)
				k++;
		}
		d++;
	}
	if(t > b)
		k++;
	if(d > b && t % d == 0)
		k++;
	cout << k << endl;
	return 0;
}
