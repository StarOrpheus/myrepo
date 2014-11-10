#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long n;
    cin >> n;
    long sum = 0, l = 0;
    sum += n / 107 * 100;
    l += n / 107 * 7;
    n %= 107;
    (n > 7) ? l += 7 : l = l;
    (n > 7) ? sum += n - 7 : sum = sum;
    cout << sum << ' ' << l << endl;
    return 0;
}

