#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <queue>
#include <locale>
#include <deque>

using namespace std;

#define INF (1<<30)
int z = 1;
int ans;
int n, m;
struct day
{
    int day_num;
    int sun_activity;
    day() {}
    day(int day_num, int sun_activity) : day_num(day_num), sun_activity(sun_activity) {}
};

struct block
{
    vector<day> days;
    block(){}
    block(int i, int a)
    {
        days.push_back(day(i, a));
    }
};
vector<block> tr;

block merge(block &a, block &b)
{
    int un1 = 0, un2 = 0;
    block temp;
    while(un1 < a.days.size() && un2 < b.days.size())
    {
        if(a.days[un1].sun_activity < b.days[un2].sun_activity)
        {
            temp.days.push_back(a.days[un1]);
            un1++;
            continue;
        }
        if(a.days[un1].sun_activity > b.days[un2].sun_activity)
        {
            temp.days.push_back(b.days[un2]);
            un2++;
            continue;
        }
        temp.days.push_back(a.days[un1]);
        temp.days.push_back(b.days[un2]);
        un1++; un2++;
    }
    while(un1 < a.days.size())
    {
        temp.days.push_back(a.days[un1]);
        un1++;
    }
    while(un2 < b.days.size())
    {
        temp.days.push_back(b.days[un2]);
        un2++;
    }
    return temp;
}
int sz, fz, rz;

bool comp(day a, day b)
{
    return (a.sun_activity < b.sun_activity);
}

void fans(int lv, int rv, int l, int r, int v)
{
//    printf("%ld %ld %ld %ld %ld", lv, rv, l, r, v);
    cout << '#' << lv << " " << rv << " " << l << " " << r << " " << v << endl;
    if(lv > r || rv < l)
        return;
    if(!(lv >= l && rv <= r))
    {
        fans(lv, (lv + rv) / 2 , l, r, 2*v);
        fans(((lv + rv) / 2) + 1, rv, l, r, 2*v+1);
        return;
    }
    int un = 0, uk = tr[v].days.size() - 1;
    while(un <= uk)
    {
        if(tr[v].days[(un + uk) / 2].sun_activity == rz)
        {
            ans = tr[v].days[(un+uk) / 2].day_num;
            break;
        }
        if(tr[v].days[(un + uk) / 2].sun_activity > rz)
        {
            uk = ((un + uk) / 2) - 1;
            continue;
        }
        if(tr[v].days[(un + uk) / 2].sun_activity < rz)
        {
            un = ((un + uk) / 2) + 1;
        }
    }
    if(un != uk)
    {
        if(abs(tr[v].days[ans].sun_activity - r) > abs(tr[v].days[un].sun_activity - r))
        {
            ans = tr[v].days[un].day_num;
        }
        if(abs(tr[v].days[ans].sun_activity - r) > abs(tr[v].days[uk].sun_activity - r))
        {
            ans = tr[v].days[uk].day_num;
        }
    }
    return;
}

int main()
{
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n >> m;
    while(z < n)
        z <<= 1;
    tr.resize(2*z + 2);
    int ai;
    for(int i = z; i < n + z; i++)
    {
        cin >> ai;
        tr[i].days.push_back(day(i-z+1, ai));
    }

    for(int i = z-1; i >= 1; i--)
    {
        tr[i] = merge(tr[i*2], tr[i*2+1]);
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> sz >> fz >> rz;
        ans = INF;
        fans(z, z+z-1, sz+z-1, fz+z-1, 1);
        cout << ans << endl;
    }
    return 0;
}