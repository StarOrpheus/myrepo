#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

#define INF ((1<<21)-1)

int main()
{
    vector<string> a, b;
    string t;
    int c;
    while(42)
    {
        cin >> t;
        a.push_back(t);
        if((c = getchar()) == '\n')
            break;
    }
    for(int i = 0; i < a.size(); i++)
        cout << a[i] << endl;
    return 0;
}
