/*
 * main.cpp
 *	Informatics № 1790
 *  Created on: Nov 6, 2014
 *      Author: Jerry Sewell
 */

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

struct __attribute__((packed)) mx
{
    int k, x, y;
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n;
    vector<int> a(n+10);
    vector<int> b;
    for(int i = 1; i <= n; i++)
        scanf("%ld", &a[i]);
    cin >> m;
    b.resize(m+10);
    for(int i = 1; i <= m; i++)
        scanf("%ld", &b[i]);
    vector<vector<int> > g(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            g[i][j] = (a[i] == b[j]) ? (g[i-1][j-1] + 1) : 0;
    mx d;
    d.k = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            if(d.k < g[i][j])
            {
                d.k = g[i][j];
                d.x = i;
                d.y = j;
            }
    }
    cout << d.k << endl;
    vector<int> way;
    while(d.x <= n && d.x >= 1 && d.y <= m && d.y >= 1 && g[d.x][d.y] > 0)
    {
        way.push_back(a[d.x]);
        if(g[d.x][d.y] - 1 != g[d.x-1][d.y-1])
            break;
        d.x--; d.y--;
    }
    for(int i = way.size() - 1; i >= 0; i--)
        printf("%ld ", way[i]);
    cout << endl;
    return 0;
}
