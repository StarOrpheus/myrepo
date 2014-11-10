#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

size_t strl (const char* str)
{
   size_t result = 0;
   while (str[result] != '\0')
   {
      ++result;
   }
   return result;
}



int main()
{
    //int BUF_SIZE = 256;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char s[256];
    memset((void *) s, '\0', sizeof(s));
    int cur = 0, c;
    while((c = getchar()) != EOF){
        s[cur] = c;
        cur++;
    }
    long max = -1;
    for(int i = 0; i < strl(s); i++){
        if(s[i] > max){
            max = s[i];
        }
        if((s[i] >= 48 && s[i] <= 57) || (s[i] >= 65 && s[i] <= 90)){}
        else {
           cout << -1 << endl;
           return 0;
        }
    }
    if(max == 48){
        cout << 2 << endl;
        exit(EXIT_SUCCESS);
    }
    if((max > 48 && max <= 57) || (max >= 65 && max <= 90)){
        if(max > 48 && max <= 57){
            cout << max - 47 << endl;
        } else {
            cout << max - 54 << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}

