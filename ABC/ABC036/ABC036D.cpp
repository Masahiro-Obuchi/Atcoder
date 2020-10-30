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
// using Graph = vector<vector<Edge>>;
using Graph = vector<vector<int>>;

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

void dfs(Graph &G, vector<mint> &f, vector<mint> &g, int v, int p = -1)
{
  for (auto u : G[v])
  {
    if (u == p)
      continue;
    dfs(G, f, g, u, v);
  }

  f[v] = 1, g[v] = 1;

  for (auto u : G[v])
  {
    if (u == p)
      continue;
    g[v] *= f[u];
    f[v] *= g[u];
  }
  f[v] += g[v];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  Graph G(N);
  for (int i = 0; i < N - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<mint> f(N), g(N);
  dfs(G, f, g, 0);

  cout << f[0] << endl;
  return 0;
}

// 次のような値を考える　f(x): 頂点xを親とする部分木に含まれる頂点を全て白または黒で塗り，両端が黒で塗られた辺が存在しないようにする方法は何通りか？
// g(x): 頂点xを親とする部分木に含まれる頂点を全て白または黒で塗り，両端が黒で塗られた辺が存在しないようにする方法は何通りか？ただし，頂点xは必ず白で塗らなければならない．
// 頂点xを親とする部分木のうちxと隣り合っている頂点をxの子という．xの子がy1, .... , ykであるとき次の式が成り立つ．f(x) = g(x) + g(y1)*g(y2)*...*g(yk), g(x) = f(y1)*f(y2)*...*f(yk) 上の式を用いてf, gの値を根から遠い順に求めていけばよい．treeDP
