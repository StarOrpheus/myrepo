#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#define MIN(a, b) ((a < b) ? (a) : (b))
#define MAX(a, b) ((a > b) ? (a) : (b))

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int> > a(n+1, vector<int>(n+1) );
    vector<vector<char> > f(n+1, vector<char>(n+1, 0));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(a[i][j] == 1)
            {
                f[i][j] = f[i][j-1] + 1;
                continue;
            }
            f[i][j] = 0;
        }
    long long ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(!f[i][j])
                continue;
            //bool f = true;
            int x = i, y = j;
            for(int k = 1; x >= 1; k++, x--)
            {
                if(f[x][y] >= k)
                    ans++;
                else
                    break;
            }
        }
    cout << ans << endl;
    return 0;
}