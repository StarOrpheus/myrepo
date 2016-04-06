#include <bits/stdc++.h>

using namespace std;

int cows = 0, bulls = 0;
string resp;
set<int> s;

string itos(int x)  // int to string
{
    string res;
    while (x)
    {
        res = char('0' + (x % 10)) + res;
        x /= 10;
    }
    return res;
}

string zeros(int x) // Transform int to 4-char str
{
    string res;
    int nos = 0, y = x;
    while (y)
    {
        y /= 10;
        nos++;
    }
    while (nos < 4)
    {
        res += "0";
        nos++;
    }
    res += itos(x);
    return res;
}

bool check(int x, int mock)
{
    int b = 0;
    string _x = zeros(x), _mock = zeros(mock);
    int c = 0;
    vector<int> nm(10, 0);

    for (int i = 0; i < 4; ++i)
        if (_x[i] == _mock[i])
            b++;

    for (int i = 0; i < 4; ++i)
        nm[(int) _mock[i] - '0']++;

    for (int i = 0; i < 4; ++i)
        if (nm[(int) _x[i] - '0'] > 0)
            c++;

    c -= b;

    return (b != (int) resp[0] - '0' || c != (int) resp[1] - '0');
}

bool can(int x)
{
    vector<int> nm(10, 0);
    int nos = 0, y = x;
    bool res = true;

    while (x)
    {
        nm[x % 10]++;
        x /= 10;
        nos++;
    }

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

    set<int> used;

    for (int i = 123; i < 10000; ++i)
        if (can(i))
            s.insert(i);

    while (resp != "40")
    {
        vector<int> todelete;
        int cur = -1;

        for (auto i = s.begin(); i != s.end() && cur == -1; ++i)
            if (used.count(*i) == 0)
                cur = *i;

        cout << zeros(cur) << endl;
        cin >> resp;
        used.insert(cur);

        if (resp == "40")
            return 0;

        for (auto i = s.begin(); i != s.end(); ++i)
            if (check(cur, *i))
                todelete.push_back(*i);

        for (int i = 0; i < todelete.size(); ++i)
            s.erase(todelete[i]);
    }
    return 0;
}
