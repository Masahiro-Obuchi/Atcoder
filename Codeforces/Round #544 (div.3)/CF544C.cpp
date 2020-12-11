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
  map<ll, ll> cnt;
  for (int i = 0; i < n; i++)
  {
    cnt[a[i]]++;
  }

  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= 5; j++)
    {
      ll tmp = 0;
      for (int k = 0; k <= 5; k++)
      {
        if (j == k)
        {
          tmp += cnt[a[i]];
        }
        else
        {
          tmp += cnt[a[i] + k - j];
        }
      }
      ans = max(ans, tmp);
    }
  }
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
