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
  int N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;

  vector<vector<mint>> dp(N + 10, vector<mint>(N + 10, 0));
  dp[A - 1][0] = 1;

  for (int i = A; i <= B; i++)
  {
    for (int j = 0; j <= N; j++)
    {
      // i人グループが0個
      dp[i][j] += dp[i - 1][j];
      int n = N - j;
      mint pw = c.fact[i].pow(C);
      for (int k = C; k <= D && i * k <= n; k++)
      {
        mint res = c(n, i * k) * c.fact[i * k] / pw / c.fact[k];
        pw *= c.fact[i];
        dp[i][j + i * k] += dp[i - 1][j] * res;
      }
    }
  }
  cout << dp[B][N] << endl;
  return 0;
}

// 数え上げはDPを使うことを考える　dp[i][j] := i人以下のグループのみでj人使っている場合の数を考える．このdpの遷移は以下のようになる．dp[i][j] = \sigma_{k = 0, C, C+1, ...D} dp[i - 1][j - i * k]*(n - j + i * k)P(i*k)/(i!)^k/k! kの動く範囲はj/iしか考えなくて良い．
// https://betrue12.hateblo.jp/entry/2019/12/01/155121
// x /= yのときx人組の個数とy人組の個数には関係がない　という点に着目するとx人組のグループを一気にすべて決めてしまう．->をx = A, A+1, A+2, ..., Bについて順番に行っていく．このとき覚えておくべき情報は既に作られたグループで何人使ったかという情報だけ　これから上のようなDPを考えることが出来る．
// 遷移を考える．dp[i - 1][N - n]からの遷移係数は残っているn人からi人組をいくつか組む通り数となる．i人組をk個作るとするとdp[i][N - n + ik]に遷移するときの係数は nCik(ik!)/(i!)^kk!という値になる．内訳はnCik: n人残っている中で使うik人を選ぶ．(ik!)/(i!)^k: ik人に対してグループを組むi人を選ぶという処理をk回繰り返す．1/k!: グループの区別をしないのでk!で割る．

// どのグループの人数もA人であるとするとそれぞれの人をk個の箱に均等に振り分ける場合の数は(kA)!/(A!)^kとなる．(=kACA * kA-ACA * kA-2ACA * ... * kA-(k-1)ACA)
