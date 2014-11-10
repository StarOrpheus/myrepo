#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<long> a;
    long n;
    cin >> n;
    if(n == 2){
        cout << 1 << endl << 3 << endl;
        exit(EXIT_SUCCESS);
    }
    a.push_back(1);
    a.push_back(1);
    while(a[a.size()-1] < n){
        a.push_back(a[a.size()-1] + a[a.size()-2]);
    }
    if(a[a.size() - 1] == n){
        cout << 1 << endl << a.size() << endl;
        exit(EXIT_SUCCESS);
    } else {
        cout << 0 << endl;
        exit(EXIT_SUCCESS);
    }
}

