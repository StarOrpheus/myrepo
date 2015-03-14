#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <queue>
#include <locale>
#include <deque>
#include <cmath>
#include <bitset>
#include <limits>
using namespace std;

const int maxl          = numeric_limits<int>::max();
const long long maxll   = numeric_limits<long long>::max();
#define SWAP(x, y) x = x ^ y; y = x ^ y; x = x ^ y;
#define MAX(a, b) ((a > b) ? (a) : (b))
#define MIN(a, b) ((a < b) ? (a) : (b))
#define MOD 1000000007

// Не забыть закрыть окно!!!
#define LEL
int timer = 1, tin[110000], tout[110000], up[110000][36];

vector<vector<int > > g;
int n;
const int lgs = 33;

void dfs(int v, int p = 0)
{
    tin[v] = timer++;
    up[v][0] = p;
    for(int i = 1; i <= lgs; i++)
        up[v][i] = up[up[v][i-1]][i-1];
    for(int i = 0; i < g[v][i]; i++)
        if(g[v][i] != p)
            dfs(g[v][i], v);
    tout[v] = timer++;
}

inline bool upper (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

inline int lca(int a, int b)
{
    if(upper(a, b))
        return a;
    if(upper(b, a))
        return b;
    for(int i = lgs; i >= 0; i--)
        if(!upper(up[a][i], b))
            a = up[a][i];
    return up[a][0];
}


int main()
{
#ifdef LEL
	freopen("/home/jyree/src/TEST/input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    g.resize(n+1);
    for(int i = 0; i <= lgs; i++)
        up[1][i] = 1;
    for(int i = 0; i < n-1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    int k;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= lgs; j++)
            printf("%d ", up[i][j]);
        putchar('\n');
    }
    scanf("%d", &k);
    while(k--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}