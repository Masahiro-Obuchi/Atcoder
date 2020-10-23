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

bool dfs2(Graph &G, vector<int> &h, int v, int p = -1)
{
  bool isExist = false;
  for (auto u : G[v])
  {
    if (u == p)
      continue;
    isExist |= dfs2(G, h, u, v);
  }

  if (h[v] == 1)
    isExist = true;

  return isExist;
}

void dfs(Graph &G, vector<int> &h, int &ans, int v, int p = -1)
{
  for (auto u : G[v])
  {
    if (u == p)
      continue;
    if (dfs2(G, h, u, v))
    {
      ans += 2;
      dfs(G, h, ans, u, v);
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x;
  cin >> n >> x;
  x--;
  vector<int> h(n);
  for (auto &it : h)
    cin >> it;
  Graph G(n);
  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  int ans = 0;
  dfs(G, h, ans, x);
  cout << ans << endl;
  return 0;
}

// 与えられたグラフから出発地点を根とした根付き木を構築する．ある辺を辿るべきかどうかであるが「辺を辿った先の部分木の頂点が1つでも宝石を含んでいるときに限り通り，それ以外のときは通らなくてもよい．ある辺を使う時は行きと帰りで必ず2回通る．（閉路は存在しないから）判定関数で行く必要のない頂点の遷移しないような再帰関数を書き，辺を辿るごとに答えに2を加算するプログラムを書く
