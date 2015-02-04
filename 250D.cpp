#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <iomanip>
#include <queue>
#include <locale>
#include <deque>

using namespace std;

#define INF (1<<30)

#define SQR(x)                  ((x)*(x))
#define RANGE(x1, y1, x2, y2)   (sqrt(SQR(x1-x2) + SQR(y1-y2)))
#define bestz                   z_b[b_iz]
#define bestv                   v_b[b_iv]
#define curz                    z_b[it]
#define curv                    v_b[i]
#define best_range              (bestz.rast + RANGE(bestz.x, bestz.y, bestv.x, bestv.y) + bestv.rast)
#define current_range           (curz.rast + RANGE(curz.x, curz.y, curv.x, curv.y) + curv.rast)
#define fci                     (l + ((r - l) / 3))
#define sci                     (r - ((r - l) / 3))
#define fc                      z_b[fci]
#define sc                      z_b[sci]
#define from                    v_b[i]
#define range_1                 (from.rast + RANGE(from.x, from.y, fc.x, fc.y) + fc.rast)
#define range_2                 (from.rast + RANGE(from.x, from.y, sc.x, sc.y) + sc.rast)
struct point
{
    int     ind;
    double  rast;
    int     x;
    int     y;
    point(){}
    point(int ind, int rast, int x, int y) : ind(ind), rast(rast), x(x), y(y) {}
};


int main()
{
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a, b;
    cin >> a >> b;
    vector<point> z_b(n);
    vector<point> v_b(m);
    for(int i = 0; i < n; i++)
    {
        int y;
        cin >> y;
        z_b[i].ind      = i+1;
        z_b[i].rast     = RANGE(0, 0, a, y);
        z_b[i].x        = a;
        z_b[i].y        = y;
    }
    for(int i = 0; i < m; i++)
    {
        int y;
        cin >> y;
        z_b[i].ind      = i+1;
        z_b[i].x        = b;
        z_b[i].y        = y;
    }
    for(int i = 0; i < m; i++)
    {
        int r;
        cin >> r;
        z_b[i].rast     = r;
    }
    int b_iz = 0, b_iv = 0;
    for(int i = 0; i < m; i++)
    {
        int l = 0, r = m-1;
        while(r - l >= 3)
        {
            if(range_1 - range_2 > 0.0000001)
            {
                l = fci + 1;
            } else
            {
                r = sci - 1;
            }
        }
        for(int it = max(0, l-1); it <= min(r+1, m-1); it++)
        {
            if(best_range - current_range > 0.00000001)
            {
                b_iz = i;
                b_iv = it;
            }
        }
    }
//    AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
    cout << (b_iz+1) << " " << (b_iv+1) << endl;
    return 0;
}