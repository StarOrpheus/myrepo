#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#define MIN(a, b) ((a < b) ? (a) : (b))
#define MAX(a, b) ((a > b) ? (a) : (b))

using namespace std;

#define TITS

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int l, r, t;
    long long t_s;
    for(int i = 1; i <= m; i++)
    {
        cin >> l >> r;
        if(i-1)
        {
            l = l ^ t_s;
            r = r ^ t_s;
        }
        t_s = 0;
        t = a[l];
        for(int j = l; j <= r; j++)
        {
            if(a[j] > t)
                t = a[j];
            t_s += t;
        }
        cout << t_s << endl;
    }
    return 0;
}