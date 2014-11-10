#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long k = 0;
    cin >> k;
    for(int i = 0; i < k; i++){
        long x = 0, y = 0;
        cin >> x >> y;
        bool xv[20], yv[20];
        for(int i = 0; i < 20; i++){
            xv[i] = false;
            yv[i] = false;
        }
        while(x != 0){
            xv[x % 10] = true;
            x /= 10;
        }
        while(y != 0){
            yv[y % 10] = true;
            y /= 10;
        }
        bool f = true;
        for(int i = 0; i < 10; i++){
            if((xv[i] && yv[i]) || (!xv[i] && !yv[i])){

            } else {
                f = false;
            }
        }
        if(f){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

