#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long a, b, c;
    double d;
    cin >> a >> b >> c;
    if(a!= 0 && b == 0 && c == 0){
        cout << 1 << endl << 0 << endl;
        exit(EXIT_SUCCESS);
    }
    if(a != 0 && b != 0 && c == 0){
        cout << 2 << endl << 0 << endl << (double) -1 * b / (double) a << endl;
        exit(EXIT_SUCCESS);
    }
    if(a == 0 && b!= 0 && c != 0){
        cout << 1 << endl << -1*c / (double) b << endl;
        exit(EXIT_SUCCESS);
    }
    if(a == 0 && b == 0 && c != 0){
        cout << 0 << endl;
        exit(EXIT_SUCCESS);
    }
    if(a == 0 && b == 0 && c == 0){
        cout << -1 << endl;
    }
    if(a == 0 && b != 0 && c == 0){
        cout << 1 << endl << 0 << endl;
        exit(EXIT_SUCCESS);
    }
    if(a != 0 && b == 0 && c != 0){
        double temp = (double) -1 * c / (double) a;
        (temp > 0) ? cout << 2 << endl << -1 * sqrt((double) temp) << endl << sqrt((double) temp) << endl : cout << 0 << endl;
        exit(EXIT_SUCCESS);
    }

    if(a != 0 && b != 0 && c != 0){
        d = (double) b * b - (double) 4.0 * a * c;
        if(d < 0){
            cout << 0 << endl;
            exit(EXIT_SUCCESS);
        }
        if(d == 0){
            cout << 1 << endl << (double)(-1*b)/(double)(2*a) << endl;
            exit(EXIT_SUCCESS);
        }
        if(d > 0){
            cout << 2 << endl << (double)(-1*b-sqrt((double)d)) / (double)(2*a) << endl << (double)(-1 * b + sqrt((double) d)) / (double)(2*a);
            exit(EXIT_SUCCESS);
        }
    }
    return 0;
}

