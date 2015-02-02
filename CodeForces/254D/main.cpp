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

#define INF (1<<30)

struct coord
{
    int x;
    int y;
    coord(){}
    coord(int x, int y) : x(x), y(y) {}
};

enum cond
{
    WALL    = -1,
    RAT     =  1,
    EMPTY   =  0
};

cond get_cond(char c)
{
    switch(c)
    {
        case 'R': return RAT;
        case '.': return EMPTY;
        case 'X': return WALL;
        default : return EMPTY;
    }
}

int main()
{
    int n, m, d;
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> d;
    vector<vector<cond > > a(n+1, vector<cond >(m+1));
    int c;

    string ts;
    for(int i = 1; i <= n; i++)
    {
        cin >> ts;
        for(int j = 0; j < ts.length(); j++)
        {
            a[i][j+1] = get_cond(ts[j]);
        }
    }
    int i = 1, j = 1;
    bool f = false;
    for(; i <= n && !f; i++)
        for(; j <= m && !f; j++)
            if(a[i][j] == RAT)
                f = true;
    vector<vector<int > > f(n+1, vector<int>(m+1, -1));
    queue<coord> q;
    q.push(coord(i, j));
    
    return 0;
}