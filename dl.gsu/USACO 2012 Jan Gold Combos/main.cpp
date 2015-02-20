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

struct vertex
{
    int     next[3];
    int     p;
    int     go[3];
    char    pch;
    bool    leaf;
    int     cnt;
    int     up;
    int     link;
    int     bc = 0;
};

inline void init(int k);
inline void add_string(const string& s);
inline int link(int v);
inline int go(int v, char c);
inline int cnt(int v);

vertex t[2000100];
int k = 1, n, ks;
int f[1010][10000];
inline void init(int k)
{
    t[k].leaf   = false;
    t[k].p      = -1;
    t[k].cnt    = -1;
    t[k].link   = -1;
    for(int i = 0; i < 3; i++)
        t[k].next[i] = -1, t[k].go[i] = -1;
}
inline void add_string(const string &s)
{
    int v = 0;
    for(int i = 0; i < s.length(); i++)
    {
        int c = (int) s[i] - 'A';
        if(t[v].next[c] == -1)
        {
            init(k);
            t[k].p          = v;
            t[k].pch        = c;
            t[v].next[c]    = k;
            k++;
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
}
inline int link(int v)
{
    if(t[v].link == -1)
    {
        if(v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(link(t[v].p), t[v].pch);
    }
    return t[v].link;
}
inline int go(int v, char c)
{
    if(t[v].go[c] == -1)
    {
        if(t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else if(v == 0)
            t[v].go[c] = 0;
        else
            t[v].go[c] = go(link(v), c);
    }
    return t[v].go[c];
}
inline int cnt(int v)
{
    if(t[v].cnt == -1)
    {
        if(v == 0)
            t[v].cnt = 0;
        else
            t[v].cnt = t[v].leaf + cnt(link(v));
    }
    return t[v].cnt;
}


int main() {
//    freopen("/home/jyree/src/input", "r", stdin);
//    freopen("/home/jyree/src/output.txt", "w", stdout);
    freopen("combos.in", "r", stdin);
    freopen("combos.out", "w", stdout);
    init(0);
    string s;
    cin >> n >> ks;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        add_string(s);
    }
    for(int i = 0; i <= ks; i++)
        for(int j = 0; j < k; j++)
            f[i][j] = -1;
    f[0][0] = 0;
    int v = 0;
    int m = 0;
    for(int i = 0; i < ks; i++)
        for(int v = 0; v < k; v++)
        {
            if(f[i][v] == -1)
                continue;
            for(int c = 0; c < 3; c++)
                f[i+1][go(v, c)] = max(f[i+1][go(v, c)], f[i][v] + cnt(go(v, c)));
        }
    for(int i = 0; i < k; i++)
        m = MAX(f[ks][i], m);
    cout << m << endl;
    return 0;
}

