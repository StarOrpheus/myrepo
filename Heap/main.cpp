#include <iostream>
#include <vector>
using namespace std;

struct __attribute__((packed))  el{
    int n, k;
};

vector<long> h;
int n;
    void inline __attribute__((always_inline)) siftUp(int i)
    {
        long x;
        while(i > 1 && h[i] < h[i / 2])
        {
            x = h[i];
            h[i] = h[i / 2];
            h[i / 2] = x;
            i /= 2;
        }
    }
    void inline __attribute__((always_inline)) siftDown(int i)
    {
        int j, x;
        while(2 * i <= n)
        {
            j = i;
            if(h[2 * i] < h[j])
                j = 2 * i;
            if(2 * i + 1 <= n && h[2 * i + 1] < h[j])
                j = 2 * i + 1;
            if(i == j)
                break;
            x = h[i]; h[i] = h[j]; h[j] = x;
            i = j;
        }
    }

int main()
{
    freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
    cin >> n;
    //heap h(n);
    h.push_back(-1);
    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        h.push_back(t);
    }
    for(int i = 1; i <= n; i++)
    {
        siftDown(i);
    }
    for(int i = 1; i <= n; i++)
        cout << h[i] << " ";
    cout << endl;
    return 0;
}

