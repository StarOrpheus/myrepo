#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#define INF 2100000000
using namespace std;
//string a[100],b[110];
//int f[100][100];
vector<string> a, b;
int main(){
    //ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    string s, s1;
    int n = 0, m = 0;
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
  //  while((c = getchar()) != EOF && c != '\n'){
     //   cin >> b[m];
   //     m++;
 //   }
   // for (int i= 1; i<=n; i++){
  //      cout << a[i] << endl;
  //  }

    /*for(int i = 1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if (a[i] == b[j]){
                f[i][j] = f[i-1][j-1]+1;
            }else{
            f[i][j] = 0;
            }
        }
    }
    int maxx = - INF;
    for(int i = 1; i<=n; i++ ){
        for(int j = 1; j<=m; j++)
            if (f[i][j] > maxx) {
                maxx = f[i][j];
            }
    }
    cout << maxx;*/
	return 0;
}
