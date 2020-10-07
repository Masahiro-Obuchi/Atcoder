#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

long long modpow(long long a, long long n, long long mod)
{
  long long res = 1;
  while (n > 0)
  {
    if (n & 1)
      res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  vector<int> check(N);
  for (int i = 0; i < N; i++)
  {
    check[A[i]]++;
  }
  bool can = true;
  if (N % 2 != 0)
  {
    if (check[0] != 1)
      can = false;
  }
  for (int i = N - 1; i > 0; i -= 2)
  {
    if (check[i] != 2)
      can = false;
  }
  if (!can)
    cout << 0 << endl;
  else
  {
    ll ans = modpow(2, N / 2, MOD);
    cout << ans << endl;
  }
  return 0;
}

// Nが偶数の場合はN - 1, N - 3, N - 5,..., 3, 1が2個ずつなかったらアウト．奇数の場合はこれ＋0が1個なかったらアウト．okの場合は2^(N/2)となる．（切り捨てだから奇数のときも偶数のときも成り立つ）
// modpowを使え
