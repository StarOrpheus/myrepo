#include <stdio.h>

int main()
{
    int c;
    freopen("/dev/random", "r", stdin); freopen("output.txt", "w", stdout);
    for(int i = 1; i <= 10000; i++)
    {
        c = getchar();
        printf("%c", c);
    }
    return 0;
}
