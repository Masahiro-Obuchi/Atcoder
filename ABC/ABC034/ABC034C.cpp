#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
struct Edge
{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
// using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

const int MOD = 1000000007;

class mint
{
  ll x;

public:
  mint(ll x = 0) : x((x % MOD + MOD) % MOD) {}
  mint operator-() const
  {
    return mint(-x);
  }

  mint &operator+=(const mint &a)
  {
    if ((x += a.x) >= MOD)
      x -= MOD;
    return *this;
  }

  mint &operator-=(const mint &a)
  {
    if ((x += MOD - a.x) >= MOD)
      x -= MOD;
    return *this;
  }

  mint &operator*=(const mint &a)
  {
    (x *= a.x) %= MOD;
    return *this;
  }

  mint operator+(const mint &a)
  {
    mint res(*this);
    return res += a;
  }

  mint operator-(const mint &a)
  {
    mint res(*this);
    return res -= a;
  }

  mint operator*(const mint &a)
  {
    mint res(*this);
    return res *= a;
  }

  mint pow(ll t) const
  {
    if (!t)
      return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1)
      a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const
  {
    return pow(MOD - 2);
  }

  mint &operator/=(const mint &a)
  {
    return (*this) *= a.inv();
  }

  mint operator/(const mint &a)
  {
    mint res(*this);
    return res /= a;
  }

  friend ostream &operator<<(ostream &os, const mint &m)
  {
    os << m.x;
    return os;
  }
};

// 二項係数nCr
const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit()
{
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++)
  {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// 二項係数計算
long long COM(int n, int k)
{
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int W, H;
  cin >> W >> H;
  mint ans = 0;
  COMinit();
  ans += COM(W - 1 + H - 1, W - 1);
  cout << ans << endl;
  return 0;
}
