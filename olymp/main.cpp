#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <bitset>
#include <deque>
#include <memory>
#include <algorithm>
using namespace std;


#define MIN(a, b) ((a < b) ? (a) : (b))
#define MINN(a, b, c) (MIN(a, MIN(b, c)))
#define MAX(a, b) ((a > b) ? (a) : (b))
#define MAXX(a, b, c) (MAX(a, MAX(b, c)))

int main()
{
    const long long INF = 1000*1000*1000 + 7;
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int c[10020];
    char t;
    int n = 0;
    while((t = getchar()) != EOF && t != '\n')
    {
        c[++n] = t - '0';
    }
    vector<vector<vector<vector<long long > > > > f(n+12, vector<vector<vector<long long > > >(11, vector<vector<long long > >(11, vector<long long>(3, 0))));
    for(int x = 0; x <= 9; x++)
        for(int y = 0; y < 10; y++)
            for(int p = 0; p <= 1; p++)
                if(x + y == (10 * p) + c[n])
                    f[n][x][y][p] = 1;

    for(int k = n-1; k >= 1; k--)
    {
        for(int i = 0; i <= 9; i++)
            for(int j = 0; j <= 9; j++)
                for(int p = 0; p <= 1; p++)
                {
                    if(c[k] + (10 * p) == i + j)
                    {
                        long long ans = 0;
                        for(int x = 0; x <= 9; x++)
                            for(int y = 0; y <= 9; y++)
                                if(x != i && y != j)
                                {
                                    ans = (ans + f[k+1][x][y][0]) % INF;
                                }
                        f[k][i][j][p] = ans;
                    } else if(c[k] + (10 * p) - 1 == i + j)
                    {
                        long long ans = 0;
                        for(int x = 0; x <= 9; x++)
                            for(int y = 0; y <= 9; y++)
                                if(x != i && y != j)
                                {
                                    ans = (ans + f[k+1][x][y][1]) % INF;
                                }
                        f[k][i][j][p] = ans;
                    } else {
                        f[k][i][j][p] = 0;
                    }
                }
    }

    long long ans = 0;
    for(int x = 1; x <= 9; x++)
    {
        for(int y = 1; y <= 9; y++)
            for(int p = 0; p <= 0; p++)
               ans = (ans +f[1][x][y][p]) % INF;
    }
    cout << ans << endl;
    return 0;
}