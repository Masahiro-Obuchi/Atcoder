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

void dfs(Graph &G, vector<ll> &a, vector<ll> &sum, ll &res, int v, int p = -1, int h = 0)
{
  res += h * 1LL * a[v];
  sum[v] = a[v];

  for (auto to : G[v])
  {
    if (to == p)
      continue;

    dfs(G, a, sum, res, to, v, h + 1);
    sum[v] += sum[to];
  }
}

void go(Graph &G, vector<ll> &sum, ll &res, ll &ans, int v, int p = -1)
{
  ans = max(ans, res);

  for (auto to : G[v])
  {
    if (to == p)
      continue;

    res -= sum[to];
    sum[v] -= sum[to];
    res += sum[v];
    sum[to] += sum[v];

    go(G, sum, res, ans, to, v);

    sum[to] -= sum[v];
    res -= sum[v];
    sum[v] += sum[to];
    res += sum[to];
  }
}

void solve()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &it : a)
    cin >> it;
  vector<ll> sum(n);
  Graph G(n);

  for (int i = 0; i < n - 1; i++)
  {
    int x, y;
    cin >> x >> y;
    x--, y--;
    G[x].push_back(y), G[y].push_back(x);
  }

  ll res = 0;
  ll ans = 0;

  dfs(G, a, sum, res, 0);
  go(G, sum, res, ans, 0);

  cout << ans << endl;
  return;
}
// re-rooting 全方位木DP
// The following sequence of changes will change all values correctly:Firstly, it can be seen that res will decrease by sumv(because the distance to each vertex in this subtree will decrease by one);then sumu will decrease by sumv(because we change the root of the tree)(we need this step to maintain the correct values);then res will increase by sumu(because the distance to each vertex in this subtree will increase by one);and then sumv will increase by sumu(because we change the root of the tree)(we need this step to maintain the correct values).

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
