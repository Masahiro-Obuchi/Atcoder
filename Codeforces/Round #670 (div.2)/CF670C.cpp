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

void SubFindCentroids(Graph &G, vector<int> &centroids, vector<int> &sizeSubtree, int n, int v, int p = -1)
{
  sizeSubtree[v] = 1;
  bool isCentroid = true;
  for (auto ch : G[v])
  {
    if (ch == p)
      continue;
    SubFindCentroids(G, centroids, sizeSubtree, n, ch, v);
    if (sizeSubtree[ch] > n / 2)
      isCentroid = false;
    sizeSubtree[v] += sizeSubtree[ch];
  }
  if (n - sizeSubtree[v] > n / 2)
    isCentroid = false;
  if (isCentroid)
    centroids.push_back(v);
}

void FindCentroids(Graph &G, vector<int> &centroids, vector<int> &sizeSubtree, int n)
{
  centroids.clear();
  SubFindCentroids(G, centroids, sizeSubtree, n, 0, n); // これを呼び出すと centoroids に重心を列挙したものが入る
}

void solve()
{
  int n;
  cin >> n;
  Graph G(n);
  for (int i = 0; i < n - 1; i++)
  {
    int x, y;
    cin >> x >> y;
    x--, y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  vector<int> centroids;
  vector<int> sizeSubTree(n);
  FindCentroids(G, centroids, sizeSubTree, n);
  if (centroids.size() == 1)
  {
    cout << centroids[0] + 1 << " " << G[centroids[0]][0] + 1 << endl;
    cout << centroids[0] + 1 << " " << G[centroids[0]][0] + 1 << endl;
  }
  else
  {
    int cent1 = centroids[0] + 1, cent2 = centroids[1] + 1;
    int v1;
    for (auto u : G[cent1 - 1])
    {
      if (u + 1 != cent2)
      {
        v1 = u;
        break;
      }
    }
    cout << cent1 << " " << v1 + 1 << endl;
    cout << cent2 << " " << v1 + 1 << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    solve();
  }
  return 0;
}
