#include <iostream>
#include <cstdio>
#include <ios>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <iomanip>
#include <cmath>

#define F first
#define S second
#define X first
#define Y second
#define pb push_back
#define mp make_pair

using namespace std;

const int INF = 1000000000; // 10^9
const long long llINF = 10000000000000000ll; // 10^16
const int SWAG = 228;
const int LEET = 1337;

//                  N  E  S   W  NE SE  SW  NW
const int sx[8] = {-1, 0, 1,  0, -1, 1,  1. -1};
const int sy[8] = { 0, 1, 0, -1,  1, 1, -1, -1};

char let[100][100];
int n, m;

int check(int x, int y, char M, char O)
{
  int res = 0;
  if (x > 1)
    if (let[x][y] == M && let[x - 1][y] == O && let[x - 2][y] == O)
      res++;
  if (x > 1 && y > 1)
    if (let[x][y] == M && let[x - 1][y - 1] == O && let[x - 2][y - 2] == O)
      res++;
  if (y > 1)
    if (let[x][y] == M && let[x][y - 1] == O && let[x][y - 2] == O)
      res++;
  if (x < n - 2)
    if (let[x][y] == M && let[x + 1][y] == O && let[x + 2][y] == O)
      res++;
  if (x < n - 2 && y < m - 2)
    if (let[x][y] == M && let[x + 1][y + 1] == O && let[x + 2][y + 2] == O)
      res++;
  if (y < m - 2)
    if (let[x][y] == M && let[x][y + 1] == O && let[x][y + 2] == O)
      res++;
  if (x > 1 && y < m - 2)
    if (let[x][y] == M && let[x - 1][y + 1] == O && let[x - 2][y + 2] == O)
      res++;
  if (x < n - 2 && y > 1)
    if (let[x][y] == M && let[x + 1][y - 1] == O && let[x + 2][y - 2] == O)
      res++;
  return res;
}

int main()
{
#ifdef LOCAL
  freopen("task.in", "r", stdin);
  freopen("task.out", "w", stdout);
  #define debug(...) printft__VA_ARGS__)
#else
  freopen("moocrypt.in", "r", stdin);
  freopen("moocrypt.out", "w", stdout);
  #define debug(...)
#endif //LOCAL
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> let[i][j];

  int ans = 0;

  for (int i = 0; i < 26; ++i)
    for (int j = 0; j < 26; ++j)
    {
      int interAns = 0;
      char M = i + 'A', O = j + 'A';
      if (i == j || M == 'M' || O == 'O')
        continue;
//      cout << M << " " << O << endl;

      for (int x = 0; x < n; ++x)
        for (int y = 0; y < m; ++y)
          interAns += check(x, y, M, O);
//      cout << interAns << endl << endl;
      ans = max(ans, interAns);
    }

  cout << ans;
  return 0;
}
