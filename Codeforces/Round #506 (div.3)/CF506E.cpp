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

void dfs(Graph &G, vector<int> &p, vector<int> &d, int v, int par = -1, int depth = 0)
{
  d[v] = depth;
  p[v] = par;
  for (auto u : G[v])
  {
    if (u == par)
      continue;
    dfs(G, p, d, u, v, depth + 1);
  }
}

void solve()
{
  int n;
  cin >> n;
  vector<int> p(n), d(n);

  Graph G(n);
  for (int i = 0; i < n - 1; i++)
  {
    int x, y;
    cin >> x >> y;
    x--, y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  dfs(G, p, d, 0);

  set<P> st;
  for (int i = 0; i < n; i++)
  {
    if (d[i] > 2)
    {
      st.insert({-d[i], i});
    }
  }

  int ans = 0;
  while (!st.empty())
  {
    int v = st.begin()->second;
    v = p[v];
    ans++;
    auto it = st.find({-d[v], v});
    if (it != st.end())
    {
      st.erase(it);
    }

    for (auto u : G[v])
    {
      auto it = st.find({-d[u], u});
      if (it != st.end())
      {
        st.erase(it);
      }
    }
  }
  cout << ans << endl;
}
// 一番遠い頂点の親から辺を張っていった方が多くの頂点を距離2以下に出来る
// setは小さい順に並ぶので-d[i]とすることで最も距離が大きい頂点から処理をすることができる
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
