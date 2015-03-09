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
#include <cmath>
#include <bitset>
using namespace std;

#define INF (1<<30)
#define SWAP(x, y) x = x ^ y; y = x ^ y; x = x ^ y;
#define MAX(a, b) ((a > b) ? (a) : (b))
#define MIN(a, b) ((a < b) ? (a) : (b))
#define MOD 1000000007

int a[13][13];
int mn = INF, n;
bool used[15];

inline void dfs(int v, int s)
{
    used[v] = true;
    if(v == 1 && s != 0)
    {
        for(int i = 1; i <= n; i++)
            if(!used[i])
                return;
        mn = MIN(mn, s);
        return;
    }
    for(int i = 1; i <= n; i++)
        if((a[v][i] && !used[i]) || (i == 1 && a[v][i]))
        {
            dfs(i, s + a[v][i]);
        }
    used[v] = false;
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif // LOCAL
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    memset((void *) used, 0, sizeof(used));
    dfs(1, 0);
    cout << ((mn == INF && n != 1) ? -1 : (n == 1) ? 0 : mn) << endl;
    return 0;
}
