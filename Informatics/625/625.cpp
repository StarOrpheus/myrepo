#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <algorithm>
#define INF 1110000
using namespace std;
int p[110000], w[110000],f1[110000] , f[110000];

int main(){
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,e,ff,s;
    cin >> e >> ff;
    s = abs(ff - e);
    cin >> n;
    for (int i = 1; i<=n; i++){
        cin >> p[i] >> w[i];
   //     cout << a[i] << ' ' << b[i]<< ' ' << c[i] << endl;

    }
    for (int i = 1; i<=s; i++){
        f[i] = INF;
        f1[i] = -INF;
    }
    f[0] = 0;
    for (int i = 1; i<=n; i++)
        for(int j=w[i]; j<=s; j++){
            f[j] =min(f[j], f[j-w[i]] + p[i]) ;
            f1[j] =max(f1[j], f1[j-w[i]] + p[i]) ;

        }
        //cout << f[i] << ' ';

    if ((f[s] <1110000  && f1[s]>-1110000) && (f[s] != 0 && f1[s] !=0 )){
          cout << f[s]<< ' ' << f1[s];
    } else
        cout << "This is impossible.";


    return 0;
}
