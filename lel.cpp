#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int inline f(int i)
{
    int z = 1;
    while(z < i){
        z <<= 1;
    }
    z /= 4;
    return z;

}


int main(){
    int n;
    cin >> n;
    vector<int> a(2*n + 3);
    a[1] = 1;
    for(int i = 2; i <= 2*n; i++)
    {
        if(i % 2 == 0)
            a[i] = a[i / 2];
        else
            a[i] = a[i-1] + f(i);
    }
    for(int i = n+1; i <= 2 * n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}