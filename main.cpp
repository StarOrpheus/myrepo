#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    long long a, c;
    cin >> a >> c;
    long long b = max(a, c) / min(a, c);
    int k = 1;
    if(b != 1)
        k++;
    int d = 2;
    while(d * d < b)
    {
        if(b % d == 0)
            k += 2;
        d++;
    }
    if(d * d == b)
        k++;
    cout << k << endl;
    return 0;
}