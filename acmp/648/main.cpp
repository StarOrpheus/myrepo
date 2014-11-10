#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

void qsort(int l, int r, int *m){
    int i = l, j = r, x = m[(l + r) / 2];
    do{
        while(m[i] > x)
            i++;
        while(m[j] < x)
            j--;
        if(i <= j){
            int k = m[i];
            m[i] = m[j];
            m[j] = k;
            i++;
            j--;
        }
    } while(i <= j);
    if(i < r)
        qsort(i, r, m);
    if(j > l)
        qsort(l, j, m);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int *f;
    int n;
    cin >> n;
    f = (int *) calloc(n, sizeof(int));
    for(int i = 0; i < n; i++)
        cin >> f[i];
    qsort(0, n-1, f);
    long sum1 = 0, sum2 = 0;
    for(int i = 0; i <= n / 2 - 1; i++)
        sum1 += f[i];
    for(int j = n / 2; j < n; j++){
        sum2 += f[j];
    }
    cout << sum1 - sum2 << endl;
    free(f);
    return 0;
}


