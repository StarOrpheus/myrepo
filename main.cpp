#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cstring>

#define MIN(a, b) ((a < b) ? (a) : (b))
#define MAX(a, b) ((a > b) ? (a) : (b))

using namespace std;

struct interv{
    int open;
    int close;
    interv(){}
    interv(int x, int y)
    {
        open = x;
        open = y;
    }
};
struct st_el{
    int el;
    char type;
};

bool inline comp(st_el a, st_el b)
{
    if(a.el < b.el)
        return true;
    if(a.el > b.el)
        return false;
    if(!a.type && b.type)
        return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<interv> a(n);
    int t;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].open >> t;
        a[i].close = a[i].open + t;
    }
    vector<st_el> st(2 * n);
    for(int i = 0; i < n; i++)
    {
        st[i].el        = a[i].open;
        st[i].type      = 0b1;
        st[n + i].el    = a[i].close;
        st[n+i].type    = 0b0;
    }
    sort(st.begin(), st.end(), comp);
    //for(int i = 0; i < 2 * n; i++)
        //cout << (int) st[i].el << " # " << (int) st[i].type << endl;
    int k_open = 0, k_m = 0;
    for(int i = 0; i < 2 * n; i++)
    {
        k_open += (st[i].type) ? 1 : -1;
        k_m = MAX(k_open, k_m);
    }
    cout << k_m << endl;
    return 0;
}