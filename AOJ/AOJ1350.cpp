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
  vector<Edge> candidate;
  Kruskal(const vector<Edge> &edges_, int V_) : edges(edges_), V(V_) { init(); }
  void init()
  {
    sort(edges.begin(), edges.end(), comp_e);
    uft = UnionFind(V);
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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<Edge> edges;
  for (int i = 0; i < M; i++)
  {
    ll s, t, w;
    cin >> s >> t >> w;
    s--, t--;
    Edge e = {s, t, w};
    edges.push_back(e);
  }
  Kruskal krs(edges, N);
  vector<Edge> candidate = krs.candidate;
  ll cost = krs.sum;
  ll ans = 0;
  ll ans_cost = 0;
  for (int i = 0; i < candidate.size(); i++)
  {
    vector<Edge> es;
    for (auto e : edges)
    {
      if (e.u == candidate[i].u && e.v == candidate[i].v && e.cost == candidate[i].cost)
        continue;
      es.push_back(e);
    }
    Kruskal krs2(es, N);
    bool connected = true;
    for (int j = 0; j < N; j++)
      if (!krs2.uft.isSame(0, j))
        connected = false;
    if (!connected || krs2.sum != cost)
    {
      ans++;
      ans_cost += candidate[i].cost;
    }
  }
  cout << ans << " " << ans_cost << endl;
  return 0;
}
// まず普通に最小全域木を求めてしまう．Hに含まれない辺は最小全域木を構成するのに必要なかった辺であるため「最小全域木に必ず含まれる辺」にはならないのは明らか．最小全域木に必ず含まれる辺eとは「その辺eがないと最小全域木が作れない辺」である．したがって以下を試せばよい．・e以外の辺で最小全域木を作ろうとしてみる．・最小全域木が作れなければその辺は必ず含まれる辺である．・最小全域木は作れるがそのコストがcより大きければその辺は必ず含まれる辺である．
// 連結判定にはUnionFindが使える．
