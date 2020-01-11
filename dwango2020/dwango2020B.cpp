#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

// mod. mでのaの逆元a{-1}を計算する
long long modinv(long long a, long long m)
{
  long long b = m, u = 1, v = 0;
  while (b)
  {
    long long t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0)
    u += m;
  return u;
}

int main()
{
  long long N;
  cin >> N;
  long long MOD = 1000000007;
  vector<long long> x(N);
  for (int i = 0; i < N; i++)
  {
    cin >> x[i];
  }
  vector<long long> c(N);
  c[0] = 0;
  for (int i = 1; i < N; i++)
  {
    c[i] = c[i - 1] + 1 * modinv(i, MOD);
  }
  vector<long long> deltax(N);
  deltax[0] = 0;
  for (int i = 1; i < N; i++)
  {
    deltax[i] = x[i] - x[i - 1];
  }
  long long sum = 0;
  for (int i = 1; i < N; i++)
  {
    sum += c[i] * deltax[i];
    sum %= MOD;
  }
  for (int i = N - 1; i >= 1; i--)
  {
    sum *= i;
    sum %= MOD;
  }
  cout << sum << endl;
}

// (N-1)!を最後にかけるとすると，求めるものはそれぞれのスライムが移動する距離の総和の期待値．それぞれのスライムが移動する距離を求める代わりに1<=i<Nを満たすiについてxi, xi+1間を各スライムが移動する確率を求める．
// 逆元を用いる
