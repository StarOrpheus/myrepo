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

vector<int> a;
int n, k;

bool f(long long l)
{
    int j = 1;
    int last = a[0];
    for(int i = 1; i < n; i++)
    {
        if(a[i] - last >= l)
        {
            j++;
            last = a[i];
        }
    }
    return j >= k;
}


int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("/home/jyree/src/lel.out", "w", stdout);
    cin >> n >> k;
    a.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    long long ans = 0;
    int r = *max_element(a.begin(), a.end()), l = 0;
    while(l <= r)
    {
        long long mid = (l + r) / 2;
        if(f(mid))
        {
            ans = max(ans, mid);
            l = mid + 1;
        } else
        {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}