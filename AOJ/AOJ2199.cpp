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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  while (true)
  {
    cin >> N >> M;
    if (N == 0 && M == 0)
      break;

    vector<ll> C(M);
    for (auto &it : C)
      cin >> it;
    vector<ll> Y(N);
    for (auto &it : Y)
      cin >> it;

    vector<vector<ll>> dp(N + 1, vector<ll>(256, INF));
    dp[0][128] = 0;
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j <= 255; j++)
      {
        for (int k = 0; k < M; k++)
        {
          int yn = j + C[k];
          if (yn < 0)
            yn = 0;
          else if (yn > 255)
            yn = 255;
          // 前回の出力を全て計算して，今回コードブックからどれを取るかを回せば今回の出力も計算できる

          int sum2 = (Y[i] - yn) * (Y[i] - yn);
          dp[i + 1][yn] = min(dp[i + 1][yn], dp[i][j] + sum2);
        }
      }
    }

    ll ans = INF;
    for (int j = 0; j <= 255; j++)
    {
      ans = min(ans, dp[N][j]);
    }
    cout << ans << endl;
  }
  return 0;
}

// dp[i][j]:=i番目の信号を出力jで符号化した際の誤差の2乗和の最小値
