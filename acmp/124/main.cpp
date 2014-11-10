#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long n, m, x, y, *k;
    cin >> n >> m;
    k = (long *) calloc(n, sizeof(long));
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        k[x-1]++;
        k[y-1]++;
    }
    for(int i = 0; i < n; i++){
        cout << k[i] << ' ';
    }
    cout << endl;
    return 0;
}

