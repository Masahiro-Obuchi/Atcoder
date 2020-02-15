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
  int D, N;
  cin >> D >> N;
  vector<int> T(D);
  for (int i = 0; i < D; i++)
    cin >> T[i];
  vector<int> A(N), B(N), C(N);
  for (int i = 0; i < N; i++)
    cin >> A[i] >> B[i] >> C[i];
  long long dp[210][210] = {0};

  for (int i = 1; i < D; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (T[i - 1] >= A[j] && T[i - 1] <= B[j])
      {
        for (int k = 0; k < N; k++)
        {
          if (T[i] >= A[k] && T[i] <= B[k])
          {
            // 全ての服について派手さの絶対値の合計について考える．
            chmax(dp[i + 1][k], dp[i][j] + abs(C[j] - C[k]));
          }
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < N; i++)
  {
    ans = max(ans, dp[D][i]);
  }
  cout << ans << endl;
}

// 注目すべきは，i日目までの服の選び方を決めた時，i+1日目以降について服を選んで目的の値を最大化する際には，1日目からi-1日目までの服の選び方は関係ないという点である．dp[i+1][j]:=i日目に服jを選ぶとしたときの,i日目までの連続する日に着る服の派手さの差の絶対値の合計　とする．すなわちdp[i][j]は問題の条件および，xi = jを満たすときの|Cx1 - Cx2| + |Cx2 - Cx3| + ... + |Cxi-1 - Cxi|の最大値である．このとき，f(i+1, j')は次のようにして計算できる : f(i+1, j')はf(i, j) + |Cj - Cj'|のうち 最大の値となる．このようにサイズの小さい問題から順番に解いていくような手法は動的計画法と呼ばれる．
// 実装時にはi-1日目の気温の条件も考慮する．すなわち，i-1日目にjの服を選んだ場合にTi-1 >= Aj とTi-1 <= Bjを満たしているもののみを考慮する．
