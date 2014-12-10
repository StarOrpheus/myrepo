#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n+1, vector<int>(m+1) );
    vector<vector<int> > f(n+1, vector<int>(m+1, 0) );
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            f[i][j] = f[i][j-1] + f[i-1][j] - f[i-1][j-1] + a[i][j];
    int max_s = -1 * (1<<30) - 1;
    for(int i1 = 1; i1 <= n; i1++)
        for(int j1 = 1; j1 <= m; j1++)
            for(int i2 = 1; i2 <= i1; i2++)
                for(int j2 = 1; j2 <= j1; j2++)
                    if(f[i1][j1] - f[i2-1][j1] - f[i1][j2-1] + f[i2-1][j2-1] > max_s)
                    max_s = f[i1][j1] - f[i2-1][j1] - f[i1][j2-1] + f[i2-1][j2-1];
    cout << max_s << endl;
    return 0;
}
