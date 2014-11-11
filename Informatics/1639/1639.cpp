#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    long long n;
    cin >> n;
    vector<int > a(45, 0);
    const int b[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    for(int i = 2; i <= n; i++)
    {
        int v = i;
        for(int j = 0; j < 15 && v != 1; j++)
            if(v % b[j] == 0)
            {
                int z = 0;
                while(v % b[j] == 0)
                {
                    z++; v /=  b[j];
                }
                a[j] += z;
            }
    }
    int s = 1;
    for(int i = 0; i < 15; i++)
    {
        s *= a[i] + 1;
    }
    cout << s << endl;
    return 0;
}
