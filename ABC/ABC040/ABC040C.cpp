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
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++)
    cin >> a[i];
  long long dp[100010];
  for (int i = 0; i < 100010; i++)
  {
    dp[i] = INF;
  }

  dp[0] = 0;

  for (int i = 1; i < N; i++)
  {
    chmin(dp[i], dp[i - 1] + abs(a[i] - a[i - 1]));
    if (i > 1)
      chmin(dp[i], dp[i - 2] + abs(a[i] - a[i - 2]));
  }
  cout << dp[N - 1] << endl;
}

// 典型的DP
