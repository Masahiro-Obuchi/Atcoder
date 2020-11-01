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

int V, E;
int G[20][20]; // グラフ
int dp[50000][20];
// メモ化再帰
int rec(int S, int v)
{
  if (S == 0)
  {
    if (v == 0)
    {
      return 0;
    }
    else
    {
      return INT_INF;
    }
  }
  if ((S & (1 << v)) == 0)
  { // Sに{v}が含まれていない
    return INT_INF;
  }
  int &ret = dp[S][v];
  if (ret != 0)
    return ret;
  ret = INT_INF;
  for (int u = 0; u < V; u++)
  {
    if (ret > rec(S ^ (1 << v), u) + G[u][v])
      ret = rec(S ^ (1 << v), u) + G[u][v];
  }
  return ret;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> V >> E;
  for (int i = 0; i < 20; i++)
  {
    for (int j = 0; j < 20; j++)
    {
      G[i][j] = INT_INF;
    }
  }
  for (int i = 0; i < E; i++)
  {
    int s, t, d;
    cin >> s >> t >> d;
    G[s][t] = d;
  }

  int ans = rec((1 << V) - 1, 0);

  if (ans != INT_INF)
    cout << ans << endl;
  else
    cout << -1 << endl;
  return 0;
}

// 始点と終点を除いて全ての頂点を1度ずつ通る閉路のことをハミルトン閉路という．漸化式を立てるためには直前にどこにいたのかの情報が不可欠なためdp[S][v]:={0, 1, 2,..., n-1}の部分集合Sを巡回する|S|!通りの経路のうち最短のものの距離とする．ただし最後に頂点vに到達した時のみ．更新式は頂点uから頂点vまでの距離をcost(u, v)とするとdp[S | {v}] = min(dp[S][u] + cost(u, v))
// 実装上では集合の要素が1の時，2の時，3の時,....のように考えるとループで表現することが難しいためメモ化再帰で実装するのが一般的．どの頂点からスタートしたとしても最短となるハミルトン閉路が存在する．
// dp[S][v]:=頂点0からスタートして{0, 1, 2,..., n-1}の部分集合Sを巡回する|S!|通りの経路のうち最短のものの距離．ただし，最後に頂点vに到達したときのみを考える．
// メモ化再帰
// 初期値　dp[1<<v][v] = 0 最終的な最小コスト minvdp[(1<<n)-1][v]となる
