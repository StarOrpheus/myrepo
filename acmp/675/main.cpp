#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long n, m, k;
    cin >> n >> m;
    char c;
    long max = 110;
    for(int i = 0; i < n; i++){
        k = 0;
        for(int j = 0; j < m; j++){
            cin >> c;
            (c == '.') ? k++ : k = k;
        }
    (max > k) ? max = k : max = max;
    }
    cout << max << endl;
    return 0;
}

