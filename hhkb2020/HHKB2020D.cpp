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
    ll weight;
    Edge(int t, ll w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
*/
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

// modint
const int mod = 1000000007;
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

mint f1(int n)
{
  if (n < 0)
    return 0;
  mint res = mint(n) * (n + 1) / 2;
  return res;
}

mint f2(int n)
{
  if (n < 0)
    return 0;
  mint res = f1(n);
  res *= res;
  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T > 0)
  {
    ll N, A, B;
    cin >> N >> A >> B;
    mint X = f1(N - A - B + 1) * (N - B + 1) * (N - A + 1);
    mint Y = f2(N - A - B + 1);
    mint ans = X * 4 - Y * 4;
    cout << ans << endl;
    T--;
  }
  return 0;
}
