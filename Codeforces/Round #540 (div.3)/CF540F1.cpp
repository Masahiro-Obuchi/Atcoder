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

P dfs(Graph &G, vector<int> &a, int &red, int &blue, int &ans, int v, int p = -1)
{
  int r = (a[v] == 1), b = (a[v] == 2);
  for (auto u : G[v])
  {
    if (u == p)
      continue;
    auto tmp = dfs(G, a, red, blue, ans, u, v);
    ans += (tmp.first == red && tmp.second == 0);
    ans += (tmp.first == 0 && tmp.second == blue);
    r += tmp.first;
    b += tmp.second;
  }
  return make_pair(r, b); // P型の関数
}

void solve()
{
  int n;
  cin >> n;
  int red = 0, blue = 0;
  vector<int> a(n);
  for (auto &it : a)
  {
    cin >> it;
    if (it == 1)
      red++;
    else if (it == 2)
      blue++;
  }

  Graph G(n);
  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[v].push_back(u);
    G[u].push_back(v);
  }

  int ans = 0;
  dfs(G, a, red, blue, ans, 0);
  cout << ans << endl;
  return;
}
// ある頂点u, vを考えた時にuは全ての赤を含み青を含まない，もしくは全ての青を含み，赤を含まないようなu, vであればよい
// このようなペアu, vを探すために適当な頂点を選んで根付き木にして木dpを行う 部分木がall or 0, 0 or all かを確かめるだけなら一般的な木dpで求めることが出来る
//  That's because removing that edge splits the tree into the subtree of u and the component of every other vertex.
// the task is to calculate the number of red and blue vertices in each subtree with dfs and check a couple of conditions.

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
