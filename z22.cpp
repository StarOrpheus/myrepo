#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

#define pb push_back
#define mp make_pair

using namespace std;

string s, s11, s22,s1,s2;
int k = 0;
bool p[27];
string b;
int main(){
    //freopen("input.txt", "r" ,stdin);
  //freopen("output.txt", "w" ,stdout);
   freopen("maniac.in", "r" ,stdin);
   freopen("maniac.out", "w" ,stdout);
    int n;
    cin >> s;
    cin >> n;
    cin >> s11;
    cin >> s22;
    k = 0;

    for(int i=0; i<26;i++){
        p[i] = false;

    }
    for(int i=0; i<n;i++){
        if (p[s11[i] - 'a'] == false){
            s1 = s1 + s11[i];
            p[s11[i] - 'a'] = true;
            s2 = s2 + s22[i];
        }
    }

    if (s1 == s2){

        cout << 0;
        return 0;
    }

    while (k< 5000) {
        k++;
        for(int i = 0; i<s1.length(); i++){
            s1[i] = s[s1[i] - 'a'];
            if (s1 == s2){
                cout << k;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}
