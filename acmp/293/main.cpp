#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, maxd;
    double max;
    cin >> n;
    int *v, *p;
    v = (int *) malloc(n*sizeof(int));
    p = (int *) malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    max = v[0] * p[0] / 100.0;
    maxd = 0;
    for(int i = 0; i < n; i++){
        if(v[i] * p[i] / 100.0 > max){
            max = v[i] * p[i] / 100.0;
            maxd = i;
        }
    }
    cout << maxd + 1 << endl;
    free(v);
    free(p);
    return 0;
}

