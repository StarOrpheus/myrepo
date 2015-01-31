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

#define S 1
#define F n
#define INF (1 << 30)

struct heap
{
    int a[105];
    int n;
    heap()
    {
        memset((void *) a, '\0', sizeof(int) * 105);
        n = 0;
    }
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<heap> heaps(n+1);
    vector<int> a(n+1, 0);
    for(int i = 1; i <= n; i++)
    {
        scanf("%ld", &a[i]);
        heaps[i].n = a[i];
    }
    bool t_f = true;
    int mn = INF, mx = -1;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] > mx)
            mx = a[i];
        if(a[i] < mn)
            mn = a[i];
    }
    if(mx - mn > k)
    {
        printf("NO\n");
        exit(EXIT_SUCCESS);
    }
    int n_p = n;
    while(n_p)
    {
        for(int i = 1; i <= k; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(heaps[j].n)
                {
                    heaps[j].n--;
                    heaps[j].a[i]++;
                    if(!heaps[j].n)
                        n_p--;
                }
            }
        }
    }
    printf("YES\n");
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
            if(heaps[i].a[j] > 0)
//                printf("%ld ", j);
                for(int c = 1; c <= heaps[i].a[j]; c++)
                    printf("%ld ", j);
        putchar('\n');
    }
    /*for(int i = 1; i <= n; i++)
    {
        heaps[i].a[1]   =  mn;
        heaps[i].n      -= mn;
    }
    for(int i = 1; i <= n; i++)
    {
        if(heaps[i].n)
        {
            for(int j = 2; heaps[i].n; j++, heaps[i].n--)
            {
                heaps[i].a[j]++;
            }
        }
    }
    printf("YES\n");
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
            if(heaps[i].a[j] > 0)
//                printf("%ld ", j);
                for(int c = 1; c <= heaps[i].a[j]; c++)
                    printf("%ld ", j);
        putchar('\n');
    }*/
    return 0;
}
