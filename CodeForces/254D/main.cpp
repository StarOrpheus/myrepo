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

const int dx[] = {-1, 0, 1, 0};
const int dy[] = { 0, 1, 0,-1};

enum cond
{
    WALL    = -1,
    RAT     =  1,
    EMPTY   =  0
};

cond get_cond(char c)
{
    if(c == 'X')
        return WALL;
    if(c == '.')
        return EMPTY;
    if(c == 'R')
        return RAT;
}

int main()
{
    int n, m, d;
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> d;
    vector<vector<cond > > a(n+1, vector<cond >(m+1));
    int c;
    int rat_count = 0;
    string ts;
    for(int i = 1; i <= n; i++)
    {
        cin >> ts;
        for(int j = 0; j < m; j++)
        {
            a[i][j+1] = get_cond(ts[j]);
            if(a[i][j+1] == RAT)
                rat_count++;
        }
    }
    int i = 1, j = 1;
    bool fl = false;
    for(; i <= n && !fl; i++)
        for(j = 1; j <= m && !fl; j++)
            if(a[i][j] == RAT)
                fl = true;
    vector<vector<int > > f(n+1, vector<int>(m+1, -1));
    queue<coord> q;
    q.push(coord(i, j));
    int rats_on_heaven = 0;
    
    while(!q.empty() && rats_on_heaven < rat_count)
    {
        coord temp = q.front();
        q.pop();
        if(a[temp.x][temp.y] == RAT)
            rats_on_heaven++;
        for(int nap = 0; nap < 4; nap++)
        {
            #define NEWX (temp.x + dx[nap])
            #define NEWY (temp.y + dy[nap])
            if(NEWX > 0 && NEWX < n+1 && NEWY > 0 && NEWY < m+1 && f[NEWX][NEWY] == -1)
            {
                f[NEWX][NEWY] = f[temp.x][temp.y] + 1;
                q.push(coord(NEWX, NEWY ) );
            }
            #undef NEWX
            #undef NEWY
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}