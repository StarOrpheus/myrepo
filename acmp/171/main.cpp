#include <iostream>
#include <vector>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    long long n;
    cin >> n;
    vector<int> b;
    int del = 2;
    for(; n != 1; (del == 2) ? del = 3 : del += 2)
    {
        if(n % del == 0)
        {
            int z = 0;
            while(n % del == 0)
            {
                z++;
                n /= del;
            }
            b.push_back(z);
        }
    }
    long long sum = 1;
    int l = b.size();
    for(int i = 0; i < l; i++)
        sum *= b[i] + 1;
    cout << sum << endl;
    return 0;
}