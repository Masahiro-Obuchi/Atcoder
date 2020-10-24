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
  vector<int> par;

  UnionFind(int n) : par(n, -1) {}

  int root(int x)
  {
    if (par[x] < 0)
      return x;
    else
      return par[x] = root(par[x]);
  }

  bool isSame(int x, int y)
  {
    return root(x) == root(y);
  }

  bool merge(int x, int y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
      return false;
    if (par[x] > par[y])
      swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  int size(int x)
  {
    return -par[root(x)];
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<ll> a(N), b(N);
  for (auto &it : a)
    cin >> it;
  for (auto &it : b)
    cin >> it;

  UnionFind uf(N);
  for (int i = 0; i < M; i++)
  {
    int c, d;
    cin >> c >> d;
    c--, d--;
    uf.merge(c, d);
  }

  ll sum1 = 0, sum2 = 0;
  for (auto it : a)
    sum1 += it;
  for (auto it : b)
    sum2 += it;

  if (sum1 != sum2)
  {
    cout << "No" << endl;
    return 0;
  }

  vector<ll> group_suma(N), group_sumb(N);
  for (int i = 0; i < N; i++)
  {
    group_suma[uf.root(i)] += a[i];
    group_sumb[uf.root(i)] += b[i];
  }

  bool can = true;
  for (int i = 0; i < N; i++)
  {
    if (group_suma[i] != group_sumb[i])
      can = false;
  }
  if (can)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
