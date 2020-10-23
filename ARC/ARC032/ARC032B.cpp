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
  UnionFind uf(N);
  for (int i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    uf.merge(a, b);
  }
  int cnt = 0;
  set<int> st;
  for (int i = 0; i < N; i++)
  {
    st.insert(uf.root(i));
  }
  int ans = st.size() - 1;
  cout << ans << endl;
  return 0;
}
