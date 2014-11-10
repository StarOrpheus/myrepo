#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long n = 0;
    cin >> n;
    long max_del = 1, max_sum = 1;
    long d = 1;
    while(d * d <= n){
        if(n % d == 0){
            long current_sum = 0, temp_del = d;
            while(temp_del != 0){
                current_sum += temp_del % 10;
                temp_del /= 10;
            }
            if(max_sum < current_sum){
                max_sum = current_sum;
                max_del = d;
            }
            temp_del = n / d;
            current_sum = 0;
            while(temp_del != 0){
                current_sum += temp_del % 10;
                temp_del /= 10;
            }
            if(max_sum < current_sum){
                max_sum = current_sum;
                max_del = n / d;
            }
        }
        d++;
    }
    cout << max_del << endl;
    return 0;
}

