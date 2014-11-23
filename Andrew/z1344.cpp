#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define INF 2100000000
using namespace std;
int a[10000],nom[10000];
bool comp1(int x, int y){
    swap(nom[x],nom[y]);
    if (x>y){
        return x;
    }else{
        return y;
    }
}
bool comp(int x, int y){
    swap(a[x],a[y]);
    if (x>y){
        return x;
    }else{
        return y;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for(int i =0; i<n; i++){
        int k, mx,my;
        cin >>k;
        cin >> mx >> my;
        for(int i=2; i<=k; i++){
            int x, y;
            cin >> x >> y;
            if (y > my){
                my = y;
            }
            if ((x > mx) && (y == my)){
                mx = x;
            }
        }
        a[i] = my;
        nom[i] = i;
    }
    sort(a, a+n, comp1);
    for (int i =0; i<n; i++){
        a[i] = i;
    }
    sort(nom, nom+n, comp);

    for (int i = 0; i<n; i++){
        cout << a[i];
    }

	return 0;
}
