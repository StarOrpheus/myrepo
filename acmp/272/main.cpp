#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

long str_to_long(char *s);

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char current_num[10];
    long max = -10000000, min = 10000000, current_pos = 1, temp;
    while((cin >> temp) != NULL){
        //temp = str_to_long(current_num);
        if(current_pos % 2 == 1){
            (min > temp) ? min = temp : min = min;
        } else {
            (max < temp) ? max = temp : max = max;
        }
        current_pos++;
    }
    cout << min + max << endl;

    return 0;
}

long str_to_long(char *s){
    long temp = 0;
    for(int i = 0; i < strlen(s); i++){
            temp = 10 * temp + (long) s[i] - 48;
    }
    return (s[0] == '-') ? -(temp - 45) - 75 : temp;
}

