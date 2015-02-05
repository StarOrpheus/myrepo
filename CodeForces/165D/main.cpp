#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <iomanip>
#include <cstring>
#include <queue>
#include <deque>
using namespace std;

#define INF (1<<30)
#define MAX(x, y) ((x > y) ? (x) : (y))
#define MIN(x, y) ((x < y) ? (x) : (y))

#define BLACK 0
#define WHITE 1

bool pf[400100];
struct edge;
vector<int> d;
int root, n;
vector<vector<int > > g;
vector<edge> a;
vector<vector<int > > ways;
int nomer_vetki[300100];
struct edge
{
    int s;
    int f;
    edge(){}
    edge(int s, int f) : s(s), f(f) {}
};
void dfs(int v, vector<int> &c)
{
    pf[v] = true;
    c.push_back(v);
    for(int i = 0; i < g[v].size(); i++)
    {
        if(!pf[g[v][i]])
        {
//            c.push_back(g[v][i]);
            dfs(g[v][i], c);
            return;
        }
    }
    return;
}

class tree
{
public:
    vector<int> a;
    int n, z;
    tree(){}
    tree(vector<int> way)
    {
        n = way.size();
        z = 1;
        while(z < n)
            z <<= 1;
        a.resize(2*z+3, BLACK);

    }
    int inline fsum(int l, int r, int lv, int rv, int v)
    {
        if(lv > r || rv < l)
            return 0;
        if(!(lv >= l && rv <= r))
        {
            return fsum(l, r, lv, (lv + rv) / 2, 2 * v) + fsum(l, r, (lv + rv) / 2 + 1, rv, 2 * v + 1);
        }
        return a[v];
    }
    void change(int l, int color)
    {
        a[l] = color; l /= 2;
        while(l >= 1)
        {
            a[l] = a[2*l] + a[2*l + 1];
            l /= 2;
        }
        return;
    }
};
vector<tree> les;
int main()
{
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n;
    g.resize(n+1);
    d.resize(n+1, INF);
    for(int i = 0; i < n-1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        a.push_back(edge(MIN(x, y), MAX(x, y)));
    }
    root = -1;
    for(int i = 1; i <= n; i++) {
        if(g[i].size() > 2)
                root = i;
    }
    if(root == -1)
    {
        for(int i = 1; i <= n; i++) {
            if(g[i].size() >= 2)
                root = i;
        }
    }
    ways.resize(g[root].size(), vector<int>(1, root));
    for(int i = 0; i < g[root].size(); i++)
    {
        memset((void *) pf, '\0', n*sizeof(bool));
        pf[root] = true;
        dfs(g[root][i], ways[i]);
    }
    for(int i = 0; i < ways.size(); i++)
    {
        for(int j = 0; j < ways[i].size(); j++)
        {
            d[ways[i][j]]   = j;
            nomer_vetki[ways[i][j]] = i;
        }
    }
    int m;
    les.resize(ways.size());
    for(int i = 0; i < ways.size(); i++)
    {
        les[i] = tree(ways[i]);
    }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int id;
            cin >> id;
            id--;
            int num_r = MAX(d[a[id].s], d[a[id].f]);
            les[nomer_vetki[a[id].s]].change(num_r + les[nomer_vetki[a[id].s]].z - 1, BLACK);
        } else if(type == 2)
        {
            int id;
            cin >> id;
            id--;
            int num_r = MAX(d[a[id].s], d[a[id].f]);
//            cout << num_r << endl;
            les[nomer_vetki[a[id].s]].change(num_r + les[nomer_vetki[a[id].s]].z - 1, WHITE);
        } else
        {
            int x, y;
            cin >> x >> y; // чтобы ребра с x+1 по y чекал
            if(x > y)
            {
                int t = x;
                x = y;
                y = t;
            }
            if(nomer_vetki[x] == nomer_vetki[y])
            {
                bool flag = !les[nomer_vetki[x]].fsum(les[nomer_vetki[x]].z + x, les[nomer_vetki[x]].z + y - 1, les[nomer_vetki[x]].z, les[nomer_vetki[x]].z + les[nomer_vetki[x]].n - 1, 1);
                if(flag)
                {
                    cout << abs(d[x] - d[y]) << endl;
                } else
                {
                    cout << -1 << endl;
                }
            } else
            {
                bool flag1, flag2;
                flag1 = !les[nomer_vetki[x]].fsum(les[nomer_vetki[x]].z, les[nomer_vetki[x]].z + x - 1, les[nomer_vetki[x]].z, les[nomer_vetki[x]].z + n - 1, 1);
                flag2 = !les[nomer_vetki[y]].fsum(les[nomer_vetki[y]].z, les[nomer_vetki[y]].z + x - 1, les[nomer_vetki[y]].z, les[nomer_vetki[y]].z + n - 1, 1);
                if(flag1 && flag2)
                {
                    cout << (d[x] + d[y]) << endl;
                } else
                {
                    cout << -1 << endl;
                }
            }
        }
    }
    return 0;
}