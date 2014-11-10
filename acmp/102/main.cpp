#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long x1, y1, x2, y2, x3, y3, x, y;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x >> y;
    long z1 = (x - x1) * (y2 - y1) - (y - y1) * (x2 - x1),
            z2 = (x - x2) * (y3 - y2) - (y - y2) * (x3 - x2),
            z3 = (x - x3) * (y1 - y3) - (y - y3) * (x1 - x3);
    if((z1 >= 0 && z2 >= 0 && z3 >= 0) || (z1 <= 0 && z2 <= 0 && z3 <= 0)){
        cout << "In" << endl;
    } else{
        cout << "Out" << endl;
    }
    return 0;
}

