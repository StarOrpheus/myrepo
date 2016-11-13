#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

class flagParser
{
private:
    union
    {
        unsigned char dec;
#pragma pack(push, 1)
        struct
        {
            unsigned f0: 1;
            unsigned f1: 1;
            unsigned f2: 1;
            unsigned f3: 1;
            unsigned f4: 1;
            unsigned f5: 1;
            unsigned f6: 1;
            unsigned f7: 1;
        } bts;
#pragma pack(pop)
    } inf;
public:
    flagParser() {}
    flagParser(const unsigned char x)
    {
        inf.dec = x;
    }
    inline vector<bool> getStateArray()
    {
        vector<bool> state(8);
        state[0] = inf.bts.f0;
        state[1] = inf.bts.f1;
        state[2] = inf.bts.f2;
        state[3] = inf.bts.f3;
        state[4] = inf.bts.f4;
        state[5] = inf.bts.f5;
        state[6] = inf.bts.f6;
        state[7] = inf.bts.f7;
        return state;
    }

    inline vector<bool> getStateArray(int x)
    {
        inf.dec = x;
        return getStateArray();
    }
};

void printBool(const bool x, const char* end)
{
    if(x)
        printf("True");
    else
        printf("False");
    printf(end);
}
