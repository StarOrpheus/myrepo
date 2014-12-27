#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
#include <queue>
#include <iomanip>
using namespace std;


int main()
{
    int n, m;
    cout << fixed << setprecision(2);
    cin >> n >> m;
    vector<vector<double> > a(n+1, vector<double>(m+1, 0));
    int t1, t2, t3;
    for(int i = 1; i <= n; i++)
    {
        cin >> t1 >> t2;
        a[i][t1] = t2;
    }
    int nn;
    cin >> nn;
    for(int i = 1; i <= nn; i++)
    {
        cin >> t1 >> t2 >> t3;
        for(int j = 1; j <= m; j++)
        {
            if(a[t2][j] < 0.0000000001)
                a[t2][j] = 0;
            if(a[t1][j] < 0.0000000001)
                a[t1][j] = 0;
            a[t2][j] += a[t1][j] / 100.0 * t3;
            a[t1][j] -= a[t1][j] / 100.0 * t3;
            if(a[t2][j] < 0.0000000001)
                a[t2][j] = 0;
            if(a[t1][j] < 0.0000000001)
                a[t1][j] = 0;
        }
    }
    long double all = 0;
    for(int i = 1; i <= m; i++)
        all += a[1][i];
    for(int i = 1; i <= m; i++)
    {
        if(a[1][i] < 0.0000000001)
            a[1][i] = 0;
        //if(a[1][i])
        //{
            cout << (a[1][i] / all * 100) << " ";
        //}
    }
    cout << endl;
    return 0;
}