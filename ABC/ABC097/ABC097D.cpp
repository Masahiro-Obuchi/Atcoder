#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
struct Edge
{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
//using Graph = vector<vector<Edge>>;
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;
const double PI = acos(-1.0);

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
  vector<int> p(N);
  for (auto &it : p)
  {
    cin >> it;
    it--;
  }
  UnionFind uf(N);
  for (int i = 0; i < M; i++)
  {
    int x, y;
    cin >> x >> y;
    x--, y--;
    uf.merge(x, y);
  }
  int ans = 0;
  for (int i = 0; i < N; i++)
  {
    if (uf.isSame(i, p[i]))
      ans++;
  }
  cout << ans << endl;
  return 0;
}

// グラフとして見てグラフ毎にそのグラフの頂点が指し示す数字の中に何個iが出るかを数える．(例: グラフの頂点が1, 2, 5, 7, 8だったときp[1], p[2], p[5], p[7], p[8]の中に1, 2, 5, 7, 8のうち何個現れるかを数える)これをグラフごとに全て足し合わせたものが答え．ただし何も操作をしない状態において何個条件を満たすものがあるかを数えてmaxをとる
// S:={i|Gにおいてiとpiが同じ連結成分にある}とおくと，最終状態で全てのi \in Sに対して同時にpi = iとすることが出来る．したがって|S|が答えとなる．各iがSに属するかどうかはUnionFindで求めることが出来る．
