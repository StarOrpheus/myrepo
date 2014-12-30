#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <fstream>
#include <limits>
#include <list>
#include <queue>
#include <iomanip>
#include <cpufreq.h>
#include <bitset>

using namespace std;
#define vecotr vector

vector<bool> used;
vector<vector<int> > g;
vector<int> mt;

bool dfs(int v)
{
    if(used[v])
        return false;
    used[v] = true;
    for(int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if(mt[to] == -1 || dfs(mt[to]))
        {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int n, k, t1, t2;
    cin >> n >> k;
    g.resize(n+1);
    for(int i = 1; i <= k*n; i++)
    {
        cin >> t1 >> t2;
        g[t1].push_back(t2);
    }
    used.resize(n+1);
    mt.resize(n+1, -1);
    for(int i = 1; i <= n; i++)
    {
        used.assign(n+1, false);
        dfs(i);
    }
    for(int i = 1; i <= n; i++)
    {
        if(!(mt[i] == -1))
        {
            cout << mt[i] << " " << i << endl;
        }
    }
    return 0;
}
