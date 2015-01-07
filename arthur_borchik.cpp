#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>

#define mp make_pair
#define pb push_back
#define S second
#define F first

using namespace std;

struct lel{
    lel* g[30];
    int c;
};

lel* cr(lel* pr, char c) {
    if ((*pr).g[c - 'a'] != 0)
        return (*pr).g[c - 'a'];
    lel* q = new lel();
    for (int i = 0; i < 30; i++) (*q).g[i] = 0;
    (*pr).g[c - 'a'] = q;
    (*q).c = 0;
    return q;
}

lel root;

int main(){
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < 30; i++) root.g[i] = 0;
    int n,m;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        lel* now = &root;
        int m = (int) s.length();
        vector<int> z (m);
        for (int i=1, l=0, r=0; i<m; ++i) {
            if (i <= r)
                z[i] = min (r-i+1, z[i-l]);
            while (i+z[i] < m && s[z[i]] == s[i+z[i]])
                ++z[i];
            if (i+z[i]-1 > r)
                l = i,  r = i+z[i]-1;
        }
        for (int i = m-1; i >= 0; i--) {
            now = cr(now, s[m-1-i]);
            if (z[i] == m-i || i == 0) {
                (*now).c++;
            }
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> s;
        lel* now = &root;
        for (int i = 0; i < s.size(); i++) now = cr(now, s[i]);
        cout << (*now).c << endl;
    }
    return 0;
}
