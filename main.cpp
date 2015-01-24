#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define INF (1<<30)
#define MIN(a, b) (a < b) ? (a) : (b)

const long long mods[] = {15485863, 19413103, 136869497};
pair<int, pair<int, int > > p[3000003];
#define F first
#define S second

int inline str_mod(string& s, int m)
{
    int sur     = 0;
    int l       = s.length();
    for(int i = 0; i < l; i++)
    {
        sur = (sur*10 + s[i] - '0') % m;
    }
    return sur;
}

int main()
{
//    freopen("meeting.in", "r", stdin);
//    freopen("meeting.out", "w", stdout);
    p[0].F = 1;
    p[0].S.F = 1;
    p[0].S.S = 1;

    p[1].F = 1;
    p[1].S.F = 1;
    p[1].S.S = 1;

    for(int i = 2; i <= 3*1000001; i++)
    {
        p[i].F      = (p[i-2].F     + p[i-1].F)     % mods[0];
        p[i].S.F    = (p[i-2].S.F   + p[i-1].S.F)   % mods[1];
        p[i].S.S    = (p[i-2].S.S   + p[i-1].S.S)   % mods[2];
    }

    sort(p, p + 3*1000001);

    int n;
    cin >> n;
    string s;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        int p1, p2, p3;
        p1      = str_mod(s, mods[0]);
        p2      = str_mod(s, mods[1]);
        p3      = str_mod(s, mods[2]);
//        cout << p1 << " " << p2 << " " << p3 << " ";
        if(binary_search(p, p + 3*1000001, pair<int, pair<int, int > >(p1, pair<int, int>(p2, p3))))
        {
            printf("Yes\n");
        } else
        {
            printf("No\n");
        }

    }
    return 0;
}