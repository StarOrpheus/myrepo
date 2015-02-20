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
using namespace std;

#define INF (1<<30)
#define SWAP(x, y) x = x ^ y; y = x ^ y; x = x ^ y;
#define MAX(a, b) ((a > b) ? (a) : (b))

struct query
{
    int u;
    int v;
    int d;
    int id;
    query(){}
    query(int u, int v, int d, int id) : u(u), v(v), d(d), id(id) {}
};

int n, m, k;
vector<vector<int > > g;
vector<query> q;

inline bool comp(query a, query b)
{
    return (a.u != b.u) ? a.u < b.u : (a.v != b.v) ? a.v < b.v : a.d < b.d;
}

int last = -1;
int d[5500][2];
bool ans[1010000];

void bfs(int v)
{
    memset(d, -1, sizeof(d));
    queue<pair<int, int > > q;
    d[v][0] = 0;
    q.push(make_pair(v, 0));
    while(!q.empty())
    {
        int v   = q.front().first;
        int odd = q.front().second;
        q.pop();

        for(int i = 0; i < g[v].size(); i++)
        {
            const int to = g[v][i];
            if(d[to][odd^1] == -1)
            {
                d[to][odd^1] = d[v][odd] + 1;
                q.push(make_pair(to, odd^1));
            }
        }
    }
}

bool can(const query& q)
{
    if(g[q.v].size() == 0 || g[q.u].size() == 0)
        return false;
    if(last != q.u)
    {
        bfs(q.u);
    }
    int odd = q.d % 2;
    last = q.u;
    if(d[q.v][odd] == -1 || q.d < d[q.v][odd] || d[q.v][odd] % 2 != odd)
        return false;
    return true;
}

int main() {
//    freopen("/home/jyree/src/input", "r", stdin);
//    freopen("/home/jyree/src/output.txt", "w", stdout);
//    freopen("combos.in", "r", stdin);
//    freopen("combos.out", "w", stdout);
    cin >> n >> m >> k;
    g.resize(n);
    for(int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int i = 0;
    while(k--)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        x--; y--;
        q.push_back(query(x, y, z, i++));
    }
    k = q.size();
    sort(q.begin(), q.end(), comp);
    for(int i = 0; i < k; i++)
        ans[q[i].id] = can(q[i]);
    for(int i = 0; i < k; i++)
        printf("%s\n", (ans[i]) ? "TAK" : "NIE");
    return 0;
}

