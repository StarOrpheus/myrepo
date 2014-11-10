#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long a = 1, b = 0, c = 0;

void swap(long *x, long *y){
    long z = *x;
    *x = *y;
    *y = z;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char x[500];
    cin >> x;
    string s(x);
    for(int i = 0; i < s.length() ; i++){
        if(s[i] == 'A')
            swap(&a, &b);
        if(s[i] == 'B')
            swap(&b, &c);
        if(s[i] == 'C')
            swap(&a, &c);
    }
    if(a == 1)
        cout << 1 << endl;
    if(b == 1)
        cout << 2 << endl;
    if(c == 1)
        cout << 3 << endl;
    return 0;
}

