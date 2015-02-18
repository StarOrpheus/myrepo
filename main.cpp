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
    edge(){}
    edge(int to, int cap, int cost, int fl, int back) : to(to), cap(cap), cost(cost), flow(fl), back(back) {}
};

#define S       210
#define T       211
#define START   101
#define INF     (1<<30)
int a[210];
int n;
vector<vector<edge > > g;
int id[500];
int d[500];
int p[500];
int pnum[500];


int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("/home/jyree/src/lel.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < 2*n; i++)
        scanf("%ld", &a[i]);
    for(int i = 0; i < 500; i++)
        p[i] = -1;
    g.resize(250);
    for(int i = 0; i < 2*n; i++)
    {
        g[S].push_back(edge(i, 1, 0, 0, g[i].size()));
        g[i].push_back(edge(T, 0, 0, 0, g[S].size()-1));
    }
    for(int i = 0; i < 2*n; i++)
    {
        for(int j = 0; j < 2*n; j++)
        {
            if(j == 0 || a[i] != a[j-1])
            {
                g[i].push_back(edge(j+START, 1, /*400 - */((abs(j - i) - 1) * 10), 0, g[j+START].size()));
                g[j+START].push_back(edge(i, 0, -1*(/*400 - */((abs(j - i) - 1) * 10)), 0, g[i].size()-1));
            }
        }
    }
    for(int i = 0; i < 2*n; i++)
    {
        g[i+START].push_back(edge(T, 1, 0, 0, g[T].size()));
        g[T].push_back(edge(i+START, 0, 0, 0, g[i+START].size()));
    }
    int cost = 0, flow = 0;
    while(true)
    {
        memset((void *) id, '\0', 500);
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
            id[v] = 2;
        }
        if(d[T] == INF)
            break;
        int add = INF;
        int v = T;
        cout << d[T] << endl;
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
            int u = p[v];
            int i = pnum[v];
            g[u][i].flow += add;
            g[v][g[u][i].back].flow -= add;
            cost += g[u][i].cost*add;
            v = u;
        }
    }
    for(int i = 0; i < 2*n; i++)
    {
        for(int j = 0; j < g[i].size(); j++)
        {
            if(g[i][j].flow > 0)
            {
                printf("%ld ", a[g[i][j].to - START]);
                g[i][j].flow--;
                break;
            }
        }
    }
    return 0;
}
