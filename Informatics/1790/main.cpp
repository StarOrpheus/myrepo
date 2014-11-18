#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>


using namespace std;

struct __attribute__((packed)) mx
{
    int k, x, y;
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n;
    vector<int> a(n+1);
    vector<int> b;
    for(int i = 1; i <= n; i++)
        scanf("%ld", &a[i]);
    cin >> m;
    b.resize(m+1);
    for(int i = 1; i <= m; i++)
        scanf("%ld", &b[i]);

    vector<vector<int> > g(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            g[i][j] = (a[i] == b[j]) ? (g[i-1][j-1] + 1) : (max(g[i-1][j], g[i][j-1]));
    mx d;
    d.k = 0;
    d.k = g[n][m];
    d.x = n;
    d.y = m;
    if(d.k == 0)
    {
        exit(EXIT_SUCCESS);
    }
    vector<int> way;
    for(;g[d.x][d.y] != 0; d.x--, d.y--)
    {
        for(; d.y > 1 && g[d.x][d.y] == g[d.x][d.y-1]; d.y--);
        for(; d.x > 1 && g[d.x][d.y] == g[d.x-1][d.y]; d.x--);
        way.push_back(a[d.x]);
    }
    for(int i = way.size()-1; i >= 0; i--)
        printf("%ld ", way[i]);
    cout << endl;
    return 0;
}