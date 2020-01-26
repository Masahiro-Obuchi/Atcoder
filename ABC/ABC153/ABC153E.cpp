
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}

int main()
{
  long long H, N;
  cin >> H >> N;
  vector<long long> A(N), B(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i] >> B[i];
  }
  vector<vector<long long>> dp(N + 1, vector<long long>(H + 1, INF));
  dp[0][0] = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j <= H; j++)
    {
      chmin(dp[i + 1][j], dp[i][j]);

      chmin(dp[i + 1][j], dp[i + 1][max(0LL, j - A[i])] + B[i]);
    }
  }
  cout << dp[N][H] << endl;
}

// dp[i][h]:=最初のi種類の魔法でモンスターにh「以上」のダメージを与える場合の消費魔力の最小値　個数制限なしナップサック問題の時はi種類目の魔法を1回使うことにした状態はdp[i+1][j-A[i]]と表すことができるので，min(dp[i][j], dp[i+1][j-A[i]]+B[i])となる．（すなわちi+1番目とi+1番目を比較することになる）　
// chmin(dp[i+1][j], dp[i][j])とchmin(dp[i+1][j], dp[i+1][max(0, j-A[i])] + B[i])の2つを計算する　maxを計算しないとB[i]を使う場合という条件が表せない
