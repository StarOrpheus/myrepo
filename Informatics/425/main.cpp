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
//#include <unordered_map>
#include <deque>
#include <cmath>
#include <bitset>
#include <limits>

using namespace std;

const int maxl          = /*numeric_limits<int>::max();*/ (1<<28);
const long long maxll   = numeric_limits<long long>::max();
#define SWAP(x, y) x = x ^ y; y = x ^ y; x = x ^ y;
#define MAX(a, b) ((a > b) ? (a) : (b))
#define MIN(a, b) ((a < b) ? (a) : (b))
#define MOD 1000000007
#define mp(a, b) make_pair(a, b)

int n, m;
vector<int> citycost;
int money = 0;
vector<vector<int > > g;
vector<int> pr;
vector<int> d;
vector<bool> used;
vector<vector<int > > eid;
vector<int> stat;

int main()
{
#ifdef DEBUG
    freopen("/home/jyree/src/TEST/input.txt", "r", stdin);
#endif
    scanf("%d %d", &n, &m);
    pr.resize(n+1);
    d.resize(n+1, maxl);
    used.resize(n+1, false);
    stat.resize(m+1, 0);
    g.resize(n+1, vector<int>(n+1, maxl));
    citycost.resize(n+1, 0);
    eid.resize(n+1, vector<int>(n+1));


    for(int i = 1; i <= n; i++)
        scanf("%d", &citycost[i]);
    for(int i = 0; i < m; i++)
    {
        int x, y, z, t;
        scanf("%d %d %d %d", &x, &y, &z, &t);
        g[x][y] = t + citycost[y];
        g[y][x] = t + citycost[x];
        if(z == 1)
        {
            stat[i+1] = -1;
            money += t;
        }
        eid[x][y] = i+1;
        eid[y][x] = i+1;
    }
    pr[1] = -1;
    for(int i = 1; i <= n; i++)
        if(g[1][i] != maxl)
        {
            pr[i] = 1;
            d[i] = g[1][i];
        }
    used[1] = true;
    for(int i = 2; 1; i++)
    {
        int vcur = 1, mnl = maxl;
        for(int j = 2; j <= n; j++)
            if(!used[j] && d[j] < mnl)
            {
                vcur = j;
                mnl = d[j];
            }
        if(mnl == maxl)
            break;
        used[vcur] = true;
        for(int j = 2; j <= n; j++)
        {
            if(g[vcur][j] != maxl && d[vcur] + g[vcur][j] < d[j])
            {
                d[j] = d[vcur] + g[vcur][j];
                pr[j] = vcur;
            }
        }
    }

    if(d[n] > money)
    {
        puts("-1\n");
        exit(EXIT_SUCCESS);
    }
    vector<int> way;
    int curv = n;
    while(curv != -1)
    {
//        printf("curv -> %d\n", curv);
        way.push_back(curv);
        curv = pr[curv];
    }
    reverse(way.begin(), way.end());
    vector<int> prod, cup;
    for(int i = 0; i < way.size() - 1; i++)
    {
        const int cureid = eid[way[i]][way[i+1]];
        if(stat[cureid] == 0)
        {
            cup.push_back(cureid);
        }
        if(stat[cureid] == -1)
        {
            stat[cureid] = 2;
        }
    }
    for(int i = 1; i <= m; i++)
        if(stat[i] == -1)
            prod.push_back(i);
    printf("%d ", prod.size());
    for(int i = 0; i < prod.size(); i++)
        printf("%d ", prod[i]);
    printf("\n%d ", cup.size());
    for(int i = 0; i < cup.size(); i++)
        printf("%d ", cup[i]);
    putchar('\n');
    for(int i = 0; i < way.size(); i++)
        printf("%d ", way[i]);
    putchar('\n');
//    cout << stat[eid[1][3]] << endl;
    return 0;
}
