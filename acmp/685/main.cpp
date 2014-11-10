#include <iostream>
#include <cstdio>
using namespace std;

void qsort(long l, long r, long *m);

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long a[4], b[4];
    cin >> a[1] >> a[2] >> a[3] >> b[1] >> b[2] >> b[3];
    qsort(1, 3, a);
    qsort(1, 3, b);
    cout << a[1]*b[1]+a[2]*b[2]+a[3]*b[3] << endl;
    return 0;
}

void qsort(long l, long r, long *m){
    long i = l, j = r, x = m[(l + r) / 2];
    do
    {
        while(m[i] > x)
            i++;
        while(m[j] < x)
            j--;
        if(i <= j){
            long z = m[i];
            m[i] = m[j];
            m[j] = z;
            i++; j--;
        }
    } while(i <= j);
    if(i < r)
        qsort(i, r, m);
    if(l < j)
        qsort(l, j, m);
}

