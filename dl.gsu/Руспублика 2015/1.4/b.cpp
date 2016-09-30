#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <Rescue.h>


using namespace std;
//using namespace __gnu_pbds;


#define INF (1<<30)
#define INFll (1ll<<62)
#define F first
#define S second
#define MOD 1000000007
#define mkp(a, b) make_pair(a, b)


typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


#define FOR(I, A, B) for(int (I) = (A); (I) < (B); (I)++)
#define ROF(I, A, B) for(int (I) = (A); (I) >= (B); (I)--)
#define SQR(A) 1ll*(A)*(A)


//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


const char array_sep[] = " ";
const char array_end[] = "";


const char pair_sep[] = " ";
const char pair_end[] = "";


const char map_sep[] = "->";
const char map_end[] = "\n";


const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int ddx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int ddy[] = {0, 1, 1, 1, 0, -1, -1, -1};


template<typename A> ostream & operator<<(ostream & os, const vector<A> & x)
{
	for(int i = 0; i < x.size(); i++)
		os << x[i] << array_sep;
	os << array_end;
	return os;
}


template<typename A, typename B> ostream & operator<<(ostream & os, const pair<A, B> & x)
{
	os << x.first << pair_sep << x.second << pair_end;
	return os;
}


template<typename A> istream & operator>>(istream & is, vector<A> & x)
{
	for(int i = 0; i < x.size(); i++)
		is >> x[i];
	return is;
}


template<typename A, typename B> istream & operator>>(istream & is, pair<A, B> & x)
{
	is >> x.first >> x.second;
	return is;
}


//template<typename _key, typename _val> ostream & operator<<(ostream & os, map<_key, _val> & mp)
//{
//	for(auto it : mp)   // not for C++98 or earlier
//		os << it->F << map_sep << it->S << map_end;
//	return os;
//}


template<typename _response> void die(_response ans)
{
	cout << ans << endl;
	exit(0);
}

long int n, k;
vector<vector<int > > g;
vector<bool > used;
vector<int > sz;

namespace {
    const char* INPUT_FILE = "input.txt";
    const char* OUTPUT_FILE = "output.txt";
    const long CLOSER_LIMIT = 50;
    const bool DEBUG_OUTPUT = true;

    typedef std::pair<long, long> _TEdge;

    enum _TState {
        _UNKNOWN,
        _INIT,
        _GET_ROUTE,
        _IS_CLOSER,
        _LOCATE
    };
    _TState _state = _UNKNOWN;

    std::vector<_TEdge> _edges;
    std::vector<long> _queries;
    FILE* _fout = NULL;
    long _n, _k, _m;
    long _ei, _qi;

    void _msg(const char* format, ...) {
        if (_fout != NULL && DEBUG_OUTPUT) {
            va_list args;
            va_start(args, format);
            vfprintf(_fout, format, args);
            va_end(args);
            fprintf(_fout, "\n");
        }
    }

    int _exit(const char* verdict) {
        if (_fout) {
            fprintf(_fout, "%s\n", verdict);
            fclose(_fout);
            _fout = NULL;
        }
        exit(0);
    }

    int _ok() {
        return _exit("OK");
    }

    int _pe() {
        return _exit("PE");
    }

    int _wa() {
        return _exit("WA");
    }

    std::vector < std::vector<int> > _e;
    std::vector <int> _deep;
    std::vector <int> _seq;
    std::vector <int> _first;
    std::vector <int> _lg;
    std::vector < std::vector<int> > _st;

    void _dfs(const int x, const int p, const int d) {
        _deep[x] = d;
        _first[x] = _seq.size();
        _seq.push_back(_deep[x]);
        for (size_t i = 0; i < _e[x].size(); ++i) {
            int y = _e[x][i];
            if (y == p) {
                continue;
            }
            _dfs(y, x, d + 1);
            _seq.push_back(_deep[x]);
        }
    }

