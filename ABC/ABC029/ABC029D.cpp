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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string N;
  cin >> N;
  int l = N.size();
  static ll dp[12][2][12];
  dp[0][0][0] = 1;
  for (int i = 0; i < l; i++)
  {
    const int D = N[i] - '0';
    for (int j = 0; j < 2; j++)
    {
      for (int k = 0; k < 12; k++)
      {
        for (int d = 0; d <= (j ? 9 : D); d++)
        {
          if (d == 1)
          {
            dp[i + 1][j || (d < D)][k + 1] += dp[i][j][k];
          }
          else
          {
            dp[i + 1][j || (d < D)][k] += dp[i][j][k];
          }
        }
      }
    }
  }
  ll ans = 0;
  for (int i = 1; i <= l; i++)
  {
    ans += (dp[l][0][i] + dp[l][1][i]) * i;
  }
  cout << ans << endl;
  return 0;
}

// 今までに1が出た個数も保持する．ansの計算をするときにdp[][][1が出た数]*(1が出た数)を足しこんでいく．
