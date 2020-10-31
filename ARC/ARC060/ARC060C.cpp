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
  ll N, A;
  cin >> N >> A;
  vector<ll> x(N);
  for (auto &it : x)
    cin >> it;

  vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(N + 1, vector<ll>(2600, 0)));

  dp[0][0][0] = 1;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      for (int k = 0; k <= 2500; k++)
      {
        if (k >= x[i])
          dp[i + 1][j + 1][k] += dp[i][j][k - x[i]];
        dp[i + 1][j][k] += dp[i][j][k];
      }
    }
  }

  ll sum = 0;
  for (int j = 1; j <= N; j++)
  {
    sum += dp[N][j][j * A];
  }
  cout << sum << endl;
  return 0;
}

// DP dp[j][k][s]:=(j番目からk枚選んでxiの合計をsにするような選び方の総数)　dp[j][k][s] = 1(j=0,k=0,s=0), dp[j-1][k][s](j>=1,s<xjのとき), dp[j-1][k][s]+dp[j-1][k-1][s-xj](j>=1, k>=1, s>=xj), 0（上記いずれでもないとき）
