#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long n = 0;
    cin >> n;
    vector<long> t1, t2;
    long long s1 = 0, s2 = 0;
    long *f = (long *) malloc(n*sizeof(long));
    for(int i = 0; i < n; i++){
       cin >> f[i];
       if(f[i] > 0){
           s1 += f[i];
           t1.push_back(i+1);
       } else if(f[i] < 0){
           s2 += abs(f[i]);
           t2.push_back(i+1);
       }
    }
    if(s1 >= s2){
        cout << t1.size() << endl;
        for(int i = 0; i < t1.size(); i++)
            cout << t1[i] << ' ';
    } else {
        cout << t2.size() << endl;
        for(int i = 0; i < t2.size(); i++){
            cout << t2[i] << ' ';
        }
    }


    free(f);
    return 0;
}

