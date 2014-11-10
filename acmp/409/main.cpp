#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long n, *f;
    double a = 0;
    cin >> n;
    f = (long *) malloc(n * sizeof(long));
    for(int i = 0; i < n; i++){
        cin >> f[i];
    }
    for(int i = 0; i < n-1; i++){
        a += (double) (f[i] + f[i+1]) / 2.0;
    }
    a /= (n-1);
    printf("%.6f\n", a);
    free(f);
    return 0;
}

