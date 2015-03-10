#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <limits>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <string>
#include <cstring>
 
 
using namespace std;
 
#define INF (1 << 30)
#define MIN(a, b) ((a < b) ? (a) : (b))
 
 
inline vector<pair<long long, long long > > factorize(long long a)
{
    vector<pair<long long, long long> > t;
    long long d = 2ll;
    while(d*d <= a)
    {
        if(a % d == 0ll)
        {
            long long z = 0ll;
            while(a % d == 0ll)
            {
                z++; a /= d;
            }
            t.push_back(make_pair(d, z));
        }
        (d == 2ll) ? d = 3ll : d += 2ll;
    }
    if(a != 1)
    {
        t.push_back(make_pair(a, 1ll));
    }
    return t;
}
 
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long n, k;
    cin >> n >> k;
    vector<pair<long long, long long> > st  = factorize(k);
    //for(int i = 0; i < st.size(); i++)
    //    printf("%d^%d\n", st[i].first, st[i].second);
    long long ans = 0;
    long long a = n;
    long long mn = numeric_limits<long long>::max();
    for(int i = 0; i < st.size(); i++)
    {
        //printf("%d ", st[i].first);
        long long k = 0, t = a, d = st[i].first;
        while(a / d * 1ll > 0ll)
        {
            k += a / d;
            d *= st[i].first;
        }
        //printf("%d/%d\n", k, st[i].second);
        mn = MIN(mn, 1ll * k / st[i].second);
    }
    ans = mn;
    cout << ans << endl;
    return 0;
}