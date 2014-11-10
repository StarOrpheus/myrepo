#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long n, k = 0, f = 0;
    cin >> n;
    f = n;
    while( n != 0 ){
        n = (n - 1) & n;
        k++;
    }
    cout << f + k << endl;
    return 0;
}

