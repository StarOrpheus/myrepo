/*
        ♥♥♥♥♥♥───♥♥♥♥───♥♥♥♥♥───♥♥──♥♥───♥♥♥♥───♥♥──♥♥───♥♥♥♥─────♥♥♥
        ♥♥──────♥♥──♥♥──♥♥──♥♥──♥♥──♥♥──♥♥──♥♥──♥♥─♥♥───♥♥──♥♥───♥♥─♥♥
        ♥♥──────♥♥──♥♥──♥♥♥♥♥───♥♥♥♥♥♥──♥♥──♥♥──♥♥♥♥────♥♥──♥♥───♥♥─♥♥
        ♥♥──────♥♥──♥♥──♥♥──♥♥──♥♥──♥♥──♥♥──♥♥──♥♥─♥♥───♥♥──♥♥──♥♥♥♥♥♥♥
        ♥♥───────♥♥♥♥───♥♥♥♥♥───♥♥──♥♥───♥♥♥♥───♥♥──♥♥───♥♥♥♥───♥─────♥
*/

#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define pob pop_back

#define GCD __gcd

using namespace std;

#ifdef LOCAL
#define TASK "task"
#define debug(...) printf(__VA_ARGS__)
#else
#define TASK "diamond"
#define debug(...)
#define cerr if(0)cerr
#endif // LOCAL
//                R  U  L   D
const int sy[] = {0, 1, 0, -1};
const int sx[] = {1, 0, -1, 0};

int cows = 0, bulls = 0;
string resp;
set<int> s;

void upd()
{
    cows += resp[1] - '0';
    bulls += resp[0] - '0';
}

void check()
{
    if (resp == "40")
        exit(0);
}

string itos(int x)
{
    string res;
    while (x)
    {
        res = char('0' + (x % 10)) + res;
        x /= 10;
    }
    return res;
}

string zeros(int x)
{
    string res;
    int nos = 0, y = x;
    while (y)
        y /= 10,
        nos++;
    while (nos < 4)
        res += "0",
        nos++;
    res += itos(x);
    return res;
}

bool check(int x, int mock)
{
    int b = 0;
    string _x = zeros(x), _mock = zeros(mock);
//    cerr << _x << " " << _mock << endl;
    for (int i = 0; i < 4; ++i)
        if (_x[i] == _mock[i])
            b++;
    int c = 0;
    vector<int> nm(10, 0);
    for (int i = 0; i < 4; ++i)
        nm[(int) _mock[i] - '0']++;
    for (int i = 0; i < 4; ++i)
        if (nm[(int) _x[i] - '0'] > 0)
            c++;
    c -= b;
    if (b != (int) resp[0] - '0' || c != (int) resp[1] - '0')
        return true;
    else
        return false;
//    cerr << b << " " << c << endl;
}

bool can(int x)
{
    vector<int> nm(10, 0);
    int nos = 0, y = x;
    while (x)
        nm[x % 10]++,
        x /= 10,
        nos++;
    bool res = true;
    for (int i = 0; i < 10; ++i)
        if (nm[i] > 1)
            res = false;
    if (nos == 3)
        while (y)
        {
            if (y % 10 == 0)
                res = false;
            y /= 10;
        }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef LOCAL
//	freopen(TASK ".in", "r", stdin);
//	freopen(TASK ".out", "w", stdout);
#endif // LOCAL
    for (int i = 123; i < 10000; ++i)
        if (can(i))
            s.insert(i);
//    check(123, 5123);
//    return 0;

    set<int> used;
    while (resp != "40")
    {
        int cur = -1;
        for (auto i = s.begin(); i != s.end() && cur == -1; ++i)
            if (used.count(*i) == 0)
                cur = *i;
//        int cur = *s.begin();
        cout << zeros(cur) << endl;
        cin >> resp;
        used.insert(cur);
        if (resp == "40")
            return 0;
        vector<int> todelete;
        for (set<int>::iterator i = s.begin(); i != s.end(); ++i)
            if (check(cur, *i))
                todelete.pb(*i);
        for (int i = 0; i < todelete.size(); ++i)
            s.erase(todelete[i]);
    }
    return 0;
}
