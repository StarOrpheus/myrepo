#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char temp[5010];
    cin >> temp;
    string c(temp);
    long k = 0;
    for(int i = c.length() - 1; i >= 0 && c[i] == '0'; i--)
        k++;
    cout << 1;
    for(int i = 0; i < k; i++)
        cout << '0';
    cout << endl;
    return 0;
}

