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
  int N, K, L;
  cin >> N >> K >> L;
  UnionFind uf1(N);
  for (int i = 0; i < K; i++)
  {
    int p, q;
    cin >> p >> q;
    p--, q--;
    uf1.merge(p, q);
  }
  vector<int> ar(N);
  for (int i = 0; i < N; i++)
  {
    ar[i] = uf1.root(i);
  }

  UnionFind uf2(N);
  for (int i = 0; i < L; i++)
  {
    int r, s;
    cin >> r >> s;
    r--, s--;
    uf2.merge(r, s);
  }
  vector<int> br(N);
  for (int i = 0; i < N; i++)
  {
    br[i] = uf2.root(i);
  }

  map<pair<int, int>, int> mp;
  for (int i = 0; i < N; i++)
  {
    mp[{ar[i], br[i]}]++;
  }

  for (int i = 0; i < N; i++)
  {
    cout << mp[{ar[i], br[i]}] << " ";
  }
  cout << endl;
  return 0;
}

// この解説をそのまま実装　https://img.atcoder.jp/arc065/editorial.pdf
