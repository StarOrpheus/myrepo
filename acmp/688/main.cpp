#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long x, y, dx, dy;
    cin >> x >> y >> dx >> dy;
    long n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        long xt, yt;
        cin >> xt >> yt;
        if(sqrt((double)(xt-x)*(xt-x)+(yt-y)*(yt-y)) < sqrt((double)(dx-xt)*(dx-xt)+(dy-yt)*(dy-yt)) / 2){
            cout << i << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}

