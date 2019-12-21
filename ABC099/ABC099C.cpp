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

const long long INF = 1LL << 60;

long long dp[110000];

int main()
{
  int N;
  cin >> N;
  for (int i = 0; i < 110000; i++)
    dp[i] = INF;

  dp[0] = 0;
  for (int i = 0; i <= N; i++)
  {
    for (int j = 2; j <= 3; j++)
    {
      for (int k = 0; k <= 6; k++)
      {
        if (i + pow(3 * j, k) > 100000)
          continue;
        chmin(dp[i + int(pow(3 * j, k))], dp[i] + 1);
      }
    }
  }
  cout << dp[N] << endl;
}

// dp[i]はi円払うのに最適なコストとする
// 配るDPで考える。dp[i]から到達できるのは高々dp[i + pow(3*j, k)]しかないので三重ループ　j=2, 3, k = 0〜6　i + pow(3*j, k) が > 100000となるときはcontinue これとdp[i] + 1をchmin
// 1からNでループを回してかつi + 3^0は考えるため1からNの全ての場合についてINFのままであることはない
