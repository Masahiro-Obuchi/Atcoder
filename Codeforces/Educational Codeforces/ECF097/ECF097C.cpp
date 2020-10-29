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
  vector<int> t(n);
  for (auto &it : t)
  {
    cin >> it;
    it--;
  }
  sort(t.begin(), t.end());

  vector<vector<ll>> dp(n + 1, vector<ll>(2 * n, INT_INF));

  dp[0][0] = 0;
  for (int i = 0; i < n + 1; i++)
  {
    for (int j = 0; j < 2 * n - 1; j++)
    {
      if (dp[i][j] < INT_INF)
      {
        if (i < n)
          dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(j - t[i]));
        dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
      }
    }
  }

  cout << dp[n][2 * n - 1] << endl;
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
