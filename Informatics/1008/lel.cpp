#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define LEL

#define MIN(x, y)((x < y) ? (x) : (y))
#define ABS(x) ((x >= 0) ? (x) : -(x))

struct coord{
    long long x, y;
    coord(){}
    coord(int a, int b)
    {
        x = a, y = b;
    }
};

long long inline gcd(long long x, long long y)
{
    //cout << endl << "#gcd: x:" << x << " and y:" << y << endl;
    while(x > 0 && y > 0)
    {
        if(x > y)
            x = x % y;
        else
            y = y % x;
    }
    return (x + y);
}

int main()
{
    #ifndef LEL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    long long n;
    cin >> n;
    vector<coord> c(n);
    for(int i = 0; i < n; i++)
        cin >> c[i].x >> c[i].y;
    long long ymin = c[0].y;
    for(int i = 1; i < n; i++) ymin = MIN(ymin, c[i].y);
    for(int i = 0; i < n; i++)
        c[i].y -= ymin;

    long long s = 0;
    for(int i = 0; i < n-1; i++)
    {
        s += (c[i+1].x - c[i].x) * (c[i].y + c[i+1].y);
    }
    s += (c[0].x - c[n-1].x) * (c[0].y + c[n-1].y);
    s = ABS(s);
    long long k = 0;
    //cout << s << endl;
    for(int i = 0; i < n-1; i++)
    {
        k += gcd(ABS(c[i+1].x - c[i].x), ABS(c[i+1].y - c[i].y));
    //    cout << gcd(abs(c[i+1].x - c[i].x), abs(c[i+1].y - c[i].y)) << " ";
    }
    //cout << endl;
    //cout << k << endl;
    k+= gcd(ABS(c[0].x - c[n-1].x), ABS(c[0].y - c[n-1].y));
    cout << ((s - k + 2) / 2) << endl;
    return 0;
}
