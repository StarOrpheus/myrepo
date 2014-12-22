#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#define MIN(a, b) ((a < b) ? (a) : (b))
#define MAX(a, b) ((a > b) ? (a) : (b))

using namespace std;

struct __attribute__((packed)) r{
    int s; //start
    int f; //finish
    r(){}
    r(int x, int y)
    {
        s = x; f = y;
    }
};

vector<int> gsu;
int n, m;
vector<int> pred;

int get(int v)
{
    if(pred[v] == v)
    {
        return v;
    }
    pred[v] = get(pred[v]);
    return pred[v];
}

void change(int a, int b)
{
    int v = get(a), u = get(b);
    pred[v] = u;
    return;
}

int main()
{
    int k;
    cin >> n >> m >> k;
    pred.resize(n+1);
    for(int i = 1; i <= n; i++)
        pred[i] = i;
    int x, y;
    int ans = 0;
    vector<r> g;
    for(int i = 1; i <= m; i++)
    {
        //scanf("%ld %ld", &x, &y);
        cin >> x >> y;
        if (x <= k || y <= k)
        {
            g.push_back(r(x,y));
        }
        else
        {
            change(x, y);
        }
    }
    for(int i = 0; i < g.size(); i++)
    {
        if(get(g[i].s) == get(g[i].f))
        {
            //cout << g[i].s << " " << g[i].f << endl;
            ans++;
            continue;
        }
        change(g[i].s, g[i].f);
    }
    cout << ans << endl;
    return 0;
}