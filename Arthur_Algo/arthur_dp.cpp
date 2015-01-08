#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

#define pb push_back
#define F first
#define S second
#define mp make_pair
#define INF 1000000000

using namespace std;

int p1[500500], p2[500500], p3[500500], on[500500];
bool used[500500];
int dp[7][7][7][90];
int sd[7][7][7][90];
int ty[7][7][7][90];

int main() {
    ios_base::sync_with_stdio(0);
    #ifdef LOCAL
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #else
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector<pair<int,int> > a,b,c;
    int d1,d2,d3;
    for (int i = 0; i < n; i++) {
        cin >> p1[i] >> p2[i] >> p3[i];
        a.pb(mp(p1[i], i));
        b.pb(mp(p2[i], i));
        c.pb(mp(p3[i], i));
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());
    vector<pair<int,pair<int,int> > > d;
    for (int i = 0; i < 10; i++) {
        if (!used[a[i].S]) {used[a[i].S] = true; on[d.size()] = a[i].S+1; d.pb(mp(p1[a[i].S], mp(p2[a[i].S], p3[a[i].S])));}
        if (!used[b[i].S]) {used[b[i].S] = true; on[d.size()] = b[i].S+1; d.pb(mp(p1[b[i].S], mp(p2[b[i].S], p3[b[i].S])));}
        if (!used[c[i].S]) {used[c[i].S] = true; on[d.size()] = c[i].S+1; d.pb(mp(p1[c[i].S], mp(p2[c[i].S], p3[c[i].S])));}
    }
    n = d.size();
    for (int i = 0; i < n; i++) {
        p1[i] = d[i].F;
        p2[i] = d[i].S.F;
        p3[i] = d[i].S.S;
        //cout << p1[i] << " " << p2[i] << " " << p3[i] << endl;
    }
    //cout << "\n";
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            for (int i1 = 0; i1 < 6; i1++) {
                for (int j1 = 0; j1 < n; j1++) {
                    dp[i][j][i1][j1] = -1000000000;
                }
            }
        }
    }
    dp[1][0][0][0] = p1[0];
    sd[1][0][0][0] = 1;
    dp[0][1][0][0] = p2[0];
    sd[0][1][0][0] = 2;
    dp[0][0][1][0] = p3[0];
    sd[0][0][1][0] = 3;
    dp[0][0][0][0] = 0;
    for (int i = 1; i < n; i++) {
        for (int i1 = 0; i1 < 6; i1++) {
            for (int i2 = 0; i2 < 4; i2++) {
                for (int i3 = 0; i3 < 3; i3++) {
                    if (i1 + i2 + i3 > i + 1) continue;
                    if (i1+i2+i3 == 0) {
                        continue;
                    }
                    for (int j = 0; j < i; j++) {
                        if (i1 > 0 && dp[i1-1][i2][i3][j] + p1[i] > dp[i1][i2][i3][i]) {
                            dp[i1][i2][i3][i] = dp[i1-1][i2][i3][j] + p1[i];
                            sd[i1][i2][i3][i] = 1;
                            ty[i1][i2][i3][i] = j;
                        }
                        if (i2 > 0 && dp[i1][i2-1][i3][j] + p2[i] > dp[i1][i2][i3][i]) {
                            dp[i1][i2][i3][i] = dp[i1][i2-1][i3][j] + p2[i];
                            sd[i1][i2][i3][i] = 2;
                            ty[i1][i2][i3][i] = j;
                        }
                        if (i3 > 0 && dp[i1][i2][i3-1][j] + p3[i] > dp[i1][i2][i3][i]) {
                            dp[i1][i2][i3][i] = dp[i1][i2][i3-1][j] + p3[i];
                            sd[i1][i2][i3][i] = 3;
                            ty[i1][i2][i3][i] = j;
                        }
                    }
                }
            }
        }
    }
    vector<int> ans1,ans2,ans3;
    int i1 = 5;
    int i2 = 3;
    int i3 = 2;
    int i = n-1;
    for (int j = 0; j < n-1; j++) {
        if (dp[5][3][2][j] > dp[5][3][2][i]) i = j;
    }
    while (i1 + i2 + i3 > 0) {
        //cout << i1 << " " << i2 << " "  << i3 << " " << i << endl;
        int dd = sd[i1][i2][i3][i];
        if (dd == 1) {
            ans1.pb(on[i]);
            i = ty[i1][i2][i3][i];
            i1--;
        } else
        if (dd == 2) {
            ans2.pb(on[i]);
            i = ty[i1][i2][i3][i];
            i2--;
        } else
        if (dd == 3) {
            ans3.pb(on[i]);
            i = ty[i1][i2][i3][i];
            i3--;
        }

    }
    if (ans1.size() != 5 || ans2.size() != 3 || ans3.size() != 2) {
        return -1;
    }
    for (int i = 0; i < 5; i++) cout << ans1[i] << " "; cout << endl;
    for (int i = 0; i < 3; i++) cout << ans2[i] << " "; cout << endl;
    for (int i = 0; i < 2; i++) cout << ans3[i] << " "; cout << endl;
}
