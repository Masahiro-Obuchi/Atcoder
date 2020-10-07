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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  while (1)
  {
    cin >> n;
    if (n == 0)
      break;
    vector<int> w(n);
    for (auto &it : w)
      cin >> it;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    for (int W = 2; W <= n; W++)
    {
      // left
      for (int l = 0; l < n; l++)
      {
        int r = l + W;
        if (r > n)
          continue;
        if (dp[l + 1][r - 1] == W - 2 && abs(w[l] - w[r - 1]) <= 1)
          dp[l][r] = W;

        for (int mid = l; mid <= r; mid++)
        {
          dp[l][r] = max(dp[l][r], dp[l][mid] + dp[mid][r]);
        }
      }
    }
    ll ans = dp[0][n];
    cout << ans << endl;
  }
  return 0;
}

// 区間DP dp[l][r]:=区間[l, r)で取り除くことの出来るブロックの数
// 2つのパターンが存在する．1. lのブロックとr-1のブロックが対になれる．2. [l, mid)と[mid,r)に区間を分ける．
// 1を満たすのは... w[l]とw[r-1]の差が1. または[l+1, r-1)が完全に取り除ける．-> dp[l + 1][r - 1]がr - l - 2という条件にあたる．
// 2を満たすのは　左側で取り除けた量 + 右側で取り除けた量　dp[l][r]=dp[l][mid] + dp[mid][r]　ボトムアップ
