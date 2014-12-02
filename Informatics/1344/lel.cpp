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

struct coord{
    int x;
    int y;
};

coord inline makeCoord(int x, int y)
{
    coord temp;
    temp.x = x; temp.y = y;
    return temp;
}

struct fig{
    int n;
    int ind;
    vector<coord> c;
};

bool inline comp(fig a, fig b)
{
    int max_y1 = -1000000, max_y2 = -1000000;
    for(int i = 1; i <= a.n; i++)
        if(max_y1 < a.c[i].y)
            max_y1 = a.c[i].y;
    for(int i = 1; i <= b.n; i++)
        if(max_y2 < b.c[i].y)
            max_y2 = b.c[i].y;
    return max_y1 > max_y2;
}

int main() {
    int n;
    scanf("%ld", &n);
    vector<fig> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        scanf("%ld", &a[i].n);
        a[i].ind = i;
        a[i].c.resize(a[i].n+1);
        for(int j = 1; j <= a[i].n; j++)
        {
            scanf("%ld %ld", &a[i].c[j].x, &a[i].c[j].y);
        }
    }
    sort(a.begin()+1, a.end(), comp);
    vector<int> f(n+1, 0);
    for(int i = 1; i <= n; i++)
    {
        f[a[i].ind] = i-1;
    }
    for(int i = 1; i <= n; i++)
        printf("%ld ", f[i]);
    putchar('\n');
    return 0;
}
