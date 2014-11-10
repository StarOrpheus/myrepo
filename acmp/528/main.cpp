#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long n, k;
    cin >> n >> k;
    long long sum = n;
    for(int i = 2; i <= k; i++){
        sum += n * i - 2 * i + 1;
    }
    cout << sum << endl;
    return 0;
}

