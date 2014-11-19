#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    int c;
    string s;
    while((c = getchar()) != EOF && c != '\n')
        s += c;
    cout << "Андрей - губошшлёп" << endl;
    return 0;
}
