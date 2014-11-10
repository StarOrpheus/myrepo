#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

int prost(long x){
    if(x % 2 == 0){
        if(x == 2){
            return 0;
        }
        return 1;
    }
    int d = 3;
    while(d * d <= x){
        if(x % d == 0){
            return 1;
        }
        (d == 3) ? d += 2 : d++;
    }
    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //vector<int> a;
    long long int a[50000];
    long long int it = 0;
    long long int k = 0;
    a[it] = 2;
    it++;
    for(long i = 3; it <= 10000; i += 2){
        if(!prost(i)){
            k = i;
            vector<int> temp;
            while(k != 0){
                temp.push_back(k % 10);
                //cout << k % 10 << ' ';
                k = k / 10;
            }
            for(int j = temp.size()-1; j >= 0; j--){
                a[it] = temp[j];
                it++;
            }
        }
    }
    long n;
    cin >> n;
    int kk;
    for(int i = 0; i < n; i++){
        cin >> kk;
        cout << a[kk-1];
    }
    return 0;
}

