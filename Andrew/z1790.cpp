#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;
vector<int> w;
struct l{
    int x,y,k;
};
int b[1100], a[1100];
int f[1100][1100];
int main() {
    ios_base::sync_with_stdio(0);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    int n ,m;
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];

    cin >> m ;

    for (int i=1; i<=m; i++)
        cin >> b[i];

    for (int i=1; i<=n; i++ ){
        for (int j=1; j<=m; j++ ){
            if (a[i] == b[j]){
                f[i][j] = f[i-1][j-1]+1;
            }

            else f[i][j]  = max(f[i-1][j], f[i][j-1]);
        }
    }
    f[0][0] = 0;
    l d;
    d.k = f[n][m];
    d.x = n;
    d.y = m;
    for(;f[d.x][d.y] != 0; d.x--, d.y--)
    {
        for(; d.y > 1 && f[d.x][d.y] == f[d.x][d.y-1]; d.y--);
        for(; d.x > 1 && f[d.x][d.y] == f[d.x-1][d.y]; d.x--);
        w.push_back(a[d.x]);
    }
    for(int i = w.size()-1; i >= 0; i--)
        cout << w[i] << ' ';

    return 0;
}
