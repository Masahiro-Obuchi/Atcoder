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
  vector<int> rank, parents;
  UnionFind() {}
  UnionFind(int n)
  {
    rank.resize(n, 0);
    parents.resize(n, 0);
    for (int i = 0; i < n; i++)
    {
      makeTree(i);
    }
  }
  void makeTree(int x)
  {
    parents[x] = x;
    rank[x] = 0;
  }
  bool isSame(int x, int y) { return findRoot(x) == findRoot(y); }
  void unite(int x, int y)
  {
    x = findRoot(x);
    y = findRoot(y);
    if (rank[x] > rank[y])
    {
      parents[y] = x;
    }
    else
    {
      parents[x] = y;
      if (rank[x] == rank[y])
      {
        rank[y]++;
      }
    }
  }
  int findRoot(int x)
  {
    if (x != parents[x])
      parents[x] = findRoot(parents[x]);
    return parents[x];
  }
};

struct Edge
{
  long long u;
  long long v;
  long long cost;
};

bool comp_e(const Edge &e1, const Edge &e2)
{
  return e1.cost < e2.cost;
}

struct Kruskal
{
  UnionFind uft;
  long long sum;
  vector<Edge> edges;
  int V;
  int resV;
  vector<Edge> candidate;
  Kruskal(const vector<Edge> &edges_, int V_, int resV_) : edges(edges_), V(V_), resV(resV_) { init(); }
  void init()
  {
    sort(edges.begin(), edges.end(), comp_e);
    uft = UnionFind(V);
    for (auto e : edges)
    {
      if (e.u == resV || e.v == resV)
      {
        uft.unite(e.u, e.v);
        candidate.push_back(e);
      }
    }
    sum = 0;
    for (auto e : edges)
    {
      if (!uft.isSame(e.u, e.v))
      {
        uft.unite(e.u, e.v);
        sum += e.cost;
        candidate.push_back(e);
      }
    }
  }
};

void solve()
{
  ll n, m;
  cin >> n >> m;
  vector<int> s(m), t(m);
  Graph G(n);
  for (int i = 0; i < m; i++)
  {
    cin >> s[i] >> t[i];
    s[i]--, t[i]--;
    G[s[i]].push_back(t[i]);
    G[t[i]].push_back(s[i]);
  }

  int resV = -1, cnt = 0;
  for (int i = 0; i < n; i++)
  {
    if (G[i].size() > cnt)
    {
      cnt = G[i].size();
      resV = i;
    }
  }

  vector<Edge> edges;
  for (int i = 0; i < m; i++)
  {
    Edge e = {s[i], t[i], 1};
    edges.push_back(e);
  }

  Kruskal krs(edges, n, resV);
  vector<Edge> candidate = krs.candidate;
  for (auto it : candidate)
  {
    cout << it.u + 1 << " " << it.v + 1 << endl;
  }
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
