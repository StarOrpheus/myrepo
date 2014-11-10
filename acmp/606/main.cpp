#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long x, y, i;
    cin >> x >> y >> i;
    cout << ((x <= y + i && y <= x + i && i <= x + y) ? "YES" : "NO") << endl;
    return 0;
}

