#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

void qsort(long l, long r, long *m);

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long n, s;
    cin >> n >> s;
    long *a = (long *) malloc(n*sizeof(long));
    for(int i = 0; i < n; i++)
        cin >> a[i];
    qsort(0, n-1, a);
    long temp_sum = 0, temp_number = 0;
    while(temp_sum < s){
        if(temp_sum + a[temp_number] <= s){
            temp_sum += a[temp_number];
            temp_number++;
        } else {
            break;
        }
    }

    cout << temp_number << endl;
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

