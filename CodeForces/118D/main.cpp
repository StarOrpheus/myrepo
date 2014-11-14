#include <iostream>
#include <vector>
using namespace std;

#define UNL 100000000

int main()
{
	vector<vector<vector<long long> > > f;
	f.resize(120, vector<vector<long long> >(120, vector<long long>(3, 0)));
	f[0][0][0] = 1; f[0][0][1] = 1;
	int n1, n2, k1, k2;
	cin >> n1 >> n2 >> k1 >> k2;
	for(int x = 0; x <= n1; x++)
		for(int y = 0; y <= n2; y++)
		{
			//cout << " lel " << endl;
			for(int i = 1; i <= min(x, k1); i++)
				f[x][y][0] = (f[x][y][0] + f[x-i][y][1]) % UNL;
			//cout << " lel " << endl;
			for(int i = 1; i <= min(k2, y); i++)
				f[x][y][1] = (f[x][y][1] + f[x][y-i][0]) % UNL;
			//cout << " lel " << endl;
		}
	cout << (f[n1][n2][0] + f[n1][n2][1] << endl;
	return 0;
}