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


int main() {
    int n;
    cin >> n;
    vector<vector<int> > g(n+1, vector<int>(n+1, 0));
    int x;
    for(int i = 1; i <= n; i++)
    {
        while(42)
        {
            scanf("%ld", &x);
            if(x == 0)
                break;
            g[i][x]++;
        }
    }
    vector<int> a(n+1, 0);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            a[j] += g[i][j];
    int nv;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == 0)
        {
            nv = i; a[i] = -1;
            break;
        }
    }
    //cout << nv << endl;
    int k = 0;
    vector<int> p(n+1, 0);
    while(nv)
    {
        k++;
        p[k] = nv;
        for(int i = 1; i <= n; i++)
            if(g[nv][i])
                a[i]--;
        nv = 0;
        for(int i = 1; i <= n; i++)
            if(!a[i])
            {
                nv = i;
                a[nv] = -1;
                break;
            }
    }
    for(int i = 1; i <= n; i++)
        cout << p[i] << " ";
    cout << endl;
    return 0;
}
