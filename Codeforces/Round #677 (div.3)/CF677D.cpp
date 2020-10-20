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
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &it : a)
    cin >> it;

  UnionFind uf(n);
  // int cnt = 0;
  vector<P> ans;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (a[i] != a[j] && uf.root(i) != uf.root(j))
      {
        uf.merge(i, j);
        ans.push_back({i + 1, j + 1});
      }
    }
  }

  bool ok = true;
  for (int i = 0; i < n; i++)
  {
    if (uf.root(i) != uf.root(0))
    {
      ok = false;
    }
  }
  if (ans.size() != n - 1)
    ok = false;
  if (!ok)
  {
    cout << "NO" << endl;
  }
  else
  {
    cout << "YES" << endl;
    for (auto it : ans)
    {
      cout << it.first << " " << it.second << endl;
    }
  }
  return;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    solve();
  }
  return 0;
}
