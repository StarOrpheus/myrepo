#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#include <map>
#include <iomanip>
#include <queue>
using namespace std;


#define mkp(a, b) make_pair(a, b)
#define F first
#define S second
#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct node
{
//    bool iff;
    vector<int> a;
    string name;
};

vector<node> world(100000);
int k = 0;

inline bool comp(int a, int b)
{
    if(((world[a].a.size()) ? true : false) == ((world[b].a.size()) ? true : false))
        return world[a].name < world[b].name;
    return world[a].a.size();
}

void go(int& p, string name)
{
    for(int i = 0; i < world[p].a.size(); i++)
        if(world[world[p].a[i]].name == name)
        {
            p = world[p].a[i];
            return;
        }
    k++;
    world[p].a.push_back(k);
    world[k].name = name;
    p = k;
}

inline void f(int p)
{
    sort(world[p].a.begin(), world[p].a.end(), comp);
    for(int i = 0; i < world[p].a.size(); i++)
        f(world[p].a[i]);
}

void inline print(int& p, string l = "")
{
    if(world[p].a.size() == 0)
    {
        cout << l << world[p].name << endl;
        return;
    }
    cout << l << world[p].name << endl;
    l += "|";
    for(int j = 0; j < world[p].name.length(); j++)
        l += '-';
    for(int i = 0; i < world[p].a.size(); i++)
        print(world[p].a[i], l);
}


int main()
{
    ios_base::sync_with_stdio(0);
//    freopen("tree.in", "r", stdin);
//    freopen("tree.out", "w", stdout);
    int root = 0, kt;
    string t;
    cin >> kt;

    for(int i = 0; i < kt; i++)
    {
        cin >> t;
        int pos = 0;
        string st;
        int l = 0;
        while(l < t.length())
        {
            st = "";
            for(; l < t.length() && t[l] != '/'; l++)
                st += t[l];
            l++;
            go(pos, st);
        }
//        cout << kt << endl;
//        cout << it << endl;
    }

    f(0);

    for(int i = 0; i < world[0].a.size(); i++)
    {
#define cur world[0].a[i]
        print(cur);
#undef cur
    }
    return 0;
}