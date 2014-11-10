#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

void qsort(long l, long r, long *m);

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long n = 0;
    cin >> n;
    long *a = (long *) malloc(n*sizeof(long));
    for(int i = 0; i < n; i++)
        cin >> a[i];
    qsort(0, n-1, a);
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    free(a);
    return 0;
}

void qsort(long l, long r, long *m){
    long i = l, j = r, x = m[(l + r) / 2];
    do
    {
      while(m[i] < x)
          i++;
      while(m[j] > x)
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

