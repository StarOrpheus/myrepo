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
using namespace std;

struct edge{
    int to;
    int cap;
    int cost;
    int flow;
    int back;
//    edge(){}
//    edge(int to, int cap, int cost, int flow, int back)
//    {
//        to = to; cap = cap; cost = cost; flow = flow; back = back;
//    }
};

#define S       (2*n)
#define T       (2*n+1)
#define START   n
#define INF     (1<<30)
int a[210];
int n;
vector<vector<edge > > g;
int id[500];
int d[500];
int p[500];
int pnum[500];
int l[500];
int r[500];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("/home/jyree/src/lel.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < 2*n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < 500; i++)
        p[i] = -1;
    for(int i = 0; i < 500; i++)
        l[i] = -1, r[i] = -1;
    for(int i = 0; i < 2*n; i++)
    {
        --a[i];
        if(l[a[i]] == -1)
        {
            l[a[i]] = i;
        } else
        {
            r[a[i]] = i;
        }
    }
    g.resize(250);
    for(int i = 0; i < n; i++)
    {
        edge e1 = {i, 1, 0, 0, g[i].size()};
        edge e2 = {S, 0, 0, 0, g[S].size()};
        g[S].push_back(e1);
        g[i].push_back(e2);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int curcost = min(abs(l[i] - j) + abs(r[i] - j - n), abs(r[i] - j) + abs(l[i] - j - n));
            edge e1 = {j + START, 1, curcost, 0, g[j+START].size()};
            edge e2 = {i, 0, -curcost, 0, g[i].size()};
            g[i].push_back(e1); g[j + START].push_back(e2);
        }
    }
    for(int i = 0; i < n; i++)
    {
        edge e1 = {T, 1, 0, 0, g[T].size()};
        edge e2 = {i+START, 0, 0, 0, g[i+START].size()};
        g[i+START].push_back(e1); g[T].push_back(e2);
    }
    int cost = 0, flow = 0;
    while(true)
    {
        memset((void *) id, 0, 500);
        for(int i = 0; i < 500; i++)
            d[i] = INF;
        d[S] = 0;
        id[S] = 1;
        deque<int> q;
        q.push_back(S);
        while(!q.empty())
        {
            int v = q.front();
            q.pop_front();
            id[v] = 2;
            for(int i = 0; i < g[v].size(); i++)
            {
                edge e = g[v][i];
                if(e.cap > e.flow && d[e.to] > d[v] + e.cost)
                {
                    d[e.to]         = d[v] + e.cost;
                    p[e.to]         = v;
                    pnum[e.to]      = i;
                    if(id[e.to] == 0)
                    {
                        q.push_back(e.to);
                        id[e.to] = 1;
                    } else if(id[e.to] == 2)
                    {
                        q.push_front(e.to);
                        id[e.to] = 1;
                    }
                }
            }
        }
        if(d[T] == INF)
            break;
        int add = INF;
        int v = T;
        while(v != S)
        {
            int u = p[v];

            int i = pnum[v];
            add = min(add, g[u][i].cap - g[u][i].flow);
            v = u;
        }

        flow += add;
        v = T;
        while(v != S)
        {
            int u                   =   p[v];
            int i                   =   pnum[v];
            g[u][i].flow            +=  add;
            g[v][g[u][i].back].flow -=  add;
            cost += g[u][i].cost * add;
            v = u;
        }
//        cout << add << endl;
    }
    int ans[n+1];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < g[i].size(); j++)
        {
            if(g[i][j].flow > 0 && g[i][j].to != S)
            {
//                printf("%ld ", a[g[i][j].to - START]);
                ans[g[i][j].to - n + 1] = i + 1;
            }
        }
    }
    for(int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    for(int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    putchar('\n');
    return 0;
}
