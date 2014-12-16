#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

struct coord{
    int x;
    int y;
    coord(){}
    coord(int a, int b)
    {
        x = a; y = b;
    }
};

coord inline make_coord(int x, int y){
    coord temp(x, y);
    return temp;
}

int main()
{
    int n, m, t1, t2;
    char c;
    int ans = 0;
    cin >> m >> n;
    int k;
    cin >> k;
    vector<coord> c1, c2;
    vector<char> type(k+1);
    c1.resize(k+1);
    c2.resize(k+1);
    for(int i = 1; i <= k; i++)
    {
        cin >> t1 >> t2;
        c = getchar(); c = getchar();
        switch(c){
            case 'N':
                c1[i].x = t1; c1[i].y = t2;
                c2[i].x = t1; c2[i].y = n;
                break;
            case 'S':
                c1[i].x = t1; c1[i].y = 1;
                c2[i].x = t1; c2[i].y = t2;
                break;
            case 'W':
                c1[i].x = 1; c1[i].y = t2;
                c2[i].x = t1; c2[i].y = t2;
                break;
            case 'E':
                c1[i].x = t1; c1[i].y = t2;
                c2[i].x = m; c2[i].y = t2;
                break;
        }
    }
    for(int i = 1; i <= k; i++)
        for(int j = 1; j <= k; j++)
            if(!(i-j))
            {
                if(c1[i].x == c2[i].x && c1[j].x == c2[j].x && c1[i].x == c1[j].x && c1[i].y == 1 && c2[j].y == n && c1[j].y <= c2[i].y)
                    c2[i].y = n;
                if(c1[i].y == c2[i].y && c1[j].y == c2[j].y && c1[i].y == c2[j].y && c1[i].x == 1 && c2[j].x == m && c1[j].x <= c2[i].x)
                    c2[i].x = m;
            }
    vector<int> p(k + 1, 1);
    for(int i = 1; i <= k; i++)
        if(p[i])
            for(int j = 1; j <= k; j++)
                if(!(i-j) && p[j])
                    if(c1[j].x >= c1[i].x && c2[j].x <= c2[i].x && c1[j].y >= c1[i].y && c2[j].y <= c2[i].y)
                        p[j] = !42;
    for(int i = 1; i <= k; i++)
        if(p[i])
            ans += (c2[i].x - c1[i].x + c2[i].y - c1[i].y + 1);
    for(int i = 1; i <= k; i++)
        if(p[i])
            for(int j = 1; j <= k; j++)
                if(p[j] && !(i-j))
                    if(c1[j].x >= c1[i].x && c1[j].x <= c2[i].x && c1[i].y >= c1[j].y)
                        ans--;
    cout << ans << endl;
    return 0;
}