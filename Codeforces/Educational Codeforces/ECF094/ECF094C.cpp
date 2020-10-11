#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
struct Edge
{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
// using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

void solve()
{
  string s;
  cin >> s;
  int n = s.size();
  int x;
  cin >> x;
  string w;
  for (int i = 0; i < n; i++)
    w += '1';

  for (int i = 0; i < n; i++)
  {
    if (s[i] == '0')
    {
      if (i >= x)
        w[i - x] = '0';
      if (i + x < n)
        w[i + x] = '0';
    }
  }

  for (int i = 0; i < n; i++)
  {
    bool one = false;
    one = one || (i >= x && w[i - x] == '1');
    one = one || (i + x < n && w[i + x] == '1');

    if ((s[i] == '1' && !one) || (s[i] == '0' && one))
    {
      cout << -1 << endl;
      return;
    }
  }

  cout << w << endl;
}

// si=0ということはwi-xとwi+xが存在するが両方とも0，またはwi-xとwi+xが共に存在しない wi-xが0 wi+xが存在しない　wi-xが存在しない wi+xが0
// 0と1で分けて考える事が重要？
// Note that si=1 means "either wi−x=1 or wi+x=1," whereas si=0 means "both wi−x=0 and wi+x=0." We can greedily solve this by starting out our string w with all 1's, then marking i−x and i+x as 0 whenever we are forced to because si=0. Then we can simply check whether all of the si=1 conditions are valid to confirm.

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    solve();
  }
  return 0;
}
