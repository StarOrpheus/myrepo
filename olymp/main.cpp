#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, l;
	cin >> n >> l;
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++)
		//scanf("%ld", &a[i]);
		cin >> a[i];
	sort(a.begin()+1, a.end());
	//a[0] = 0;
	int max_l = -1;
	for(int i = 2; i <= n; i++)
	{
		if(a[i]-a[i-1] > max_l)
		{
			max_l = a[i] - a[i-1];
			//cout << a[i] << " " << a[i-1] << endl;
		}
	}
	if(n == 1)
	{
		printf("%.9f\n" , (double) max(a[1], l - a[1]));
		exit(EXIT_SUCCESS);
	}
	if(a[1] > max_l / 2.0 || l - a[n] > max_l / 2.0)
	{
		if(a[1] > l - a[n])
			printf("%.9f \n", (double) a[1]);
		else
			printf("%.9f \n", (double) l-a[n]);
		exit(EXIT_SUCCESS);
	}

	//cout << a[3] << " " << a[5] << endl;
	printf("%.9f\n", max_l / 2.0000);
	return 0;
}
