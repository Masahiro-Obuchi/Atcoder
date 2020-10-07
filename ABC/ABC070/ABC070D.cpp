#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

const int limit = 100010;
using edge = struct
{
  int to;
  ll cost;
};

vector<edge> tree[limit];

ll depth[limit];

void dfs(int v, int p, ll d)
{
  depth[v] = d;
  for (auto &e : tree[v])
  {
    if (e.to == p)
      continue;
    dfs(e.to, v, d + e.cost);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;

  for (int i = 0; i < N - 1; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    tree[a].push_back({b, c});
    tree[b].push_back({a, c});
  }

  int q, k;
  cin >> q >> k;
  k--;

  dfs(k, -1, 0);

  for (int i = 0; i < q; i++)
  {
    int x, y;
    cin >> x >> y;
    x--, y--;
    cout << depth[x] + depth[y] << endl;
  }

  return 0;
}
// 与えられたグラフの性質を考える．与えられたグラフは閉路がない連結グラフであるため，異なる2頂点間の最短経路は1通りに定まる．次に，全ての質問クエリで求める最短経路は頂点Kを経由している．したがって，各質問クエリの答えは頂点xjから頂点Kまでの最短経路+頂点Kから頂点yjまでの最短経路となります．このことから，頂点Kから全ての頂点への最短経路を前計算することにより各質問クエリを効率よく処理することが可能．頂点Kから全ての頂点への最短経路を前計算する方法として頂点KからDFSをするのが簡単．
