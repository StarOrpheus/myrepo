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
    int     next[26];
    int     p;
    int     go[26];
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
int k = 1, ans = 0, bc;
bool good[26];


inline void init(int k)
{
    t[k].leaf   = false;
    t[k].p      = -1;
    t[k].cnt    = -1;
    t[k].link   = -1;
    for(int i = 0; i < 26; i++)
        t[k].next[i] = -1, t[k].go[i] = -1;
}
inline void add_string(const string &s)
{
    int v = 0;
    for(int i = 0; i < s.length(); i++)
    {
        char c = (int) s[i] - 'a';
        if(t[v].next[c] == -1)
        {
            init(k);
            t[k].p          = v;
            t[k].pch        = c;
            t[k].bc         = t[v].bc + ((good[c]) ? 0 : 1);
            t[v].next[c]    = k;
            if(t[k].bc <= bc)
                ans++;
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
        if(t[v].cnt == 0)
            t[v].cnt = 0;
        else
            t[v].cnt = ((t[v].leaf) ? 1 : 0) + cnt(link(v));
    }
    return 0;
}


int main() {
//    freopen("/home/jyree/src/input", "r", stdin);
//    freopen("/home/jyree/src/output.txt", "w", stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    string s1, s2;
    init(0);
    cin >> s1;
    cin >> s2;
    cin >> bc;
    for(int i = 0; i < 26; i++)
        good[i] = (s2[i] - '0');
    for(int i = 0; i < s1.length(); i++)
        add_string(s1.substr(i));
    cout << ans << endl;
    return 0;
}

