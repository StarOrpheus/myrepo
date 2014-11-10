#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long x1,y1,x2,y2,x3,y3,x,y,a,b,c;
    scanf("%ld %ld %ld %ld %ld %ld \n %ld %ld", &x1, &y1, &x2, &y2, &x3, &y3, &x, &y);
    double d1, d2, d3;
    //first one
     a = y2 - y1;
     b = x1 - x2;
     c = y1 * x2 - y2 * x1;
     d1 = (double) abs(a * x + b * y + c) / ((double) sqrt((double) a * a + b * b));
    //second one
     a = y3 - y2;
     b = x2 - x3;
     c = y2 * x3 - y3 * x2;
     d2 = (double) abs(a * x + b * y + c) / ((double) sqrt((double) a * a + b * b));
    //third one
     a = y1 - y3;
     b = x3 - x1;
     c = y3 * x1 - y1 * x3;
     d3 = (double) abs(a * x + b * y + c) / ((double) sqrt((double) a * a + b * b));
    /* THAT'S IT*/
    printf("%.7f\n", min(d1, min(d2, d3)) - 0.0000001);
    return 0;
}
