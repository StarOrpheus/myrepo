#include <string>
#include <iostream>

using namespace std;

string getbin(const int dec)
{

    union cl
    {
#pragma pack(push, 1)
        struct bts
        {
            unsigned b0:        1;
            unsigned b1:        1;
            unsigned b2:        1;
            unsigned b3:        1;
            unsigned b4:        1;
            unsigned b5:        1;
            unsigned b6:        1;
            unsigned b7:        1;
        };
#pragma pack(pop)
        int     a;
        bts     bt[4];
        char    fl[4];
    };
    // cerr << sizeof(cl) << endl;
    cl temp;
    temp.a = abs(dec);
    if(dec == 0)
        return "00000000";
    int bc = 3;
    while(temp.fl[bc] == 0)
        bc--;
    string ans;
    ans.reserve(32);
    for(int i = bc; i >= 0; i--)
    {
        ans += temp.bt[i].b7 + '0';
        ans += temp.bt[i].b6 + '0';
        ans += temp.bt[i].b5 + '0';
        ans += temp.bt[i].b4 + '0';
        ans += temp.bt[i].b3 + '0';
        ans += temp.bt[i].b2 + '0';
        ans += temp.bt[i].b1 + '0';
        ans += temp.bt[i].b0 + '0';
    }
    return ans;
}