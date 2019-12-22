#include <bits/stdc++.h>
using namespace std;

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

long long dp[55][55][11000] = {0};

int main()
{
  int W;
  cin >> W;
  int N, K;
  cin >> N >> K;
  vector<long long> A(N);
  vector<long long> B(N);
  for (int i = 0; i < N; i++)
    cin >> A[i] >> B[i];

  // DPループ
  for (int i = 0; i < N; i++)
  {
    for (int k = 1; k <= K; k++)
    {
      for (int sum_w = 0; sum_w <= W; sum_w++)
      {
        chmax(dp[i + 1][sum_w][k], dp[i][sum_w][k]);
        // i番目の品物を選ぶ場合
        if (sum_w - A[i] >= 0)
        {
          chmax(dp[i + 1][sum_w][k], dp[i][sum_w - A[i]][k - 1] + B[i]);
        }
        // i番目の品物を選ばない場合
        else
        {
          chmax(dp[i + 1][sum_w][k], dp[i][sum_w][k]);
        }
      }
    }
  }
  long long int ans = 0;
  for (int i = 0; i <= K; i++)
  {
    for (int j = 0; j <= W; j++)
    {
      ans = max(ans, dp[N][j][i]);
    }
  }
  cout << ans << endl;
}

// dp[i][sum_w][k] i-1までの品物から幅がsum_w以下となるように選び, 枚数がk枚の時の重要度の総和の最大値
