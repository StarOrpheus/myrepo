#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

double sqr(double d){
    return d*d;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long a[5][2], k = 0;
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 2; j++)
            cin >> a[i][j];
    const int b[] = {0, 25, 50, 75, 100};
    int f[] = {0, 0, 0, 0, 0};
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++)
            if((10 - sqrt((double) sqr(a[i][0]-b[j]) + sqr(a[i][1]-0)) == 0|| 10 - sqrt((double) sqr(a[i][0]-b[j]) + sqr(a[i][1]-0)) >= 0.00001 || sqrt((double) sqr(a[i][0]-b[j]) + sqr(a[i][1]-0)) - 10 <= 0.00001) && f[j] == 0){
                f[j] = 1;
                k++;
            }
    }
    cout << k << endl;
    return 0;
}

