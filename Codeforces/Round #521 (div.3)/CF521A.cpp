#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
/*
struct Edge
{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
*/
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

void solve()
{
  ll a, b, k;
  cin >> a >> b >> k;
  ll ans = 0;
  if (k % 2 == 0)
  {
    if (a >= b)
    {
      ans += k / 2 * (a - b);
    }
    else
    {
      ans -= k / 2 * (b - a);
    }
  }
  else
  {
    if (a >= b)
    {
      ans += (k - 1) / 2 * (a - b) + a;
    }
    else
    {
      ans -= (k - 1) / 2 * (b - a);
      ans += a;
    }
  }
  cout << ans << endl;
}

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
