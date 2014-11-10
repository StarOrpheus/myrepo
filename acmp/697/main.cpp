#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long l, w, h;
    cin >> l >> w >> h;
    if((l*h*2+w*h*2) % 16 == 0){
        cout << (l*h+w*h)/8 << endl;
    } else
        cout << (l*h+w*h)/8 + 1 << endl;
    return 0;
}

