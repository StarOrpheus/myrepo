#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <cstring>
#include <ctime>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define T third

using namespace std;

const long long INFll = 1000000000000000001ll;
const long double INFld = (long double) 1000000000000000001;
const int ISDE = -1000000000;

struct e{
    int to; //направление
    int w; //вес
    int ne; //прирост
    int x0r; //xor
};

struct trio{
    int first;
    int second;
    int third;
};

e new_e(int to, int w, int ne, int x0r) {
    e p;
    p.to = to;
    p.w = w;
    p.ne = ne;
    p.x0r = x0r;
    return p;
}

trio mt(int ff, int ss, int tt) {
    trio p;
    p.first = ff;
    p.second = ss;
    p.third = tt;
    return p;
}

vector<vector<e> > g;
vector<vector<vector<trio> > > cg;
vector<stack<trio> > cd;
vector<int> clrs;
vector<int> used;
vector<int> root;
vector<int> www;
vector<int> uuu;
vector<int> pred;
//vector<int> www;
map<int, int> shkl;
int n,m,k,colors_c,dd1;
int ans;

int get_color(int x) {
    if (shkl.count(x) == 0) {
        shkl[x] = colors_c++;
        return colors_c-1;
    }
    return shkl[x];
}

void init_dfs (int x, int y) {
    clrs[x] = y;
    //cout << x << " " << y << " " << z << endl;
    for (int i = 0; i < g[x].size(); i++) {
        if (clrs[g[x][i].to] == -1) {
            init_dfs(g[x][i].to, y ^ g[x][i].x0r);
            pred[g[x][i].to] = x;
        }
    }
}

void ddfs (int x) {
    used[x] = 1;
    if (root[clrs[x]] == -1) {
        root[clrs[x]] = x;
    } else {
        while (used[root[clrs[x]]] == 2) {
            root[clrs[x]] = pred[root[clrs[x]]];
        }
    }
    for (int i = 0; i < g[x].size(); i++) {
        if (used[g[x][i].to] == 0) {
            ddfs(g[x][i].to);
        }
    }
    used[x] = 2;
}

void build_dfs (int x, int pr, int z, int u) {
    //cout << "www[" << x << "] = " << z << endl;
    //cout << x << ".color = " << clrs[x] << endl;
    //cout << "dfs(" << x << "," << pr << "," << z << "," << u << ")" << endl;
    www[x] = z;
    uuu[x] = u;
    dd1 = cg[clrs[x]].size();
    if (cd[clrs[x]].empty()) {
        cd[clrs[x]].push(mt(0, www[root[clrs[x]]], uuu[root[clrs[x]]]));
    }
    {
        //cout << "!EMPTY " << x << endl;
        cg[clrs[x]].resize(dd1+1);
        cg[clrs[x]][cd[clrs[x]].top().F].pb(mt(dd1, z-cd[clrs[x]].top().S, u-cd[clrs[x]].top().T));
        cg[clrs[x]][dd1].pb(mt(cd[clrs[x]].top().F, z-cd[clrs[x]].top().S, u-cd[clrs[x]].top().T));
        //cout << "make edge " << dd1 << " " << cd[clrs[x]].top().F << endl;
        cd[clrs[x]].push(mt(dd1,z,u));
    }
    for (int i = 0; i < g[x].size(); i++) {
        if (g[x][i].to == pr) continue;
        //cout << "for " << x << " " << g[x][i].to << " " << g[x][i].w << " " << g[x][i].ne << " " << g[x][i].x0r << endl;
        build_dfs(g[x][i].to, x, z + g[x][i].w, u + g[x][i].ne);
    }
    cd[clrs[x]].pop();
}

int good_dfs (int x, int pr, int clr) {
    //cout << "g " << x << " " << pr << " " << clr << endl;
    int s;
    if (x == 0) s = ISDE; else s = 0;
    int ds;
    for (int i = 0; i < cg[clr][x].size(); i++) {
        if (cg[clr][x][i].F == pr) continue;
        ds = good_dfs(cg[clr][x][i].F, x, clr) + cg[clr][x][i].S;
        cout << "go " << cg[clr][x][i].F << " " << ds << endl;
        ans = max(ans, s + ds);
        s = max(s, ds);
    }
    return s;
}

int main(){
    ios_base::sync_with_stdio(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> m >> k;
    g.resize(n);
    pred.resize(n);
    root.resize(n);
    www.resize(n);
    uuu.resize(n);
    used.resize(n);
    int d1,d2,d3,d4,d5,d6,d7,d8,d9;
    for (int i = 0; i < n-1; i++) {
        cin >> d1 >> d2 >> d3 >> d4 >> d5 >> d6 >> d7;
        d1--;
        d2--;
        d8 = 0;
        for (int j = 0; j < d7; j++) {
            cin >> d9;
            d9--;
            d8 ^= (1<<d9);
        }
        g[d1].pb(new_e(d2,d3-d4,d5-d6,d8));
        g[d2].pb(new_e(d1,d3-d4,d5-d6,d8));
    }
    clrs.resize(n);
    for (int i = 0; i < n; i++) clrs[i] = -1;
    init_dfs(0, 0);
    for (int i = 0; i < n; i++) {
        clrs[i] = get_color(clrs[i]);
        //cout << i << " " << clrs[i] << endl;
    }
    for (int i = 0; i < colors_c; i++) {
        root[i] = -1;
    }
    ddfs(0);
    cg.resize(0);
    cg.resize(colors_c);
    cd.resize(0);
    cd.resize(colors_c);
    for (int i = 0; i < colors_c; i++) {
        cg[i].resize(1);
    }
    build_dfs(0, -1, 0, 0);

#ifdef LOCAL
    for (int i = 0; i < colors_c; i++) {
        cout << "COLOR: " << i << " " << cg[i].size() << endl;
        for (int j = 0; j < cg[i].size(); j++) {
            for (int l = 0; l < cg[i][j].size(); l++) cout << "From " << j << " to " << cg[i][j][l].F << " weight: " << cg[i][j][l].S << " ch: " << cg[i][j][l].T << endl;
        }
    }
#endif // LOCAL

    for (int year = 0; year < k; year++) {
        ans = ISDE;
        for (int i = 0; i < colors_c; i++) {
            if (cg[i].size() == 2) continue;
            good_dfs(0, -1, i);
            cout << ans << " " << i << endl;
            //if (i == 1) break;

        }
        if (ans == ISDE) cout << "Sadness!\n"; else cout << ans << endl;

        for (int i = 0; i < colors_c; i++) {
            //cout << "COLOR: " << i << " " << cg[i].size() << endl;
            for (int j = 0; j < cg[i].size(); j++) {
                for (int l = 0; l < cg[i][j].size(); l++) {
                    //cout << j  << " " << cg[i][j][l].F << " " << cg[i][j][l].S << endl;
                    cg[i][j][l].S += cg[i][j][l].T;
                }
            }
        }
    }
    return 0;
}
