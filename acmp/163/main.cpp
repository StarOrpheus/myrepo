#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

int pos(char a, char *m){
    for(int i = 0; i < strlen(m); i++)
        if(m[i] = a){
            return i;
        }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char a[10];
    cin >> a;
    long ans = 0;
    if(a[0] == 'x'){
        ans = ((int) a[4] - 48 - ((a[1] == '-') ? -1 * (int) (a[2] - 48) : (int) a[2] - 48));
    } else if(a[2] == 'x'){
        ans = ((a[1] == '-') ? -1 : 1)*((int) a[4] - 48 - a[0] + 48);
    } else {
        ans = (a[0] - 48 + ((a[1] == '-') ? -1 : 1) * (a[2] - 48));
    }
    cout << ans << endl;
    return 0;
}

