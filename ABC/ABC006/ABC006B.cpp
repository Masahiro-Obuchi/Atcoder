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
  int n;
  cin >> n;
  long long dp[1000010];

  for (int i = 0; i < 1000010; i++)
    dp[i] = 0;

  dp[0] = 0, dp[1] = 0, dp[2] = 1;

  for (int i = 3; i < 1000010; i++)
  {
    chmax(dp[i], (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 10007);
  }

  cout << dp[n - 1] << endl;
}

// 典型的なDP
