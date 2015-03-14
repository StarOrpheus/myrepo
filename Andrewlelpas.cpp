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
#include <exception>
#include <cmath>
#include <bitset>
#include <limits>
#include <unordered_map>

using namespace std;

const int maxl          = numeric_limits<int>::max();
const long long maxll   = numeric_limits<long long>::max();
#define SWAP(x, y) x = x ^ y; y = x ^ y; x = x ^ y;
#define MAX(a, b) ((a > b) ? (a) : (b))
#define MIN(a, b) ((a < b) ? (a) : (b))
#define MOD 1000000007

// Не забыть закрыть окно!!!
//#define LEL

long long a, k, b, m, x;
long long ans = 0;
int curd = 1;


int main()
{
#ifdef LEL
    freopen("/home/jyree/src/TEST/input.txt", "r", stdin);
#endif
//    scanf("%lld %lld %lld %lld %lld", &a, &k, &b, &m, &x);
    cin >> a >> k >> b >> m >> x;
    long double l = 1, r = 1000000000000000000;
    long double ans = r;
    while(l <= r)
    {
        long double mid         = ((long long)(l + r)) / 2;
        long double midtreec    = (mid * (a + b) - (((long long) mid / k) * a) - (((long long) mid / m) * b));
        if(midtreec >= x)
        {
            ans = MIN(ans, mid);
            r = mid - 1;
        }
        if(midtreec < x)
            l = mid + 1;
    }
    /*int xx = MIN(l, r);
    int yy = MAX(l, r);
    if(xx * (a + b) - (xx / k * a) - (xx / m * b) >= x)
        ans = xx;
    else
        ans = yy;*/
//    printf("%lld\n", ans);
    cout << (long long) ans << endl;
    return 0;
}
