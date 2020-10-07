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
  long double cost;
};

bool comp_e(const Edge &e1, const Edge &e2)
{
  return e1.cost < e2.cost;
}

bool comp_e_greater(const Edge &e1, const Edge &e2)
{
  return e1.cost > e2.cost;
}

struct Kruskal
{
  UnionFind uft;
  long double sum;
  vector<Edge> edges;
  vector<Edge> resEdges;
  int V;
  Kruskal(const vector<Edge> &edges_, int V_) : edges(edges_), V(V_) { init(); }
  void init()
  {
    sort(edges.begin(), edges.end(), comp_e);
    uft = UnionFind(V);
    sum = 0.0;
    for (auto e : edges)
    {
      if (!uft.isSame(e.u, e.v))
      {
        uft.unite(e.u, e.v);
        sum += e.cost;
        resEdges.push_back(e);
      }
    }
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  while (true)
  {
    cin >> n;
    if (n == 0)
      break;

    vector<long double> x(n), y(n), z(n), r(n);
    for (int i = 0; i < n; i++)
    {
      cin >> x[i] >> y[i] >> z[i] >> r[i];
    }

    vector<Edge> edges;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (i == j)
          continue;
        long double dist = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2) + pow(z[i] - z[j], 2));
        if (dist > r[i] + r[j])
        {
          Edge e = {i, j, dist - (r[i] + r[j])};
          edges.push_back(e);
        }
        else
        {
          Edge e = {i, j, 0};
          edges.push_back(e);
        }
      }
    }
    Kruskal krs(edges, n);
    cout << setprecision(3) << fixed << krs.sum << endl;
  }
  return 0;
}

// 含まれればコスト0, 含まれなければ表面から表面までの長さ
