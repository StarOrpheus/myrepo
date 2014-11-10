#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    char mas[4];
    int c;
    char mas2[4];
    mas[0] = getchar();
    mas[1] = getchar();
    mas[2] = getchar();
    mas[3] = getchar();
    getchar();
    mas2[0] = getchar();
    mas2[1] = getchar();
    mas2[2] = getchar();
    mas2[3] = getchar();
    int b,k;
    b = 0;
    k = 0;
    for(int i = 0; i < 4; i++){
        if(mas[i] == mas2[i]){
            b++;
        }
        for(int j = 0; j < 4; j++){
            if(mas[i] == mas2[j] && i != j){
                k++;
            }
        }
    }
    printf("%ld %ld", b, k);

}
