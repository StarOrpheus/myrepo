#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define begin {
#define end }
#define Program int main()
#define lel;
#define readln(a) cin >> (a)
#define write(a) cout << (a)
#define writeln(a) cout << (a) << endl
#define writeln putchar('\n')

typedef int longint;

Program
begin
    freopen("sequence.in", "r", stdin); freopen("sequence.out", "w", stdout);
    longint n;
    readln(n);
    vector<longint> a(n+1);
    vector<long long> b(n+3, 0);
    for(longint i = 1; i <= n; i = i + 1)
    begin
        readln(a[i]);
    end;
    b[2] = a[1];
    for(longint i=3; i <= n+1; i=i+1)
    begin
        b[i]=a[i-1] - b[i-1] - b[i-2];
    end;
    for(longint i= 0; i <= n+1; i=i+1)
    begin
        write(b[i]);
        write(' ');
    end;
    writeln;
end
