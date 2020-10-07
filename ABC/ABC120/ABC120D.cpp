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
  ll N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  for (int i = 0; i < M; i++)
  {
    cin >> A[i] >> B[i];
    A[i]--, B[i]--;
  }
  UnionFind uf(N);
  ll cur = N * (N - 1) / 2;
  vector<ll> res;
  for (int i = 0; i < M; i++)
  {
    res.push_back(cur);

    int a = A[M - i - 1], b = B[M - i - 1];

    if (uf.isSame(a, b))
      continue;

    ll sa = uf.size(a), sb = uf.size(b);
    cur -= sa * sb;
    uf.merge(a, b);
  }
  reverse(res.begin(), res.end());
  for (auto &it : res)
    cout << it << endl;
  return 0;
}

// 島を頂点，橋を辺としたグラフを考える．グラフから辺を削除していくのは難しいことが多いので逆に辺がない状態から追加していくことを考える．すなわち，後ろから答えを求めて配列に保存し，逆順に出力する．
// i番目に出力すべき答えをans(i)とする．辺を追加することを考えると初めは全ての辺がないのでans(M) = N * (N - 1) / 2．さらに各iについて，i+1番目の辺ei+1番目の辺ei+1=(ai+1, bi+1)によって1.元々ai+1, bi+1が連結でなかった場合，eを加える前のグラフにおいて，頂点ai+1を含む連結成分の大きさをN1, 頂点bi+1を含む連結成分の大きさをN2とすると，ans(i) = ans(i + 1) - N1 * N2となる．元々連結だった場合，不便さに変化はなくans(i) = ans(i+1)となる．
