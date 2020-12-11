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

void solve()
{
  int n, m, D;
  cin >> n >> m >> D;

  UnionFind uf1(n), uf2(n);
  Graph G(n);
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    x--, y--;
    G[x].push_back(y);
    G[y].push_back(x);
    if (x && y)
      uf1.merge(x, y); // どちらも頂点1でなければ連結
  }

  vector<P> ans;
  for (auto no : G[0])
  {
    if (uf1.isSame(0, no))
      continue;
    uf1.merge(0, no);
    uf2.merge(0, no);
    ans.push_back({no + 1, 1});
  }

  // 次数が足りない or 外せる辺がない
  if (G[0].size() < D || ans.size() > D)
  {
    cout << "NO" << endl;
    return;
  }

  // Dになるまで辺を追加

  for (auto no : G[0])
  {
    if (ans.size() == D)
      break;
    if (uf2.isSame(no, 0))
      continue;
    uf2.merge(no, 0);
    ans.push_back({1, no + 1});
  }

  for (int i = 1; i < n; i++)
  {
    for (auto no : G[i])
    {
      if (uf2.isSame(i, no) || no == 0)
        continue;
      ans.push_back({no + 1, i + 1});
      uf2.merge(no, i);
    }
  }

  cout << "YES" << endl;
  for (auto it : ans)
  {
    cout << it.first << " " << it.second << endl;
  }
  return;
}
// もとのグラフの頂点１の次数をxとする。xがDより真に小さい場合は構築不可能である。xがD以上の場合、頂点1から取り除いてはいけない辺の本数がD以下であればよい。まず頂点1を除いたグラフを用意する。このグラフの連結成分の個数が頂点1から伸ばす必要のある辺の最小本数である。この本数をcntとしたとき、cnt > Dの場合は構築不可能である。そうでなければ頂点１に対して必要な辺をはり、次数がDになるまで辺を追加する。あとはF1と同様にUnion - Findで候補の辺から条件を満たす辺を追加すればよい。

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  t = 1;
  for (int i = 0; i < t; i++)
  {
    solve();
  }
  return 0;
}
