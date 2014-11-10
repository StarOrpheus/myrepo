#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long n;
    cin >> n;
    long d = 2;
    while(d < n){
        d *= 2;
    }
    (d == n || n == 1) ? cout << "YES" : cout << "NO";
    return 0;
}

