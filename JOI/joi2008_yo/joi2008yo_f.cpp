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

vector<int> dijkstra(Graph &G, int start)
{
  vector<int> dist(G.size(), INT_INF);
  // pair(その時点での最短経路，頂点番号)
  priority_queue<P, vector<P>, greater<P>> que;
  dist[start] = 0;
  que.push(make_pair(dist[start], start));
  while (!que.empty())
  {
    int cost = que.top().first;
    int idx = que.top().second;
    que.pop();
    if (dist[idx] < cost)
      continue;

    for (auto e : G[idx])
    {
      if (dist[e.to] <= cost + e.weight)
        continue;
      dist[e.to] = cost + e.weight;
      que.push(make_pair(dist[e.to], e.to));
    }
  }
  return dist;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  Graph G(n);
  for (int i = 0; i < k; i++)
  {
    int num;
    cin >> num;
    if (num == 0)
    {
      int a, b;
      cin >> a >> b;
      a--, b--;
      vector<int> dist = dijkstra(G, a);
      if (dist[b] == INT_INF)
        cout << -1 << endl;
      else
        cout << dist[b] << endl;
    }
    else
    {
      int c, d, e;
      cin >> c >> d >> e;
      c--, d--;
      G[c].push_back({d, e});
      G[d].push_back({c, e});
    }
  }
  return 0;
}
