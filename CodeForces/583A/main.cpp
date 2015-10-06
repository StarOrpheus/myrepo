#include <iostream>
#include <cstring>
#include <string>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_map<int, bool> mpx, mpy;
    vector<int > ans;
    if( n == 1 )
    {
        puts("1");
        exit(0);
    }
    for(int i = 0; i < n*n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if(mpx[a] || mpy[b])
            continue;
        mpx[a] = 1;
        mpy[b] = 1;
        ans.push_back(i+1);
    }
    for(auto it = 0; it != ans.size(); it++)
        printf("%d ", ans[it]);

    return 0;
}
