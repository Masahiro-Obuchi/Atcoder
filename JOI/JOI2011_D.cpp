
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

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

long long dp[110][30] = {0}; //DPテーブル

int main()
{
  long long N;
  cin >> N;
  vector<long long> a(N);
  for (int i = 0; i < N; i++)
    cin >> a[i];
  dp[0][a[0]] = 1;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j <= 20; j++)
    {
      if (j >= a[i + 1] && j + a[i + 1] <= 20)
        chmax(dp[i + 1][j], dp[i][j - a[i + 1]] + dp[i][j + a[i + 1]]);

      else if (j < a[i + 1] && j + a[i + 1] <= 20)
        chmax(dp[i + 1][j], dp[i][j + a[i + 1]]);

      else if (j >= a[i + 1] && j + a[i + 1] > 20)
        chmax(dp[i + 1][j], dp[i][j - a[i + 1]]);

      if (j >= a[i + 1] && j + a[i + 1] <= 20)
        chmax(dp[i + 1][j], dp[i][j - a[i + 1]] + dp[i][j + a[i + 1]]);

      chmax(dp[i + 1][j], 0LL);
    }
  }
  cout << dp[N - 2][a[N - 1]] << endl;
}

// 数字がn個並んでいるとき穴がn-2箇所あるf(k, B):=左からk個の穴に「+」or「-」を入れて「a0からakまでを部分和」をBにする方法の数(0<=k<=n-2, 0 <= B <=20)とおけばf(k+1, B) = f(k, B - ak+1) + f(k, B + ak+1) (0 <= B <= 20でないときf(k, B) = 0と考える)　f(0, a0) = 1, f(0, B) = 0, (B not= a0) 求める答えは f(n-2, an-1)
