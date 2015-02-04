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

#define S 1
#define F n
#define INF (1 << 30)

struct /*__attribute__((packed))*/ edge
{
    long long y, z, p, f;
    edge(){}
    edge(int y, int z, int f, int p) : y(y), z(z), f(f), p(p) {}
};

vector<int> d;
vector<int> kon;
//bool d[100000];
int n, m;
vector<vector<edge > > g;

inline bool bfs()
{
    for(int i = 1; i <= n; i++)
        d[i] = -1;
    d[1] = 0;
//    for(int i = 1; i <= n; i++)
//        printf("%ld ", d[i]);
//    putchar('\n');
    //cout << "One more tit\n" << endl;
    queue<int> q;
    q.push(1);
    while(!q.empty() && d[n] == -1)
    {
        int v = q.front(); q.pop();
        for(int i = 0; i < g[v].size(); i++)
        {
            if(d[g[v][i].y] == -1 && g[v][i].f < g[v][i].z)
            {
                d[g[v][i].y] = d[v] + 1;
                q.push(g[v][i].y);
            }
        }
    }
//    for(int i = 1; i <= n; i++)
//        printf("%ld ", d[i]);
//    putchar('\n');
//    putchar('\n');
//    putchar('\n');
    //printf("hmmm...\n");
    return (d[n] != -1);
}

long dfs(int v, int dp)
{
    int pushed;
    if(v == n)
        return dp;
    if(!dp)
        return 0;
    for(int i = kon[v]; i < g[v].size(); i++, kon[v]++)
    {
        if(d[v] + 1 == d[g[v][i].y])
        {
            pushed = dfs(g[v][i].y, min((long long) dp, g[v][i].z - g[v][i].f));
            if(pushed)
            {
                g[v][i].f += pushed;
                g[g[v][i].y][g[v][i].p].f -= pushed;
                return pushed;
            }
        }
    }
    return 0;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    kon.resize(n+1);
    d.resize(n+1, -1);
    int x,y,z;
    g.resize(n+1);
    for(int i = 0; i < m; i++)
    {
        //scanf("%ld %ld %ld", &x, &y, &z);
        cin >> x >> y >> z;
//        cout << i << endl;
        g[x].push_back(edge(y, z, 0, (int) g[y].size()  ));
        g[y].push_back(edge(x, 0, 0, (int) g[x].size()-1));
//        cout << i << endl;
    }
    int f;
    long long pot = 0;
    //printf("tits\n");
    //cout << "More tits " << endl;
    while(bfs())
    {
        kon.assign(n+1, 0);
        while(int pu = dfs(1, INF))
            pot += pu;
    }
    cout << pot << endl;
    return 0;
}