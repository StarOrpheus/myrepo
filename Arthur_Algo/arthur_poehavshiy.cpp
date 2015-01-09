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

e new_e(int to, int w, int ne, int x0r) {
    e p;
    p.to = to;
    p.w = w;
    p.ne = ne;
    p.x0r = x0r;
    return p;
}

vector<vector<e> > g;
vector<vector<vector<e> > > cg;
vector<vector<pair<int,int> > > gy;
vector<int> clrs;
vector<vector<int> > lca;
vector<int> www;
vector<int> uuu;
vector<int> it,ot;
map<int, int> shkl;
int n,m,k,colors_c,dd1,dd2,de1,de2;
int ans;
int dtime = 0;

int get_color(int x) {
    if (shkl.count(x) == 0) {
        shkl[x] = colors_c++;
        return colors_c-1;
    }
    return shkl[x];
}

void init_dfs (int x, int y, int u, int w, int pr) {
    if (pr != -1) {
        lca[x].pb(pr);
        for (int i = 0; ; i++) {
            if (lca[pr].size() >= i) break;
            pr = lca[pr][i];
            lca[x].pb(pr);
        }
    }
    clrs[x] = y;
    uuu[x] = u;
    www[x] = w;
    //cout << "www[" << x << "] = " << w << endl;
    //cout << "uuu[" << x << "] = " << u << endl;
    it[x] = dtime++;
    for (int i = 0; i < g[x].size(); i++) {
        if (clrs[g[x][i].to] == -1) {
            init_dfs(g[x][i].to, y ^ g[x][i].x0r, u + g[x][i].ne, w + g[x][i].w, x);
        }
    }
    ot[x] = dtime++;
}

bool ispr(int x, int y) {
    return (it[x] <= it[y] && ot[x] >= ot[y]);
}

int flca (int x, int y) {
    if (it[x] > it[y]) swap(x,y);
    if (ispr(x,y)) return x;
    while (true) {
        dd1 = lca[x][0];
        if (ispr(dd1,y)) return dd1;
        for (int i = 1; i < lca[x].size(); i++) {
            if (ispr(lca[x][i], y)) break;
            dd1 = lca[x][i];
        }
        x = dd1;
    }
}

int good_dfs (int x, int pr, int clr) {
    int s = (clrs[cg[clr][x][0].x0r] == clr) ? 0 : ISDE;
    for (int i = 0; i < cg[clr][x].size(); i++) {
        if (cg[clr][x][i].to == pr) continue;
        dd1 = good_dfs(cg[clr][x][i].to, x, clr);
        if (dd1 != ISDE) {
            if (s != ISDE) ans = max(ans, s + dd1 + cg[clr][x][i].w);
            s = max(s, dd1 + cg[clr][x][i].w);
        }
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
    www.resize(n);
    uuu.resize(n);
    it.resize(n);
    ot.resize(n);
    lca.resize(n);
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
    gy.resize(n);
    for (int i = 0; i < n; i++) clrs[i] = -1;
    init_dfs(0, 0, 0, 0, -1);
    for (int i = 0; i < n; i++) {
        clrs[i] = get_color(clrs[i]);
        //cout << i << " " << clrs[i] << endl;
        gy[clrs[i]].pb(mp(it[i], i));
    }
    cg.resize(colors_c);
    for (int i = 0; i < colors_c; i++) {
        sort(gy[i].begin(), gy[i].end());
        for (int j = gy[i].size()-1; j > 0; j--) {
            dd1 = flca(gy[i][j].S, gy[i][j-1].S);
            gy[i].pb(mp(it[dd1], dd1));
        }
        sort(gy[i].begin(), gy[i].end());
//        cout << "FCOLOR " << i << endl;
//        for (int j = 0; j < gy[i].size(); j++) {
//            cout << gy[i][j].F << " " << gy[i][j].S << endl;
//        }
        stack<pair<int,int> > h;
        h.push(mp(gy[i][0].S,0));
        cg[i].resize(1);
        for (int j = 1; j < gy[i].size(); j++) {
            if (gy[i][j] == gy[i][j-1]) continue;
            de2 = gy[i][j].S;
            //cout << "lel" << endl;
            while (!h.empty() && !ispr(h.top().F, de2)) {
                dd1 = h.top().S;
                de1 = h.top().F;
                h.pop();
            }
            dd2 = cg[i].size();
            cg[i].resize(dd2+1);
            if (!h.empty()) {
                dd1 = h.top().S;
                de1 = h.top().F;
                //cout << dd1 << " " << de1 << " " << dd2 << " " << de2 << endl;
                cg[i][dd1].pb(new_e(dd2, www[de2] - www[de1], uuu[de2] - uuu[de1], de1));
                cg[i][dd2].pb(new_e(dd1, www[de2] - www[de1], uuu[de2] - uuu[de1], de2));
            } else {
                cg[i][dd1].pb(new_e(dd2, www[de1] - www[de2], uuu[de1] - uuu[de2], de1));
                cg[i][dd2].pb(new_e(dd1, www[de1] - www[de2], uuu[de1] - uuu[de2], de2));
            }
            h.push(mp(de2, dd2));
        }
    }
#ifdef LOCAL
    for (int i = 0; i < colors_c; i++) {
        cout << "COLOR: " << i << " " << cg[i].size() << endl;
        for (int j = 0; j < cg[i].size(); j++) {
            for (int l = 0; l < cg[i][j].size(); l++) cout << "From " << j << " to " << cg[i][j][l].to << " weight:" << cg[i][j][l].w << " ch:" << cg[i][j][l].ne << endl;
        }
    }
#endif // LOCAL
    for (int year = 0; year < k; year++) {
        ans = ISDE;
        for (int i = 0; i < colors_c; i++) {
            if (cg[i].size() == 1) continue;
            good_dfs(0, -1, i);
        }
        if (ans == ISDE) cout << "Sadness!\n"; else cout << ans << endl;
        for (int i = 0; i < colors_c; i++) {
            for (int j = 0; j < cg[i].size(); j++) {
                for (int l = 0; l < cg[i][j].size(); l++) {
                    cg[i][j][l].w += cg[i][j][l].ne;
                }
            }
        }
    }
    return 0;
}
