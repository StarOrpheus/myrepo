#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    long a;
    cin >> a;
    if(a % 400 == 0 || (a % 100 != 0 && a % 4 == 0)){
        cout << "12/09/";
        (a > 0 && a < 10) ? printf("000%ld\n", a) : a = a;
        (a > 9 && a < 100) ? printf("00%ld\n", a) : a = a;
        (a > 99 && a < 1000) ? printf("0%ld\n", a) : a = a;
        (a > 999) ? printf("%ld\n", a) : a = a;
    } else {
        cout << "13/09/";
        (a > 0 && a < 10) ? printf("000%ld\n", a) : a = a;
        (a > 9 && a < 100) ? printf("00%ld\n", a) : a = a;
        (a > 99 && a < 1000) ? printf("0%ld\n", a) : a = a;
        (a > 999) ? printf("%ld\n", a) : a = a;
    }


return 0;
}
