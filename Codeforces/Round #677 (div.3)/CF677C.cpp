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
  vector<ll> a(n);
  for (auto &it : a)
    cin >> it;

  bool can = false;
  ll maxv = 0;
  for (int i = 0; i < n; i++)
  {
    maxv = max(maxv, a[i]);
    if (a[i] != a[0])
    {
      can = true;
    }
  }

  vector<int> idxs;
  for (int i = 0; i < n; i++)
  {
    if (a[i] == maxv)
      idxs.push_back(i);
  }

  int ans = -1;
  for (auto it : idxs)
  {
    if (it == 0 && a[it + 1] < maxv)
    {
      ans = it;
      break;
    }
    else if (it == n - 1 && a[it - 1] < maxv)
    {
      ans = it;
      break;
    }
    else if (a[it - 1] < maxv || a[it + 1] < maxv)
    {
      ans = it;
      break;
    }
  }
  if (!can || ans == -1)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << ans + 1 << endl;
  }
  return;
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
