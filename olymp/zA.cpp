#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <queue>
#include <locale>
#include <deque>

using namespace std;

#define S 1
#define F n
#define INF (1 << 30)

int main() {
    freopen("happy.in", "r", stdin);
    freopen("happy.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) scanf("%ld", &a[i]);
    int f1 = 0, f2 = 0;
    for(int i = 0; i < n; i++)
        (a[i] % 2) ? f1++ : f2++;
    if(f2 > f1)
        printf("Happy\n");
    else
        printf("Sad\n");
    return 0;
}
