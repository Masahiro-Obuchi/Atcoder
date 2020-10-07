#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

// Graph
struct Edge
{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
// using Graph = vector<vector<int>>;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N, W;
  cin >> N >> W;
  vector<ll> v(N), w(N);
  for (int i = 0; i < N; i++)
    cin >> v[i] >> w[i];
  if (N <= 30)
  {
    int n = N / 2; // まず2つに分ける
    vector<pair<ll, ll>> A;
    for (int bit = 0; bit < (1 << n); bit++)
    {
      ll valueSum = 0, weightSum = 0;
      for (int i = 0; i < n; i++)
      {
        if (bit & (1 << i))
        {
          valueSum += v[i], weightSum += w[i];
        }
      }
      A.push_back(make_pair(weightSum, valueSum)); // 重み優先
    }
    sort(A.begin(), A.end());
    for (int i = 1; i < A.size(); i++)
    {
      if (A[i].first > A[i - 1].first && A[i].second < A[i - 1].second)
        A[i].second = A[i - 1].second;
    } // 境界となる重さ以下となる荷物の最大価値を求められるようにするため
    vector<pair<ll, ll>> B;
    for (int bit = 0; bit < (1 << N - n); bit++)
    {
      ll valueSum = 0, weightSum = 0;
      for (int i = 0; i < N - n; i++)
      {
        if (bit & (1 << i))
        {
          valueSum += v[n + i], weightSum += w[n + i];
        }
      }
      B.push_back(make_pair(weightSum, valueSum));
    }
    ll ans = 0;
    for (int i = 0; i < B.size(); i++)
    {
      int idx = upper_bound(A.begin(), A.end(), make_pair(W - B[i].first, INF)) - A.begin();
      if (idx == 0)
        continue;
      else
        ans = max(ans, A[idx - 1].second + B[i].second);
    }
    cout << ans << endl;
  }
  else
  {
    bool flag = true;
    for (int i = 0; i < N; i++)
      if (w[i] > 1000)
        flag = false;
    if (flag)
    {
      // i番目までの品物から重さの総和がj以下となるように選んだ時の価値の総和の最大値
      vector<vector<ll>> dp(N + 1, vector<ll>(W + 1));
      for (int i = 0; i < N; i++)
      {
        for (int j = 0; j <= W; j++)
        {
          if (j < w[i])
            dp[i + 1][j] = dp[i][j];
          else
          {
            dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
          }
        }
      }
      cout << dp[N][W] << endl;
    }
    else
    {
      // 価値が1000以下
      // dp[i + 1][j]:=i番目までの品物から価値の総和がjとなるように選んだ時の重さの総和の最小値と定義する
      vector<vector<ll>> dp(N + 1, vector<ll>(200010, INF));
      dp[0][0] = 0;
      for (int i = 0; i < N; i++)
      {
        for (int j = 0; j <= 200005; j++)
        {
          if (j < v[i])
            dp[i + 1][j] = dp[i][j];
          else
            dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
        }
      }
      ll res = 0;
      for (int i = 0; i <= 200005; i++)
        if (dp[N][i] <= W)
          res = i;
      cout << res << endl;
    }
  }
  return 0;
}

// 半分全列挙　価値と重さの入れ替え
