#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long p, k, t = 0;
    cin >> p >> k;
    long *f = (long *) malloc((k - p + 1) * sizeof(long));
    memset((void *) f, '\0',  (k - p + 1) * sizeof(long));
    for(int i = p; i <= k; i++){
        t = i;
        while(t != 2){
            (t % 2 == 0) ? t /= 2 : t = t * 3 + 1;
            f[i-p]++;
        }
    }
    long long sum = 0;
    for(int i = 0; i < k - p + 1; i++)
        sum += f[i];
    cout << sum << endl;

    free(f);
    return 0;
}

