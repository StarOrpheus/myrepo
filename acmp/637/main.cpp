#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long n = 0;
    cin >> n;
    long *f = (long *) malloc(sizeof(long) * n);
    long k;
    for(int i = 0; i < n; i++)
        cin >> f[i];
    cin >> k;
    long a = 0;
    for(int i = 0; i < n; i++){
        a += min(f[i], k);
    }
    cout << a << endl;
    return 0;
}

