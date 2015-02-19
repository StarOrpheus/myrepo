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
using namespace std;

#define INF (1<<30)
#define SWAP(x, y) x = x ^ y; y = x ^ y; x = x ^ y;
#define P 31
#define MAX(a, b) ((a > b) ? (a) : (b))
inline long long calc_hash(string &s)
{
    long long hash = 0, p_pow = 1;
    for (size_t i=0; i<s.length(); ++i)
    {
        hash += (s[i] - 'a' + 1) * p_pow;
        p_pow *= P;
    }
    return hash;
}
inline long long calc_hash(char *a)
{
    string s = a;
    return calc_hash(s);
}
inline long long calc_hash(char a)
{
    return P*(a - 'a' + 1);
}


int n, l, k;
vector<string> a;
long long       hashes[1010];
int             eq[1010];
int             ans[1010];



int main() {
//    freopen("/home/jyree/src/input", "r", stdin);
//    freopen("/home/jyree/src/output.txt", "w", stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    cin >> n >> l >> k;
    a.resize(n);
    memset((void *) eq, 0, n*sizeof(int));
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        hashes[i] = calc_hash(a[i]);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(hashes[i] == hashes[j])
                eq[i]++;
        }
    }
    for(int i = 0; i < n; i++)
    {
        ans[i] = eq[i];
    }
//    for(int i = 0; i < n; i++)
//        printf("%d ", ans[i]);
//    putchar('\n');
//    return 0;
    for(; k; k--)
    {
//        cout << "AAAAAAAAA" << endl;
        int p1, w1, p2, w2;
        scanf("%d %d %d %d", &p1, &w1, &p2, &w2);
        long long hash1, hash2;
//        recount(p1, w1, p2, w2);
        p1--; p2--; w1--; w2--;
        swap(a[p1][w1], a[p2][w2]);
        hash1 = calc_hash(a[p1]);
        hash2 = calc_hash(a[p2]);
        for(int i = 0; i < n; i++)
        {
            if(i == p1 || i == p2)
                continue;
            if(hashes[i] != hashes[p1] && hash1 == hashes[i])
            {
                eq[p1]++; eq[i]++;
            } else if(hashes[i] == hashes[p1] && hash1 != hashes[i])
            {
                eq[p1]--; eq[i]--;
            }
            if(p1 != p2)
            {
                if(hashes[i] != hashes[p2] && hash2 == hashes[i])
                {
                    eq[p2]++; eq[i]++;
                } else if(hashes[i] == hashes[p2] && hash2 != hashes[i])
                {
                    eq[p2]--; eq[i]--;
                }
            }
        }
        if(p1 != p2 && hashes[p1] != hashes[p2] && hash1 == hash2)
        {
            eq[p1]++; eq[p2]++;
        }
        if(p1 != p2 && hashes[p1] == hashes[p2] && hash1 != hash2)
        {
            eq[p1]--; eq[p2]--;
        }
        hashes[p1] = hash1; hashes[p2] = hash2;
        for(int i = 0; i < n; i++)
        {
            ans[i] = MAX(ans[i], eq[i]);
        }
    }
    for(int i = 0; i < n; i++)
        printf("%d\n", ans[i]);
    putchar('\n');
    return 0;
}

