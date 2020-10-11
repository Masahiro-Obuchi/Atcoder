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
  ll n, x;
  cin >> n >> x;
  vector<ll> a(n);
  for (auto &it : a)
    cin >> it;
  sort(a.begin(), a.end(), greater<ll>());
  int ans = 0;
  ll now = INF;
  ll nowCnt = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] >= x)
    {
      ans++;
    }
    else
    {
      now = min(now, a[i]);
      nowCnt++;
      if (now * nowCnt >= x)
      {
        ans++;
        now = INF;
        nowCnt = 0;
      }
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
