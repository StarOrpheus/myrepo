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


long long fack(long long c)
{
    if(c == 1)
        return 1;
    if(c == 0)
        return 1;
    return fack(c - 1)*c;
}

int main(){
//    freopen("lel.out", "w", stdout);
    long long k, n, ans = 0;
    cin >> k >> n;
    int f[110][5];
    for(int i = 0; i <= 100; i++)
        f[i][0] = 1;
    for(int i = 0; i <= 100; i++)
    {
        for(int j = 1; j <= 4; j++)
            f[i][j] = f[i-1][j] + f[i-1][j-1];
    }
//    cout << f[5][4] << endl;
    long long a[101];
    memset((void *) a, '\0', sizeof(long long) * 101);
    for(int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        if(c <= 100)
            a[c]++;
    }
    if(!(k % 4))
    {
        int t = a[k / 4];
        ans += t * (t-1) * (t-2) * (t-3) / fack(4);
    }
    for(int i = 0; i < 100; i++)
    {
        for(int j = i + 1; j <= 100; j++)
        {
            for(int inum = 1; inum <= 3; inum++)
            {
                int jnum = 4 - inum;
                if(i*inum + j*jnum == k)
                {
                    ans += f[a[i]][inum] * f[a[j]][jnum];
                }
            }
        }
    }
    for(int i = 0; i <= 100; i++)
    {
        for(int j = i+1; j <= 100; j++)
        {
            for(int h = j+1; h <= 100; h++)
            {
                for(int inum = 1; inum <= 2; inum++)
                {
                    int jnum = 3 - inum;
                    if(i*inum + j*jnum + h == k)
                    {
                        ans += f[a[i]][inum] * f[a[j]][jnum] * h;
                    }
                }
            }
        }
    }
    for(int i = 0; i < 100; i++)
        for(int j = i+1; j <= 100; j++)
            for(int h = j+1; j <= 100; j++)
            {
                int x = k - i - j - h;
                if(x > h)
                    ans += a[i]*a[j]*a[h]*a[x];
            }
    cout << ans << endl;
//    cout << f(5, 4) << endl;
    return 0;
}