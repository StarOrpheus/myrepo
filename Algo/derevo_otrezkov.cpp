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
const int MOD = 1000000007;

struct e{
    int kk,kt;
    long long tn,tp,tt;
};

int n,m,k0;
char t1[400100]; //чем заполнили
int kt[400100]; //количество подвластных чисел
int kk[400100]; //количество не нулей
long long s10[400100]; //степень 10
long long s1[400100]; //1 в ряд
long long s2[400100]; //1 + 11 + 111 + 1111
long long s3[400100]; //s2[1] + s2[2] + s2[3] + s2[4]
long long tn[400100]; //сумма справа налево без нулей
long long tt[400100]; //само число
long long tp[400100]; //сумма слева направо
long long ans[400100]; //ответ
long long fid;

void update (int x, int tl, int tr, int fl, int fr, int u) {
    if (fl > fr) return;
    if (tl == fl && tr == fr) {
        t1[x] = u;
        if (u == 0) {
            ans[x] = 0;
            tp[x] = 0;
            tn[x] = 0;
            kk[x] = 0;
            tt[x] = 0;
        } else {
            ans[x] = (s3[kt[x]] * u) % MOD;
            tp[x] = (s2[kt[x]] * u) % MOD;
            tn[x] = tp[x];
            kk[x] = kt[x];
            tt[x] = (s1[kt[x]-1] * u) % MOD;
        }
    } else {
        int d = (tl + tr) >> 1;
        if (t1[x] != 10) {
            update(x<<1, tl, d, tl, d, t1[x]);
            update((x<<1)|1, d+1, tr, d+1, tr, t1[x]);
            t1[x] = 10;
        }
        update(x<<1, tl, d, fl, min(fr, d), u);
        update((x<<1)|1, d+1, tr, max(fl, d+1), fr, u);
        ans[x] = (ans[x<<1] + ans[(x<<1)|1] + tn[x<<1] * (s1[kt[(x<<1)|1]]-1) + tp[(x<<1)|1] * kk[x<<1]) % MOD;
        kk[x] = kk[x<<1] + kk[(x<<1)|1];
        tp[x] = (tp[x<<1] + tt[x<<1] * (s1[kt[(x<<1)|1]]-1) + tp[(x<<1)|1]) % MOD;
        tn[x] = (tn[x<<1] * s10[kt[(x<<1)|1]] + tn[(x<<1)|1] + kk[x<<1] * tt[(x<<1)|1]) % MOD;
        tt[x] = (tt[x<<1] * s10[kt[(x<<1)|1]] + tt[(x<<1)|1]) % MOD;
    }
}

e fa (int x, int tl, int tr, int fl, int fr) {
    //cout << "fa " << x << " " << fl << " " << fr << endl;
    if (fl > fr) {
        e t;
        t.kk = -1;
        return t;
    }
    if (tl == fl && tr == fr) {
        fid = (ans[x] + fid) % MOD;
        e t;
        t.kk = kk[x];
        t.kt = kt[x];
        t.tn = tn[x];
        t.tp = tp[x];
        t.tt = tt[x];
        return t;
    }
    if (t1[x] != 10) {
        e t;
        t.kt = fr - fl + 1;
        if (t1[x] == 0) {
            t.kk = 0;
            t.tp = 0;
            t.tn = 0;
            t.tt = 0;
        } else {
            fid = (fid + (s3[t.kt] * t1[x])) % MOD;
            t.kk = t.kt;
            t.tp = (s2[t.kt] * t1[x]) % MOD;
            t.tn = t.tp;
            t.tt = (s1[t.kt-1] * t1[x]) % MOD;
        }
        return t;
    }
    int d = (tl + tr) >> 1;
    e t1 = fa(x<<1, tl, d, fl, min(fr, d));
    e t2 = fa((x<<1)|1, d+1, tr, max(fl, d + 1), fr);
    if (t1.kk == -1) {
        return t2;
    }
    if (t2.kk == -1) {
        return t1;
    }
    e t;
    fid = (fid + t1.tn * (s1[t2.kt]-1) + t2.tp * t1.kk) % MOD;
    t.kk = t1.kk + t2.kk;
    t.kt = t1.kt + t2.kt;
    t.tp = (t1.tp + t1.tt * (s1[t2.kt]-1) + t2.tp) % MOD;
    t.tn = (t1.tn * s10[t2.kt] + t2.tn + t2.tt * t1.kk) % MOD;
    t.tt = (t1.tt * s10[t2.kt] + t2.tt) % MOD;
    return t;
}

int main(){
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int kr;
    int d1,d2,d3,d4;
    cin >> n >> kr;
    m = 1;
    while (m < n) m <<= 1;
    k0 = m-n;
    for (int i = 0; i < (m<<1); i++) t1[i] = 10;
    for (int i = m + k0; i < (m<<1); i++) {
        cin >> d1;
        ans[i] = d1;
        tp[i] = d1;
        tn[i] = d1;
        kk[i] = d1!=0;
        tt[i] = d1;
    }
    s1[0] = 1;
    s1[1] = 11;
    s10[1] = 10;
    s2[1] = 1;
    s3[1] = 1;
    for (int i = 2; i <= m; i++) {
        s1[i] = (s1[i-1] * 10 + 1) % MOD;
        s10[i] = (s10[i-1] * 10) % MOD;
        s2[i] = (s2[i-1] + s1[i-1]) % MOD;
        s3[i] = (s3[i-1] + s2[i]) % MOD;
    }
    kt[1] = m;
    int u = m;
    for (int i = m; i < (m<<1); i++) {
        kt[i] = 1;
    }
    for (int x = m-1; x > 0; x--) {
        ans[x] = (ans[x<<1] + ans[(x<<1)|1] + tn[x<<1] * (s1[kt[(x<<1)|1]]-1) + tp[(x<<1)|1] * kk[x<<1]) % MOD;
        kk[x] = kk[x<<1] + kk[(x<<1)|1];
        kt[x] = kt[x<<1] + kt[(x<<1)|1];
        tp[x] = (tp[x<<1] + tt[x<<1] * (s1[kt[(x<<1)|1]]-1) + tp[(x<<1)|1]) % MOD;
        tn[x] = (tn[x<<1] * s10[kt[(x<<1)|1]] + tn[(x<<1)|1] + kk[x<<1] * tt[(x<<1)|1]) % MOD;
        tt[x] = (tt[x<<1] * s10[kt[(x<<1)|1]] + tt[(x<<1)|1]) % MOD;
    }
    for (int i = 0; i < kr; i++) {
        cin >> d1 >> d2 >> d3;
        if (d1 == 1) {
            cin >> d4;
            update(1, 1, m, d2 + k0, d3 + k0, d4);
        } else {
            fid = 0;
            fa(1, 1, m, d2 + k0, d3 + k0);
            cout << fid << endl;
        }
    }
    return 0;
}
