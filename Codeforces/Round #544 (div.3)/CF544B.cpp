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
  ll n, k;
  cin >> n >> k;
  vector<ll> d(n);
  for (auto &it : d)
    cin >> it;
  map<ll, ll> cnt;
  for (int i = 0; i < n; i++)
  {
    cnt[d[i] % k]++;
  }

  ll ans = 0;
  for (int i = 0; i < k / 2 + 1; i++)
  {
    // cerr << min(cnt[i], cnt[k - i]) << endl;
    if (i % k == (k - i) % k)
    {
      ans += cnt[i] / 2;
    }
    else
    {
      ans += min(cnt[i], cnt[k - i]);
    }
  }
  ans *= 2;
  cout << ans << endl;
  return;
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
