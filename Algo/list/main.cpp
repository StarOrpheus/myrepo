#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <queue>
#include <locale>
#include <deque>

using namespace std;

#define INF (1 << 30)
#define F first
#define S second


#define MOD 1000000007
#define MODLL 1000000007LL

struct vertex
{
    vertex* next;
    int a;
    vertex(){
        next = NULL;
        a = 0;
    }
};

void add(vertex *v, int n)
{
    if(v->next == NULL)
    {
        v->next         = new vertex;
        v->next->a      = n;
        return;
    }
    add(v->next, n);
}

void printv(vertex* v)
{
    printf("%ld ", v->a);
    if(v->next == NULL)
        return;
    printv(v->next);
}


int main() {
//    freopen("adding.in", "r", stdin);
//    freopen("adding.out", "w", stdout);
    vertex root;
    int n;
    cin >> n;
    n--;
    if(n < 0)
        exit(EXIT_SUCCESS);
//    scanf("%ld ", &root.a);
//    vertex* temp;
//    temp = &root;
    cin >> root.a;
    printv(&root);
    putchar('\n');
    for(int i = 0; i < n; i++)
    {
        int x;
//        scanf("%ld", &x);
        cin >> x;
        add(&root, x);
//        temp = temp->next;
        printv(&root);
        putchar('\n');
    }
    return 0;
}