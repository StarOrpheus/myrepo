#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
long **f;
long n, s;
bool *b;

void destructor(void);
void constructor(void);
void dfs(long x);
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> s;
    constructor();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cin >> f[i][j];
    }
    for(int i = 0; i <= n; i++)
        b[i] = false;
    dfs(s);
    long k = 0;
    for(int i = 1; i <= n; i++)
        if(b[i])
            k++;
    cout << k - 1 << endl;
    destructor();
    return 0;
}

void dfs(long x){
    b[x] = true;
    for(int i = 1; i <= n; i++){
        if(f[x][i] == 1 && !b[i]){
            dfs(i);
        }
    }

}

void destructor(void){
    free(b);
    for(int i = 0; i <= n; i++)
        free(f[i]);
    free(f);
}

void constructor(void){
    f = (long **) malloc(sizeof(long *) * (n+5));
    for(int i = 0; i <= n; i++){
        f[i] = (long *) malloc(sizeof(long) * (n + 5));
    }
    b = (bool *) malloc(sizeof(bool) * (n + 5));
}
