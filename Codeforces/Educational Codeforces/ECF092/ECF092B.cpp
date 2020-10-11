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
// using Graph = vector<vector<Edge>>;
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

void solve()
{
  int n, k, z;
  cin >> n >> k >> z;
  vector<int> a(n);
  for (auto &it : a)
    cin >> it;
  int ans = 0;
  int sum = 0;
  int mx = 0;
  for (int t = 0; t <= z; t++)
  {
    int pos = k - 2 * t;
    if (pos < 0)
      continue;
    mx = 0;
    sum = 0;
    for (int i = 0; i <= pos; i++)
    {
      if (i < n - 1)
      {
        mx = max(mx, a[i] + a[i + 1]);
      }
      sum += a[i];
    }
    ans = max(ans, sum + mx * t);
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
