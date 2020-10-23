#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

struct Edge
{
  int to;
  ll weight;
  Edge(int t, ll w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
// using Graph = vector<vector<int>>;

struct edge
{
  int from;
  int to;
};

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

vector<ll> dijkstra(Graph &G, int start)
{
  vector<ll> dist(G.size(), INF);
  // pair(その時点での最短経路，頂点番号)
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
  dist[start] = 0;
  que.push(make_pair(dist[start], start));
  while (!que.empty())
  {
    ll cost = que.top().first;
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

void bfs(Graph &G, vector<ll> &dist, int start)
{
  for (auto &it : dist)
    it = -1;
  queue<int> que;
  dist[start] = 0;
  que.push(start);
  while (!que.empty())
  {
    int v = que.front();
    que.pop();
    for (auto nv : G[v])
    {
      if (dist[nv.to] != -1)
        continue;

      dist[nv.to] = dist[v] + 1;
      que.push(nv.to);
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N, M, K, S;
  cin >> N >> M >> K >> S;
  ll P, Q;
  cin >> P >> Q;
  vector<int> C(K);
  vector<bool> zonbi(N, false);
  for (auto &it : C)
  {
    cin >> it;
    it--;
    zonbi[it] = true;
  }

  Graph G1(N + 1);
  vector<edge> edges;
  for (int i = 0; i < M; i++)
  {
    int A, B;
    cin >> A >> B;
    A--, B--;
    G1[A].push_back({B, 0});
    G1[B].push_back({A, 0});
    edges.push_back({A, B});
  }
  for (auto it : C)
  {
    G1[it].push_back({N, 0});
    G1[N].push_back({it, 0});
  }

  vector<ll> check_danger(N + 1);
  bfs(G1, check_danger, N);

  vector<bool> danger(N, false);
  for (int i = 0; i < N; i++)
  {
    if (check_danger[i] <= S + 1)
      danger[i] = true;
  }

  Graph G2(N);
  for (auto it : edges)
  {
    int A, B;
    A = it.from, B = it.to;
    if (B == N - 1)
      G2[A].push_back({B, 0});
    else if (zonbi[B])
      G2[A].push_back({B, INF});
    else if (danger[B])
      G2[A].push_back({B, Q});
    else
      G2[A].push_back({B, P});

    if (A == N - 1)
      G2[B].push_back({A, 0});
    else if (zonbi[A])
      G2[B].push_back({A, INF});
    else if (danger[A])
      G2[B].push_back({A, Q});
    else
      G2[B].push_back({A, P});
  }

  vector<ll> dist = dijkstra(G2, 0);
  cout << dist[N - 1] << endl;
  return 0;
}
// ゾンビがいるK個の町それぞれと1本の道で結ばれている仮想の町を1つ考えてそこからS+1本以内の道からなる経路で到達出来る町を列挙すること．こうすれば1回のbfsで危険な町を列挙することが出来る．頂点Nに向かう辺のコストは0とする．
