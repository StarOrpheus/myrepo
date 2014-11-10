#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long k = 0;
    cin >> k;
    long long sum = 0;
    for(int i = 1; sum <= k; i++){
        if(sum <= k && sum + i > k){
            cout << i-1 << endl;
            exit(EXIT_SUCCESS);
        }
        sum += i;
    }
    return 0;
}

