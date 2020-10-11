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
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &it : a)
    cin >> it;

  sort(a.begin(), a.end(), greater<ll>());
  for (int i = 1; i <= k; i++)
  {
    if (k > n - 1)
      break;
    a[0] += a[i];
    a[i] = 0;
  }

  ll mx = 0, mn = INF;
  for (auto it : a)
  {
    mx = max(mx, it);
    mn = min(mn, it);
  }
  cout << mx - mn << endl;
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
