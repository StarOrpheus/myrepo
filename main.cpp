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

int inline hsh(int a, int b, int c, int d)
{
    int l[4];
    l[0] = a;
    l[1] = b;
    l[2] = c;
    l[3] = d;
    sort(l, l + 3);
    return a + 2*b + 4 * c + 8 * d;
}

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
    bool us[1510];
    memset((void *) us, '\0', sizeof(bool) * 1510);
    int k;
    int n;
    cin >> k;
    cin >> n;
    int c;
    long long a[101];
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
        for(int ib = 0; ib <= 100; ib++)
        {
            for(int ic = 0; ic <= 100; ic++)
            {
                if(ia + ib + ic >= k)
                    break;
                int id = k - ia - ib - ic;
                if(ia + ib + ic + id != k)
                    break;
                if(ia != ib && ia != ic && ia != id && ib != ic && ib != id && ic != id && !us[hsh(ia, ib, ic, id)])
                {
                    ans += a[ia]*a[ib]*a[ic]*a[id];
                    us[hsh(ia, ib, ic, id)] = 42;
//                    printf("%ld %ld %ld %ld\n", ia, ib, ic, id);
                    continue;
                } else if(ia == ib && ia != ic && ia != id && a[ia] >= 2 && !us[hsh(ia, ib, ic, id)])
                {
                    ans += a[ia] * (a[ia] - 1) / 2 * a[ic] * a[id];
                    us[hsh(ia, ib, ic, id)] = 42;
//                    printf("%ld %ld %ld\n", ia, ic, id);
                    continue;
                } else if(ia == ib && ib == ic && ic != id && a[ia] >= 3 && !us[hsh(ia, ib, ic, id)])
                {
                    ans += (a[ia]*(a[ia] - 1)*(a[ia] - 2)) / fac(3) * a[id];
                    us[hsh(ia, ib, ic, id)] = 42;
//                    printf("%ld %ld\n", ia, id);
                    continue;
                } else if(a[ia] >= 4 && !us[hsh(ia, ib, ic, id)])
                {
                    ans += a[ia]*(a[ia] - 1) * (a[ia] - 2) * (a[ia] - 3) / fac(4);
                    us[hsh(ia, ib, ic, id)] = 42;
//                    printf("%ld\n", ia);
                    continue;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}