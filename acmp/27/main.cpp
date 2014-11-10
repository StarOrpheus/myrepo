#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int w, h, n;
    cin >> w >> h >> n;
    int f[100][100];
    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 100; j++)
            f[i][j] = 0;
    int x1, y1, x2, y2;
    for(int i = 0; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int ai = x1; ai < x2; ai++)
            for(int aj = y1; aj < y2; aj++)
                f[ai][aj] = -1;
    }
    int k = 0;
    for(int i = 0; i < w; i++)
        for(int j = 0; j < h; j++)
            if(f[i][j] == 0)
                k++;
    cout << k << endl;
    return 0;
}

