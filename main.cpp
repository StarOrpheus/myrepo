#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#define MIN(a, b) ((a < b) ? (a) : (b))
#define MAX(a, b) ((a > b) ? (a) : (b))
using namespace std;

int main()
{
 freopen("maniac.in", "r", stdin); freopen("maniac.out", "w", stdout);
    string alphabet, a, b;
    cin >> alphabet;
    int l;
    cin >> l;
    cin >> a;
    cin >> b;
    if (a == b) {
        cout << 0;
        exit(EXIT_SUCCESS);
    }
    int a_l = a.length(), b_l = b.length();
    vector<int> k(28, 0);
    for(int i = 0; i < a_l; i++)
        k[a[i]-'a'] = 1;

    a = ""; char c;
    for(int i = 0; i < 26; i++)
        if(k[i])
        {
            c = i + 'a';
            a += c;
        }
    k.resize(28, 0);
    for(int i = 0; i < 28; i++)
        k[i] = 0;
    for(int i = 0; i < b_l; i++)
        k[b[i] - 'a'] = 1;
    b = "";
    for(int i = 0; i < 26; i++)
        if(k[i])
        {
            c = i + 'a';
            b += c;
        }
    //cout << a << " " << b << endl;
    int df;
    string temp;
    if(a.length() != b.length())
    {
        cout << -1 << endl;
        exit(EXIT_SUCCESS);
    }
    a_l = a.length(); b_l = b.length();
    for(df = 1;df <20000 ;df++) {
        for (int i = 0; i < a_l; i++) {
            a[i] = alphabet[(a[i] - 'a')];
            if (a == b) {
                cout << df << endl;
                exit(EXIT_SUCCESS);
            }
        }
    }
    cout << -1 << endl;
    return 0;
}