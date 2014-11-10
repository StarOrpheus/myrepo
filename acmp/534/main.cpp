#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long n = 0;
    cin >> n;
    long *f = (long *) malloc(n*sizeof(long));
    for(int i = 0; i < n; i++)
        cin >> f[i];
    long k = 0;
    cin >> k;
    long *p = (long *) malloc(k*sizeof(long));
    long *c = (long *) malloc((n+5) * sizeof(long));
    for(int i = 0; i < n; i++)
        c[i] = 0;
    for(int i = 0 ; i < k; i++){
        cin >> p[i];
        c[p[i]]++;
    }
    for(int i = 1; i <= n; i++){
        if(c[i] <= f[i-1]){
            cout << "no" << endl;
        } else {
            cout << "yes" << endl;
        }
    }


    free(c);
    free(p);
    free(f);
    return 0;
}

