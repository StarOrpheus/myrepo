#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long n, m, k;
    cin >> n >> m >> k;
    long f[300][300];
    for(int i = 0; i <= n+1; i++)
        for(int j = 0; j <= m+1; j++)
            f[i][j] = 0;
    for(int i = 0; i < k; i++){
        long x, y;
        cin >> x >> y;
        f[x][y] = -1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(f[i][j] == -1){
                cout << '*';
            } else {
                long counter = 0;
                for(int ii = i-1; ii <= i+1; ii++){
                    for(int jj = j-1; jj <= j+1; jj++){
                        if(f[ii][jj] == -1){
                            counter++;
                }}}
                (counter == 0) ? cout << '.' : cout << counter;
            }
        }
        cout << endl;
    }
    return 0;
}

