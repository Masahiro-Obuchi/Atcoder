#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

// Graph
struct Edge
{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;

void dfs(int N, int u, Graph &G, vector<bool> &used, vector<ll> &dist, bool &can, ll cost)
{
  if (used[u])
  {
    if (dist[u] != cost)
      can = false;
  }
  else
  {
    used[u] = true;
    dist[u] = cost;
    for (auto v : G[u])
    {
      dfs(N, v.to, G, used, dist, can, cost + v.weight);
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  Graph G(N);
  for (int i = 0; i < M; i++)
  {
    int L, R, D;
    cin >> L >> R >> D;
    L--, R--;
    G[L].push_back(Edge(R, D));
    G[R].push_back(Edge(L, -D));
  }
  bool can = true;
  vector<bool> used(N, false);
  vector<ll> dist(N, -1);
  dist[0] = 0;
  for (int i = 0; i < N; i++)
  {
    if (!used[i])
    {
      dist[i] = 0; // 適当に座標を設定
      dfs(N, i, G, used, dist, can, 0);
    }
  }
  if (can)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}

// 1つ数を決めるとそれと連結の座標の数がすべて決まる．
// 解説放送を見ると何をしているのかが分かりやすい
