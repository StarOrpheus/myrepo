#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

long __inline max (long a, long b){
    return (a > b) ? a : b;
}

int main()
{
    long long n, v, k;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> v >> k;
    if((n - 1) * k < v){
        cout << "YES ";
    } else {
        cout << "NO ";
    }
    long long Zapas_Meda = v;
    long long *f = (long long *) calloc(n+10, sizeof(long long));
    f[1] = v;
    for(int i = 2; i <= n; i++){
        Zapas_Meda += max(0, f[i-1] - k);
        f[i] = max(0, f[i-1] - k);
    }
    cout << Zapas_Meda << endl;
    return 0;
}

