#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
/*
struct Edge
{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
*/
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

const int mod = 998244353;
struct mint
{
  ll x; // typedef long long ll;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}
  mint operator-() const { return mint(-x); }
  mint &operator+=(const mint a)
  {
    if ((x += a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator-=(const mint a)
  {
    if ((x += mod - a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator*=(const mint a)
  {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const { return mint(*this) += a; }
  mint operator-(const mint a) const { return mint(*this) -= a; }
  mint operator*(const mint a) const { return mint(*this) *= a; }
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
  mint inv() const { return pow(mod - 2); }
  mint &operator/=(const mint a) { return *this *= a.inv(); }
  mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream &operator>>(istream &is, const mint &a) { return is >> a.x; }
ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }

struct combination
{
  vector<mint> fact, ifact;
  combination(int n) : fact(n + 1), ifact(n + 1)
  {
    assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
      fact[i] = fact[i - 1] * i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i)
      ifact[i - 1] = ifact[i] * i;
  }
  mint operator()(int n, int k)
  {
    if (k < 0 || k > n)
      return 0;
    return fact[n] * ifact[k] * ifact[n - k];
  }
  mint p(int n, int k)
  {
    return fact[n] * ifact[n - k];
  }
} c(1000005);

struct UnionFind
{
  vector<int> par;

  UnionFind(int n) : par(n, -1) {}

  int root(int x)
  {
    if (par[x] < 0)
      return x;
    else
      return par[x] = root(par[x]);
  }

  bool isSame(int x, int y)
  {
    return root(x) == root(y);
  }

  bool merge(int x, int y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
      return false;
    if (par[x] > par[y])
      swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  int size(int x)
  {
    return -par[root(x)];
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  vector<vector<int>> a(N, vector<int>(N));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> a[i][j];
    }
  }

  UnionFind uf1(N), uf2(N);
  for (int x = 0; x < N; x++)
  {
    for (int y = 0; y < N; y++)
    {
      bool ok = true;
      for (int i = 0; i < N; i++)
      {
        if (a[i][x] + a[i][y] > K)
          ok = false;
      }
      if (ok)
      {
        uf1.merge(x, y);
      }
    }
  }

  for (int x = 0; x < N; x++)
  {
    for (int y = 0; y < N; y++)
    {
      bool ok = true;
      for (int j = 0; j < N; j++)
      {
        if (a[x][j] + a[y][j] > K)
          ok = false;
      }
      if (ok)
      {
        uf2.merge(x, y);
      }
    }
  }

  mint ans = 1;
  vector<bool> used1(N), used2(N);
  for (int i = 0; i < N; i++)
  {
    if (!used1[uf1.root(i)])
    {
      for (int j = uf1.size(uf1.root(i)); j >= 1; j--)
        ans *= j;
      used1[uf1.root(i)] = true;
    }
  }
  for (int i = 0; i < N; i++)
  {
    if (!used2[uf2.root(i)])
    {
      for (int j = uf2.size(uf2.root(i)); j >= 1; j--)
        ans *= j;
      used2[uf2.root(i)] = true;
    }
  }
  cout << ans << endl;
  return 0;
}

// 「行swapしか出来ない場合の答え」*「列swapしかできない場合の答え」これは列swapをしても行swapの条件に一切影響がないから
