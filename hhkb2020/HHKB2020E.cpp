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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int H, W;
  cin >> H >> W;
  ll dots = 0;
  vector<string> S(H);
  for (auto &it : S)
  {
    cin >> it;
  }

  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (S[i][j] == '.')
        dots += 1;
    }
  }

  vector<vector<ll>> L(H, vector<ll>(W)), R(H, vector<ll>(W)), D(H, vector<ll>(W)), U(H, vector<ll>(W)); // i行j列目に明かりを置いたときにそこから左方向に照らされるマスの個数etc

  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (S[i][j] == '#')
        L[i][j] = 0;
      else
      {
        if (j == 0)
        {
          L[i][j] = 1;
        }
        else
        {
          L[i][j] = L[i][j - 1] + 1;
        }
      }
    }
  }

  for (int i = 0; i < H; i++)
  {
    for (int j = W - 1; j >= 0; j--)
    {
      if (S[i][j] == '#')
        R[i][j] = 0;
      else
      {
        if (j == W - 1)
        {
          R[i][j] = 1;
        }
        else
        {
          R[i][j] = R[i][j + 1] + 1;
        }
      }
    }
  }

  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (S[i][j] == '#')
        U[i][j] = 0;
      else
      {
        if (i == 0)
        {
          U[i][j] = 1;
        }
        else
        {
          U[i][j] = U[i - 1][j] + 1;
        }
      }
    }
  }

  for (int i = H - 1; i >= 0; i--)
  {
    for (int j = 0; j < W; j++)
    {
      if (S[i][j] == '#')
        D[i][j] = 0;
      else
      {
        if (i == H - 1)
        {
          D[i][j] = 1;
        }
        else
        {
          D[i][j] = D[i + 1][j] + 1;
        }
      }
    }
  }

  vector<vector<ll>> cnts(H, vector<ll>(W));
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cnts[i][j] = L[i][j] + R[i][j] + U[i][j] + D[i][j] - 3; // 重なっている部分を引く
    }
  }

  mint ans = 0;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (S[i][j] == '.')
      {
        mint tmp = mint(2).pow(cnts[i][j]) - 1;
        mint tmp2 = mint(2).pow(dots - cnts[i][j]);
        tmp *= tmp2;
        ans += tmp;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

// ABC129Dの方法を使って前計算をすれば照らされるマスの個数を数えられる...
