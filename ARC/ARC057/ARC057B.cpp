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
  int N;
  cin >> N;
  ll K;
  cin >> K;
  vector<ll> a(N);
  for (auto &it : a)
    cin >> it;
  vector<vector<ll>> dp(N + 10, vector<ll>(N + 10, INF));
  vector<ll> sum(N + 1, 0);
  for (int i = 0; i < N; i++)
    sum[i + 1] = sum[i] + a[i];
  if (sum[N] == K)
  {
    cout << 1 << endl;
    return 0;
  }
  dp[0][0] = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      if (dp[i][j] < INF)
      {
        // 勝たない->機嫌がよくなることはない
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
        // 勝つ
        if (i == 0)
        {
          // 1回でも勝てばよい
          dp[i + 1][j + 1] = min(dp[i][j] + 1, dp[i + 1][j + 1]);
        }
        else
        {
          ll x = (ll)dp[i][j] * sum[i + 1] / sum[i] + 1; // x > dp[i][j]/sum[i] * sum[i + 1] 掛け算を先にする．
          if (x <= a[i] + dp[i][j])
            dp[i + 1][j + 1] = min(x, dp[i + 1][j + 1]);
        }
      }
    }
  }
  ll res = 0;
  for (int i = 0; i <= N; i++)
  {
    cerr << dp[N][i] << endl;
    if (dp[N][i] <= K)
      res = i;
  } // K勝ったとK回以下勝ったは同じ
  cout << res << endl;
  return 0;
}

// Kが大きいからdp[i + 1][j] := i日目までに機嫌が良かった日数がj日になったときのゲームに勝った回数の最小値と定義する．
// dp遷移
// i日目を機嫌を良くしないとすると全敗するのが最適
// i日目を機嫌を良くするとすると最低限勝つのが最適
// sum = a1 + a2 + a3 + ... + anとする．K < sumのときK回勝ったとはK回以下勝ったと同じであることを示す．L < K回勝った場合を考える．このとき，残りのK - L回の勝つ日を上手く選べば機嫌の良い日が同じかそれ以上になることを示せばよい．N日間を後ろから見ていきその日が全勝ではないなら残り勝ち数がなくなるかその日が全勝になるまで勝ち数を増やす．このようにすると，x日目以前では機嫌の良い日の日数は変わらない．x + 1日目以降は全勝しているので勝率は上昇しているので機嫌がよかったのに悪くなることはない．また，x日目の勝率は上がるのでx日目に機嫌が悪くなったのが良くなることはあってもその逆はない．以上により機嫌の良い日は多くなることはあっても少なくなることはない．以上により，K回勝ったはK回以下勝ったに言い換えることが出来る．
