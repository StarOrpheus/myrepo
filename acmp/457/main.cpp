#include <iostream>
#include <cstdio>
using namespace std;

void qsortmax(long l, long r, long *m);
void qsortmin(long l, long r, long *m);
long max(long x, long y);
long min(long x, long y);

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long a, k = 0, last, current;
    cin >> a;
    last = a; 
    current = 0;
    while(1){
    	current = a;
    	long c[10];
    	long temp = 0;
    	while(current != 0){
    		c[temp] = current % 10;
    		current /= 10;
    		temp++; 
    	}
        qsortmax(0, temp-1, c);
    	long x = 0, y = 0;
    	for(int i = 0; i < temp; i++)
    		x = x * 10 + c[i];
        qsortmin(0, temp-1, c);
    	for(int i = 0; i < temp; i++)
    		y = y * 10 + c[i];
        a = max(x, y) - min(x, y);
        if(a == last){
            cout << 6174 << endl << ((a == 0) ? 5 : k) << endl;
    		break;
        } else {
            last = a;
        }
    	k++;
    }
    return 0;
}

void qsortmax(long l, long r, long *m){
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
        qsortmax(i, r, m);
	if(j > l)
        qsortmax(l, j, m);
}

void qsortmin(long l, long r, long *m){
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
        qsortmin(i, r, m);
    if(j > l)
        qsortmin(l, j, m);
}

long max(long x, long y){
    return ((x > y) ? x : y);
}

long min(long x, long y){
    return ((x < y) ? x : y);
}
