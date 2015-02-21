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

struct __attribute__((packed)) vertex
{
    int     next[26];
    int     p;
//    int     go[26];
    char    pch;
    bool    leaf;
//    int     cnt;
//    int     up;
    int     link;
//    int     bc = 0;
};

inline void init(int k);
inline void add_string(const string& s);
inline int link(int v);
inline int go(int v, char c);
inline int cnt(int v);

vertex t[1000500];
int k = 1;
//bool good[26];


inline void init(int k)
{
    t[k].leaf   = false;
    t[k].p      = -1;
//    t[k].cnt    = -1;
    t[k].link   = -1;
    for(int i = 0; i < 26; i++)
        t[k].next[i] = -1;
}
inline void add_string(const char *s, int sz)
{
    int v = 0;
    for(int i = 0; i < sz; i++)
    {
        char c = (int) s[i] - 'a';
        if(t[v].next[c] == -1)
        {
            init(k);
            t[k].p          = v;
            t[k].pch        = c;
//            t[k].bc         = t[v].bc + ((good[c]) ? 0 : 1);
            t[v].next[c]    = k;
//            if(t[k].bc <= bc)
//                ans++;
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
    if(t[v].next[c] == -1)
    {
        if(v == 0)
            t[v].next[c] = 0;
        else
            t[v].next[c] = go(link(v), c);
    }
    return t[v].next[c];
}


int main() {
//    freopen("/home/jyree/src/input", "r", stdin);
//    freopen("/home/jyree/src/output.txt", "w", stdout);
//    freopen("censor.in", "r", stdin);
//    freopen("censor.out", "w", stdout);
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
//    string s1, s2;
    init(0);
//    cin >> s1;
//    cin >> s2;
    char s1[1000500], s2[1000500];
    gets(s1); gets(s2);
    int s1l = strlen(s1), s2l = strlen(s2);
    add_string(s2, s2l);
    bool    used[1000100];
    int     f[1000100];
    memset((void *) used, 0, s1l * sizeof(bool));
    int v = 0;
    for(int i = 0; i < s1l; i++)
    {
        v = go(v, s1[i] - 'a');
        f[i] = v;
        if(t[v].leaf)
        {
            int k = s2l;
            int j = i;
            while(k)
            {
                if(!used[j])
                {
                    k--;
                    used[j] = true;
                }
                j--;
            }
            v = f[j];
        }
    }
    for(int i = 0; i < s1l; i++)
        if(!used[i])
            putchar(s1[i]);
    putchar('\n');
    return 0;
}
