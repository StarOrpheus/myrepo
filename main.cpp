#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define INF (1<<30)
#define MIN(a, b) (a < b) ? (a) : (b)

int main()
{
//    freopen("meeting.in", "r", stdin);
//    freopen("meeting.out", "w", stdout);
    long long n, k;
    cin >> n >> k;
    
    int i = 1;
    while(k - n + i >= 0 && k)
    {
        printf("%ld ", n - i + 1);
        k -= n - i;
        i++;
    }
    if(!k)
    {
        for(int l = 1; l + i - 1 <= n; l++)
            printf("%ld ", l);
        printf("\n");
        exit(EXIT_SUCCESS);
    }
    for(int l = 1; l + i <= n; l++)
    {
        if(n - l - i == k - 1)
            printf("%ld ", n - i + 1);
        printf("%ld ", l);
    }
    return 0;
}