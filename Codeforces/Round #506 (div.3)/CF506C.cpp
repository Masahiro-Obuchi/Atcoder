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
  int n;
  cin >> n;
  vector<pair<ll, ll>> lr(n);
  for (int i = 0; i < n; i++)
    cin >> lr[i].first >> lr[i].second;

  ll res1 = 0, res2 = 0;
  sort(lr.begin(), lr.end(), greater<pair<ll, ll>>());
  ll left = 0, right = INF;
  for (int i = 1; i < n; i++)
  {
    left = max(left, lr[i].first), right = min(right, lr[i].second);
  }
  res1 = right - left;

  for (int i = 0; i < n; i++)
  {
    swap(lr[i].first, lr[i].second);
  }
  sort(lr.begin(), lr.end());
  left = 0, right = INF;
  for (int i = 1; i < n; i++)
  {
    left = max(left, lr[i].second), right = min(right, lr[i].first);
  }
  res2 = right - left;
  ll ans = max(0LL, max(res1, res2));
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  t = 1;
  for (int i = 0; i < t; i++)
  {
    solve();
  }
  return 0;
}
