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

bool check(long double x, vector<int> &A, vector<int> &B, vector<long double> &C, vector<long double> &T, int N, int M)
{
  vector<pair<long double, P>> y(M);
  for (int i = 0; i < M; i++)
  {
    y[i].first = C[i] - x * T[i];
    y[i].second.first = A[i], y[i].second.second = B[i];
  }

  sort(y.begin(), y.end());

  double sum = 0.0;
  UnionFind uf(N);
  int cnt = 0;
  int i = 0;
  while (uf.size(0) < N || i < M - 1)
  {
    // cerr << "i: " << i << "  cnt: " << cnt << endl;
    if (!uf.isSame(y[i].second.first, y[i].second.second) || y[i].first < 0.0)
    {
      sum += y[i].first;
      uf.merge(y[i].second.first, y[i].second.second);
      cnt++;
    }
    i++;
  }
  return sum <= 0;
}
// \sigmaCi - xTi <= xとなるような辺の選び方があるかどうかを判定したい

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  vector<long double> C(M), T(M);
  for (int i = 0; i < M; i++)
  {
    cin >> A[i] >> B[i] >> C[i] >> T[i];
  }

  long double left = 0, right = INT_INF;
  for (int i = 0; i < 100; i++)
  {
    // cerr << "left: " << left << "  right: " << right << endl;
    long double mid = (left + right) / 2.0;
    if (check(mid, A, B, C, T, N, M))
      right = mid;
    else
      left = mid;
  }
  cout << fixed << setprecision(12) << right << endl;
  return 0;
}
