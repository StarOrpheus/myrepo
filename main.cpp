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

long long inline hsh(long long a, long long b, long long c, long long d)
{
    long long l[4];
    l[0] = a;
    l[1] = b;
    l[2] = c;
    l[3] = d;
    sort(l, l + 3);
    long long ans = 0;
    for(int i = 0; i < 4; i++)
        ans += (1 << i) * l[i];
    return ans;
}

long long fac(long long c)
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
    for(int i = 0; i < 101; i++) a[i] = 0;
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
                    continue;
                int l[4];
                l[0] = ia;
                l[1] = ib;
                l[2] = ic;
                l[3] = id;
                sort(l, l + 3);
                if(a[l[0]] >= 1 && a[l[1]] >= 1 && a[l[2]] >= 1 && a[l[3]] >= 1 && l[0] != l[1] && l[0] != l[2] && l[0] != l[3]
                        && l[1] != l[2] && l[1] != l[3] && l[2] != l[3] && !us[hsh(l[0], l[1], l[2], l[3])])
                {
                    ans += a[l[0]]*a[l[1]]*a[l[2]]*a[l[3]];
                    us[hsh(l[0], l[1], l[2], l[3])] = 42;
//                    printf("%ld %ld %ld %ld #1\n", a[l[0]], a[l[1]], a[l[2]], a[l[3]]);
//                    continue;
                }
                if(l[0] == l[1] && l[0] != l[2] && l[0] != l[3] && a[l[0]] >= 2 && !us[hsh(l[0], l[1], l[2], l[3])] && a[l[2]] >= 1 && a[l[3]] >= 1)
                {
                    ans += a[l[0]] * (a[l[0]] - 1) / 2 * a[l[2]] * a[l[3]];
                    us[hsh(l[0], l[1], l[2], l[3])] = 42;
//                    printf("%ld %ld %ld %ld #2\n", a[l[0]], a[l[1]], a[l[2]], a[l[3]]);
//                    continue;
                }
                if(l[0] == l[1] && l[1] == l[2] && l[2] != l[3] && a[l[0]] >= 3 && !us[hsh(l[0], l[1], l[2], l[3])] && a[l[3]] >= 1)
                {
                    ans += (a[l[0]]*(a[l[0]] - 1)*(a[l[0]] - 2)) / fac(3) * a[l[3]];
                    us[hsh(l[0], l[1], l[2], l[3])] = 42;
//                    printf("%ld %ld %ld %ld #3\n", a[l[0]], a[l[1]], a[l[2]], a[l[3]]);
//                    continue;
                }
                if(l[0] == l[1] && l[1] == l[2] && l[2] == l[3] && a[l[0]] >= 4 && !us[hsh(l[0], l[1], l[2], l[3])])
                {
                    ans += a[l[0]]*(a[l[0]] - 1) * (a[l[0]] - 2) * (a[l[0]] - 3) / fac(4);
                    us[hsh(l[0], l[1], l[2], l[3])] = 42;
//                    printf("%ld %ld %ld %ld #4\n", a[l[0]], a[l[1]], a[l[2]], a[l[3]]);
//                    continue;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}