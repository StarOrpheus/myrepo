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
#define fci                     (l + ((r - l) / 3))
#define sci                     (r - ((r - l) / 3))
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
//    vector<point> z_b(n);
//    vector<point> v_b(m);
    point *z_b = (point *) malloc(sizeof(point) * n);
    point *v_b = (point *) malloc(sizeof(point) * m);
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
        v_b[i].ind      = i+1;
        v_b[i].x        = b;
        v_b[i].y        = y;
    }
    for(int i = 0; i < m; i++)
    {
        int r;
        cin >> r;
        v_b[i].rast     = r;
    }
    int b_iz = 0, b_iv = 0;
    for(int i = 0; i < m; i++)
    {
        int l = 0, r = n-1;
        while(r - l > 3)
        {
            int ms1 = l + (r - l) / 3, ms2 = r - (r - l) / 3;
            if(z_b[ms1].rast + v_b[i].rast + RANGE(z_b[ms1].x, z_b[ms1].y, v_b[i].x, v_b[i].y) >/*!!!!*/ z_b[ms2].rast + v_b[i].rast + RANGE(z_b[ms2].x, z_b[ms2].y, v_b[i].x, v_b[i].y))
            {
                l = ms1;
            } else
            {
                r = ms2;
            }
//            cout << l << " "  << r << endl;
        }
        for(int it = max(0, l-1); it <= min(r+1, n-1); it++)
        {
            if(z_b[b_iz].rast + RANGE(z_b[b_iz].x, z_b[b_iz].y, v_b[b_iv].x, v_b[b_iv].y) + v_b[b_iv].rast > z_b[it].rast + RANGE(z_b[it].x, z_b[it].y, v_b[i].x, v_b[i].y) + v_b[i].rast)
            {
                b_iz = it;
                b_iv = i;
            }
        }
    }
    free(z_b);
    free(v_b);
    cout << (b_iz+1) << " " << (b_iv+1) << endl;
    return 0;
}