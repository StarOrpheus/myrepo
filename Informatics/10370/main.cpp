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
struct edge
{
    int     flow;   //  Flow
    int     cap;    //  Capcity
    int     to;     //  To
    int     back;   //  Back
    bool    u;
    edge(){
        u = false;
    }
    edge(int to, int cap, int f, int b) : flow(f), cap(cap), to(to), back(b) {
        u = false;
    }
};
#define MIN(a, b) (a < b ? (a) : (b))
#define INF (1<<30)
int n;
int d[110];
string s;
bool used[110];
int k[26];
vector<vector<edge>> g;
#define S 100            // Source
#define T 101            // Gain

bool bfs(void)
{
    for(int i = 0; i < 110; i++)
        d[i] = -1;
    d[S] = 0;
    queue<int> q;
    q.push(S);
    while(!q.empty())
    {
        int v = q.front(); q.pop();
        for(int i = 0; i < g[v].size(); i++)
        {
            int to = g[v][i].to;
            if(d[to] == -1 && g[v][i].flow < g[v][i].cap)
            {
                d[to] = d[v] + 1;
                q.push(to);
            }
        }
    }
    return (d[T] != -1);
}

long dfs(int v, int dp)
{
    int pushed;
    if(v == T)
        return dp;
    if(!dp)
        return 0;
    for(int i = 0; i < g[v].size(); i++)
    {
        if(d[v] + 1 == d[g[v][i].to])
        {
            pushed = dfs(g[v][i].to, MIN(dp, g[v][i].cap - g[v][i].flow));
            if(pushed)
            {
                g[v][i].flow                        += pushed;
                g[g[v][i].to][g[v][i].back].flow    -= pushed;
                return pushed;
            }
        }
    }
    return 0;
}


int main() {
    //freopen("input.txt", "r", stdin);
//    freopen("/home/jyree/src/lel.out", "w", stdout);
    cin >> n;
    cin >> s;
    g.resize(110);
    memset((void *) k, '\0', sizeof(int)*26);
    for(int i = 0; i < n; i++)
        k[s[i]-'a']++;
    for(int i = 0; i < 26; i++)
    {
        if(k[i])
        {
            g[S].push_back(edge(i, k[i], 0, g[i].size()));
            g[i].push_back(edge(S, 0, 0, g[S].size()-1));
        }
    }
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            if(i != j && k[i] && k[j])
            {
                g[i].push_back(edge(26+j, INF, 0, g[j+26].size()));
                g[j+26].push_back(edge(i, 0, 0, g[i].size()-1));
            }
        }
    }
    for(int j = 0; j < 26; j++)
    {
        if(k[j])
        {
            g[j+26].push_back(edge(T, k[j], 0, g[T].size()));
            g[T].push_back(edge(j+26, 0, 0, g[j+26].size() - 1));
        }
    }

    /*for(int i = 0; i < 110; i++)
    {
        if(g[i].size())
            printf("#%ld ", i);
        for(int j = 0; j < g[i].size(); j++)
            printf("(%ld; %ld) ", g[i][j].to, g[i][j].back);
        if(g[i].size())
            putchar('\n');
    }*/
    int pot = 0;
    while(bfs())
    {
        memset((void *) used, '\0', sizeof(bool) * 110);
        while(int pu = dfs(S, 10000000))
        {
            pot += pu;
//            cout << pot << endl;
        }
    }
    if(pot != n)
    {
        cout << "Impossible\n";
        exit(EXIT_SUCCESS);
    }
    for(int i = 0; i < s.size(); i++)
    {
        for(int j = 0; j < g[s[i] - 'a'].size(); j++)
        {
            #define shit (g[s[i] - 'a'][j])
            if(shit.flow > 0)
            {
//                shit.u = 42;
                putchar(shit.to - 26 + 'a');
                shit.flow--;
                break;
            }
        }
    }
    putchar('\n');
    return 0;
}
