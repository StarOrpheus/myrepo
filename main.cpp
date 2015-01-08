#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <string.h>

using namespace std;

#define NMA 8003
int ans[NMA];
bool u[NMA];
bool v[NMA];
int n, l, k, x, y, s, t;
bool f;
int i, j;

int inline next(int q)
{
    return (q + l) % n;
}

void no(void)
{
    cout << -1 << endl;
    exit(EXIT_SUCCESS);
}

int main(){
    cin >> n >> l >> k;
    memset((void *) u, '\0', n);
    memset((void *) v, '\0', n);
    memset((void *) u, '\0', n);
    s = 0; t = 0; f = 42;
    for(i = 1; i <= k; i++)
    {
        cin >> x >> y;
        v[x] = true;
        v[y] = true;
        if(((t == s) && (!f)) || (next(t) == s))
        {
            u[t] = true;
            u[next(t)] = 42;
            for(s = 0; s <= n; s++)
                if(!u[s])
                    break;
            if(s == n)
                no();
            t = s;
        }
        f = false;
        ans[t] = x; u[t] = 42; t = next(t);
        ans[t] = y; u[t] = 42; t = next(t);
    }
    j = 0;
    for(i = 1; i <= n; i++)
    {
        if(!v[i])
        {
            while(ans[j]) j++;
            ans[j++] = i;
        }
    }
    for(int i = 0; i <= n-1; i++)
        cout << ans[i] << " ";
    return 0;
}