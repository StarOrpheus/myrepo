#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long x1, x2, x3;
    cin >> x1 >> x2 >> x3;
    if(x1 == 0 && x2 == 0 && x3 == 0){
        cout << 0 << endl;
        exit(EXIT_SUCCESS);
    }
    (x1 != 0) ? cout << x1 : cout << "";
    (x2 != 0) ? (x2 > 0 && x1 != 0) ? (x2 == 1) ? cout << "+x" : cout << '+' << x2 << 'x' : (x2 == -1) ? cout << "-x" : (x2 == 1) ? cout << 'x' : (x2 == -1) ? cout << "-x" : cout << x2 << 'x' : cout << "";
    (x3 != 0) ? (x3 == 1) ? cout << 'y' : (x3 == -1) ? cout << "-y" : (x2 == 0 && x1 == 0) ? cout << x3 << 'y' :  (x3 > 0) ? (x3 == 1) ? cout << "+y" : cout << '+' << x3 << 'y' : (x3 == -1) ? cout << "-y" : cout << x3 << 'y' : cout << "";
    cout << endl;
    return 0;
}

