#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <limits>
#include <cmath>
#include <iomanip>
#include <queue>
using namespace std;

#define MIN(a, b) ((a < b) ? (a) : (b))
#define MAX(a, b) ((a > b) ? (a) : (b))

int HOLY_COW = 0;

int inline fsum(int l, int r, int lv, int rv, int v, vector<int> &tree){
//    printf("%ld %ld %ld %ld %ld\n", l, r, lv, rv, v);
    if(lv > r || rv < l)
        return 0;
    if(lv >= l && rv <= r)
    {
//        HOLY_COW++;
//        cout << " Lel \n";
        return tree[v];
    }
    return fsum(l, r, lv, (lv + rv) / 2, 2*v, tree) + fsum(l, r, ((lv + rv) / 2) + 1, rv, 2*v + 1, tree);
}

#define L 2
#define R 4

int main(){
//    freopen("lel.out", "w", stdout);
    int n;
    cin >> n;
    int z = 1;
    while(z < n)
        z <<= 1;
    vector<int> tree(2*z+1, 0);
    for(int i = z; i <= z + n - 1; i++)
        tree[i] = i - z + 1;
    for(int i = z-1; i; i--)
        tree[i] = tree[2*i] + tree[2*i + 1];
//    cout << fsum(L + z - 1, R + z - 1, z, z + z - 1, 1, tree) << endl;
//    cout << HOLY_COW << endl;
    for(int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        int n_z = tree[z + k - 1];
        if(n_z + k <= n)
        {
            int s = fsum(k + z, k + z + n_z - 1, z, (z << 1) - 1, 1, tree);
            tree[k + z - 1] = s / n_z;
            int v = (k + z - 1) / 2;
            while(v >= 1)
            {
                tree[v] = tree[2 * v] + tree[2 * v + 1];
                v = v / 2;
            }
            continue;
        }
        
    }

    return 0;
}