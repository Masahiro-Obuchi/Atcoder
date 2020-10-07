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
  vector<ll> w(N);
  for (auto &it : w)
    cin >> it;

  vector<ll> sum(N + 1);
  for (int i = 0; i < N; i++)
    sum[i + 1] = sum[i] + w[i]; // [l, r)

  vector<vector<ll>> dp(N + 10, vector<ll>(N + 10));
  vector<vector<ll>> K(N + 10, vector<ll>(N + 10));

  for (int i = 0; i < N; i++)
    K[i][i] = i;

  for (int w = 1; w <= N; w++)
  {
    for (int i = 0; i < N; i++)
    {
      int j = i + w;
      if (j >= N)
        continue;
      int a = K[i][j - 1];
      int b = K[i + 1][j];
      ll m = INF;
      ll idx = -1;
      for (int l = a; l <= b; l++)
      {
        if (i > l || l >= j)
          continue;
        ll now = dp[i][l] + dp[l + 1][j];
        if (now <= m)
        {
          idx = l;
          m = now;
        }
      }
      dp[i][j] = m + sum[j + 1] - sum[i];
      K[i][j] = idx;
    }
  }
  cout << dp[0][N - 1] << endl;
  return 0;
}

// まず累積和を計算してその区間のコストをすぐ計算できるようにしておく
// dp[左端][右端]:=その部分を全て1cmにするときのコストとする．すでに1cmのときはコスト0であるからdp[i][i] = 0 区間[i, j]を[i, r]と[r + 1, j]に切る時はdp[i][j] = min(dp[i][r] + dp[r + 1][j] + cost[i][j]) となる．このままだとO(N^3)で通らないがcost[i][j]にはMonge性があってO(N^2)に落ちる．K[i][j] = argmin(dp[i][r] + dp[r + 1][j])とするとdp[i][j] = {min(dp[i][j] + dp[r + 1][j]) | K[i][j - 1] <= r <= K[i + 1][j]}
