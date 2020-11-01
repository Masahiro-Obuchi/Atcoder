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

template <class Abel>
struct UnionFind
{
  vector<int> par;
  vector<int> rank;
  vector<Abel> diff_weight;

  UnionFind(int n = 1, Abel SUM_UNITY = 0)
  {
    init(n, SUM_UNITY);
  }

  void init(int n = 1, Abel SUM_UNITY = 0)
  {
    par.resize(n);
    rank.resize(n);
    diff_weight.resize(n);
    for (int i = 0; i < n; ++i)
      par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
  }

  int root(int x)
  {
    if (par[x] == x)
    {
      return x;
    }
    else
    {
      int r = root(par[x]);
      diff_weight[x] += diff_weight[par[x]];
      return par[x] = r;
    }
  }

  Abel weight(int x)
  {
    root(x);
    return diff_weight[x];
  }

  bool issame(int x, int y)
  {
    return root(x) == root(y);
  }

  bool merge(int x, int y, Abel w)
  {
    w += weight(x);
    w -= weight(y);
    x = root(x);
    y = root(y);
    if (x == y)
      return false;
    if (rank[x] < rank[y])
      swap(x, y), w = -w;
    if (rank[x] == rank[y])
      ++rank[x];
    par[y] = x;
    diff_weight[y] = w;
    return true;
  }

  Abel diff(int x, int y)
  {
    return weight(y) - weight(x);
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  UnionFind<int> uf(N);
  for (int i = 0; i < M; i++)
  {
    int l, r, d;
    cin >> l >> r >> d;
    l--, r--;
    if (uf.issame(l, r))
    {
      int diff = uf.diff(l, r);
      if (diff != d)
      {
        cout << "No" << endl;
        return 0;
      }
    }
    else
    {
      uf.merge(l, r, d);
    }
  }
  cout << "Yes" << endl;
  return 0;
}

// 重み付きUnion-Find木　ノード間の距離も管理することが出来る．diff(x, y): xとyとが同じグループにいるときweight(y) - weight(x)をリターンする．merge(x, y, w): weight(y) = weight(x) + wとなるようにxとyをマージする
