#include <iostream>
#include <cstdlib>

using namespace std;


int main()
{
    int n, k = 1, m = 0;
    cin >> n;
    while(n >> k > 0){
        k++;
    }
    k--;
    for(int i = 1; i <= k; i++){
        n = (n >> 1) + ((n & 1) << k);
        if(n > m)
            m = n;
    }
    if(n == 1)
        cout << 1 << endl;
    else
        cout << m << endl;
    return 0;
}

