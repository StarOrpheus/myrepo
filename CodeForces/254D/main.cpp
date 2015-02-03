#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
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
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
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
    for(i = 1; i <= n && !fl; i++)
        for(j = 1; j <= m && !fl; j++)
            if(a[i][j] == RAT)
                fl = true;
    //cout << i << " " << j << endl;
    i--; j--;
    vector<vector<int > > f(n+1, vector<int>(m+1, -1));
    queue<coord> q;
    f[i][j] = 0;
    q.push(coord(i, j));
    int rats_on_heaven = 0;

    while(!q.empty() && rats_on_heaven <= rat_count)
    {
        coord temp = q.front();
        q.pop();
        if(a[temp.x][temp.y] == RAT)
            rats_on_heaven++;
        for(int nap = 0; nap < 4; nap++)
        {
            #define NEW_X (temp.x + dx[nap])
            #define NEW_Y (temp.y + dy[nap])
            if(NEW_X > 0 && NEW_X < n+1 && NEW_Y > 0 && NEW_Y < m+1 && f[NEW_X][NEW_Y] == -1 && a[NEW_X][NEW_Y] != WALL)
            {
                if(f[temp.x][temp.y] == d)
                    break;
                f[NEW_X][NEW_Y] = f[temp.x][temp.y] + 1;
                q.push(coord(NEW_X, NEW_Y ) );
            }
            #undef NEW_X
            #undef NEW_Y
        }
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if(f[i][j] != -1)
            {
                vector<vector<int > > f(n+1, vector<int>(m+1, -1));
                queue<coord> q;
                f[i][j] = 0;
                q.push(coord(i, j));
                int rats_on_heaven = 0;

                while(!q.empty() && rats_on_heaven <= rat_count)
                {
                    coord temp = q.front();
                    q.pop();
                    if(a[temp.x][temp.y] == RAT)
                        rats_on_heaven++;
                    for(int nap = 0; nap < 4; nap++)
                    {
#define NEW_X (temp.x + dx[nap])
#define NEW_Y (temp.y + dy[nap])
                        if(NEW_X > 0 && NEW_X < n+1 && NEW_Y > 0 && NEW_Y < m+1 && f[NEW_X][NEW_Y] == -1 && a[NEW_X][NEW_Y] != WALL)
                        {
                            if(f[temp.x][temp.y] == d)
                                break;
                            f[NEW_X][NEW_Y] = f[temp.x][temp.y] + 1;
                            q.push(coord(NEW_X, NEW_Y ) );
                        }
#undef NEW_X
#undef NEW_Y
                    }
                }

            }
        }



    return 0;
}