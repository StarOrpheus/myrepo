#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int c, f = 1;
    long a[259], b[259];
    //memset(a, '\0', 256 * sizeof(long));
    //memset(b, '\0', 265 * sizeof(long));
    for(int i = 0; i < 256; i++){
        a[i] = 0;
        b[i] = 0;
    }
    while((c = getchar()) != ' '){
        a[toupper(c)]++;
        //cout << toupper(c) << ' ';
    }
    //cout << endl;
    while((c = getchar()) != EOF){
        b[toupper(c)]++;
        //cout << toupper(c) << ' ';
    }
    //cout << endl;
    for(int i = 0; i < 256; i++){
        if(b[i] != a[i]){
            f = 0;
            break;
        }

    }
    if(f)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}

