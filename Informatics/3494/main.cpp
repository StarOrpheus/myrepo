#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cstring>
#include <list>
#include <queue>
using namespace std;

struct edge{
    unsigned int     v;      // Куда
    unsigned int     len;    // Длина
    edge(){}
    edge(int _v, int _len)
    {
        v = _v; len = _len;
    }
};

struct  v_data{
    unsigned int     v;      // Номер вершины
    unsigned int     est;    // Оценочное расстояние
    v_data(){}
    v_data(int _v, int _est){
        v = _v; est = _est;
    }
};

bool operator<(v_data a, v_data b)
{
    return a.est > b.est;
}

enum stat{
    CHECKED = 0,
    ON_WORK = 1
};

#define INF 2009000999

int main()
{
    int sdfsdf;
    cin >> sdfsdf;
    for(int sfa = 0; sfa < sdfsdf; sfa++)
    {
        int n, m, s;
        cin >> n >> m;
        vector<vector<edge> > g(n+1);
        vector<stat> st(n+1, ON_WORK);
        int _s, _f, _len;
        for(int i = 0; i < m; i++)
        {
            cin >> _s >> _f >> _len;
            g[_s+1].push_back(edge(_f+1, _len));
            g[_f+1].push_back(edge(_s+1, _len));
        }
        cin >> s;
        s++;
        priority_queue<v_data> f;
        vector<int> d(n+1, INF);

        d[s] = 0;
        f.push(v_data(s, 0));
        while(!f.empty())
        {
            while(!f.empty() && (st[f.top().v] == CHECKED || d[f.top().v] != f.top().est))
                f.pop();
            if(f.empty())
            {
                continue;
            }
            int temp = f.top().v;
            st[temp] = CHECKED;
            //cout << temp << endl;
            f.pop();
            for(int i = 0; i < g[temp].size(); i++)
            {
                int to = g[temp][i].v;
                if(st[to] == ON_WORK && d[temp] + g[temp][i].len < d[to])
                {
                    d[to] = d[temp] + g[temp][i].len;
                    f.push(v_data(to, d[to]));
                }
            }
        }
        for(int i = 1; i <= n; i++)
        {
            cout << d[i] << " ";
        }
        cout << endl;
    }
    return 0;
}