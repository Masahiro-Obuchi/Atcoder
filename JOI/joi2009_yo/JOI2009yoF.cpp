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

const int MOD = 100000;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M, S;
  cin >> N >> M >> S;
  vector<vector<int>> dp(N * N + 1, vector<int>(S + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= N * N; i++)
  {
    for (int j = 0; j <= S; j++)
    {
      if (i <= j)
      {
        dp[i][j] += dp[i][j - i] + dp[i - 1][j - i];
      }
      if (j - M - 1 >= 0)
      {
        dp[i][j] -= dp[i - 1][j - M - 1];
      }
      dp[i][j] = (dp[i][j] + MOD) % MOD;
    }
  }
  cout << dp[N * N][S] << endl;
  return 0;
}

// dp[i][j]:=i個の異なるM以下の数で総和をjにする組み合わせ　
// dp[i][j] = dp[i - 1][j - i] + dp[i][j - i] - dp[i - 1][j - M  - 1] 第1項は既に出来ているi-1個のそれぞれに1を加算しi番目に1を付け加えるという操作を意味する　第2項はすでにできているi個の数のそれぞれに1を加算して出来るという意味を表す　第3項は1を加算したことでMを超えるような場合の数を取り除くようなもの　dp[i][j]でMを超えるとしたら遷移の仕方からその値はM + 1でかつその一つだけ．他のi - 1個の総和がj - M - 1でかつMを超えるものがない場合なのでdp[i - 1][j - M - 1]に対応
// https://suikaba.hatenablog.com/entry/2017/12/06/180214
