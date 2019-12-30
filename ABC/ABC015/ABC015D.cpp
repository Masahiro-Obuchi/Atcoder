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

long long dp[55][11000][55] = {0};

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
    for (int sum_w = 0; sum_w <= W; sum_w++)
    {
      for (int k = 0; k <= K; k++)
      {
        // i番目の品物を選ぶ場合
        if (sum_w - A[i] >= 0 && k - 1 >= 0)
        {
          chmax(dp[i + 1][sum_w][k], dp[i][sum_w - A[i]][k - 1] + B[i]);
        }

        chmax(dp[i + 1][sum_w][k], dp[i][sum_w][k]);
      }
    }
  }
  cout << dp[N][W][K] << endl;
}

// dp[i][sum_w][k] i-1までの品物から幅がsum_w, 枚数がk枚を超えないように選んだ時の重要度の総和の最大値
