#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <limits>
#include <cmath>
#include <iomanip>
#include <queue>
using namespace std;

#define MIN(a, b) ((a < b) ? (a) : (b))
#define MAX(a, b) ((a > b) ? (a) : (b))

int fac(int c)
{
    if(c == 1)
        return 1;
    if(c == 0)
        return 1;
    return fac(c-1)*c;
}

int main(){
//    freopen("lel.out", "w", stdout);
    int k;
    int n;
    cin >> k;
    cin >> n;
    int c;
    int a[101];
    long long ans = 0;
    memset((int *) a, '\0', sizeof(int) * 101);
    for(int i = 0; i < n; i++)
    {
//        scanf("%ld", &c);
        cin >> c;
        if(c <= 100)
        {
            a[c]++;
        }
    }
    for(int ia = 0; ia <= 100; ia++)
    {
        for(int ib = ia; ib <= 100; ib++)
        {
            for(int ic = ib; ic <= 100; ic++)
            {
                if(ia + ib + ic >= k)
                    break;
                int id = k - ia - ib - ic;
                if(ia != ib != ic != id)
                {
                    ans += a[ia]*a[ib]*a[ic]*a[id];
                    continue;
                } else if(ia == ib && ia != ic && ia != id)
                {
                    ans += a[ia] * (a[ia] - 1) / 2 * a[ic] * a[id];
                    continue;
                } else if(ia == ib == ic && ic != id)
                {
                    ans += (a[ia]*(a[ia] - 1)*(a[ia] - 2)) / fac(3) * a[id];
                    continue;
                } else
                {
                    ans += (a[ia]*(a[ia] - 1) * (a[ia] - 2) * (a[ia] - 3)) / fac(4);
                    continue;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}