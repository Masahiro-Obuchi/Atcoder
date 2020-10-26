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

void dfs(const Graph &G, vector<ll> &subtree_size, int v, int p)
{
  for (auto u : G[v])
  {
    if (u == p)
      continue;
    dfs(G, subtree_size, u, v);
  }

  if (G[v].size() == 1 && v != 0)
    subtree_size[v] = 1;
  for (auto c : G[v])
  {
    if (c == p)
      continue;
    subtree_size[v] += subtree_size[c];
  }
}
// 葉の数の求め方

void dfs2(const Graph &G, vector<ll> &a, vector<ll> &suma, int v, int p)
{
  for (auto u : G[v])
  {
    if (u == p)
      continue;
    dfs2(G, a, suma, u, v);
  }

  suma[v] = a[v];
  for (auto c : G[v])
  {
    if (c == p)
      continue;
    suma[v] += suma[c];
  }
}

// 葉の数とaの値を共に木DPで求める
// The answer to the original problem is maxi(sumav/leavesi)(切り上げ)
// 二分探索解もある（部分木の頂点に対してx以下で分割出来るようなxを見つける）

void solve()
{
  int n;
  cin >> n;
  Graph G(n);
  for (int i = 0; i < n - 1; i++)
  {
    int p;
    cin >> p;
    p--;
    G[i + 1].push_back(p);
    G[p].push_back(i + 1);
  }
  vector<ll> a(n);
  for (auto &it : a)
    cin >> it;
  vector<ll> subtree_size(n, 0);
  dfs(G, subtree_size, 0, -1);
  vector<ll> suma(n, 0);
  dfs2(G, a, suma, 0, -1);
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans = max(ans, (suma[i] + (subtree_size[i] - 1)) / subtree_size[i]);
  }
  cout << ans << endl;
  return;
}

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