    void _sparse_table() {
        int n = _seq.size();
        _lg.resize(n + 1);
        _lg[1] = 0;
        for (int i = 2; i <= n; ++i) {
            _lg[i] = _lg[i >> 1] + 1;
        }
        _st.resize(_lg[n] + 1);
        _st[0].resize(n);
        for (int i = 0; i < n; ++i) {
            _st[0][i] = _seq[i];
        }
        for (int i = 1; i <= _lg[n]; ++i) {
            _st[i].resize(n - (1 << i) + 1);
            for (size_t j = 0; j < _st[i].size(); ++j) {
                _st[i][j] = std::min(_st[i - 1][j], _st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int _distance(const int a, const int b) {
        int l = _first[a - 1];
        int r = _first[b - 1];
        if (l > r) {
            std::swap(l, r);
        }
        int t = _lg[r - l + 1];
        return _deep[a - 1] + _deep[b - 1] - 2 * std::min(_st[t][l], _st[t][r - (1 << t) + 1]);
    }
}

void Init(long& N, long& K) {
    _state == _UNKNOWN || _pe();
    _fout = fopen(OUTPUT_FILE, "w");

    FILE* fin = fopen(INPUT_FILE, "r");
    fin || _pe();

    fscanf(fin, "%ld %ld", &_n, &_k) == 2 || _pe();

    _e.resize(_n);
    _deep.resize(_n);
    _first.resize(_n);

    _edges.resize(_n - 1);
    for (int i = 0; i < _n - 1; ++i) {
        long a, b;
        fscanf(fin, "%ld %ld", &a, &b) == 2 || _pe();
        _edges[i] = _TEdge(a, b);
        a -= 1;
        b -= 1;
        _e[a].push_back(b);
        _e[b].push_back(a);
    }
    _queries.resize(_k);
    for (int i = 0; i < _k; ++i) {
        fscanf(fin, "%ld", &_queries[i]) == 1 || _pe();
    }
    fclose(fin);

    _dfs(0, 0, 0);
    _sparse_table();

    _ei = 0;
    _qi = 0;
    _m = 0;
    N = _n;
    K = _k;
    _msg("Init(%ld, %ld)", N, K);
    _state = _INIT;
}

void GetRoute(long& X, long& Y) {
    _state == _UNKNOWN && _pe();
    _ei < _n - 1 || _pe();

    X = _edges[_ei].first;
    Y = _edges[_ei].second;
    ++_ei;
    _msg("GetRoute(%ld, %ld)", X, Y);
    _state = _GET_ROUTE;
}

bool IsCloser(long X, long Y) {
    _state == _UNKNOWN && _pe();
    _ei == _n - 1 || _pe();

    (1 <= X && X <= _n) || _pe();
    (1 <= Y && Y <= _n) || _pe();

    ++_m;
    _m <= CLOSER_LIMIT || _pe();

    bool result = _distance(_queries[_qi], X) < _distance(_queries[_qi], Y);
    _msg("IsCloser(%ld, %ld) = %s", X, Y, result? "TRUE" : "FALSE");
    _state = _IS_CLOSER;
    return result;
}

void Locate(long P) {
    _state == _UNKNOWN && _pe();
    _ei == _n - 1 || _pe();

    _msg("Locate(%d)", P);
    _queries[_qi] == P || _wa();
    ++_qi;
    _qi == _k && _ok();
    _m = 0;
    _state = _LOCATE;
}


int calc_size(int v, int p = -1)
{
    sz[v] = 1;
    for(int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if(to != p && !used[to])
            sz[v] += calc_size(to, v);
    }
    return sz[v];
}

bool comp(int a, int b)
{
    return IsCloser(a+1, b+1);
//    return b > a;
}

vector<vector<pair<int, int > > > centroid;

int calc_centroids(int u)
{
    int N = calc_size(u);
//    cerr << "#-# " << u << ' ';


    int v = u;
    int p = -1;
    while(true)
    {
//        cerr << "." << endl;
        bool sep = true;
        for(int i = 0; i < g[v].size(); i++)
        {
            int to = g[v][i];
            if(to != p && !used[to] && sz[to] >= N/2)
            {
                sep = false;
                p = v;
                v = to;
                break;
            }
        }
        if(sep) break;
    }

    if(u == 0)
        v = 0;

    used[v] = true;
//    cerr << v << endl;

    for(int to: g[v])
        if(!used[to])
            centroid[v].push_back(mkp(to, calc_centroids(to)));
    return v;
}

void solve(int u)
{
    used[u] = true;
//    cerr << "# V = " << (u+1) << endl;

    vector<pair<int, int > > children;

    for(int i = 0; i < centroid[u].size(); i++)
    {
        auto to = centroid[u][i];
//        int centr = centroid[u][i].S;

        if(!used[to.F])
            children.push_back(to);
    }
//
//    for(auto& x: children)
//        cerr << x.F+1 << ' ';
//    cerr << endl;

    if(children.size() == 0)
    {
        Locate(u+1);
        return;
    }

    if(children.size() == 1)
    {
        if(IsCloser(children[0].F + 1, u+1))
            solve(children[0].S);
        else
            Locate(u+1);
        return;
    }

    if(children.size() == 2)
    {
        if(IsCloser(children[0].F + 1, children[1].F + 1))
        {
            solve(children[0].S);
            return;
        }

        if(IsCloser(children[1].F + 1, u+1))
        {
            solve(children[1].S);
            return;
        }

        Locate(u+1);
        return;
    }

    // ДОПИСАТЬ!1-!

    // Children count == 3

    if(IsCloser(children[0].F + 1, children[1].F + 1))
    {
        solve(children[0].S);
        return;
    }

    if(IsCloser(children[1].F + 1, children[2].F + 1))
    {
        solve(children[1].S);
        return;
    }

    if(IsCloser(children[2].F + 1, u + 1))
    {
        solve(children[2].S);
        return;
    }

    Locate(u+1);
}


int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	freopen("errlog.log", "w", stderr);
	ios_base::sync_with_stdio(0);
//	cout << fixed << setprecision(3);

    Init(n, k);

    g.resize(n);
    used.resize(n, false);
    sz.resize(n);
    centroid.resize(n);

    for(int i = 0; i < n-1; i++)
    {
        long int a, b;
        GetRoute(a, b);
        a--, b--;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    used.assign(n, false);
    calc_centroids(0);
//    for(int i = 0; i < n; i++)
//    {
//        cerr << (i+1) << ": \n";
//        for(auto& p: centroid[i])
//            cerr << "\t#"<<  p.F + 1 << " " << p.S + 1 << endl;
//    }
//    exit(0);

    while(k--)
    {
        used.assign(n, false);
        solve(0);
    }

	return 0;
}
