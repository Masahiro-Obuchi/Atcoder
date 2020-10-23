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
using Graph = vector<vector<Edge>>;
// using Graph = vector<vector<int>>;

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
  int N, Q;
  cin >> N >> Q;
  UnionFind uf(2 * N);
  for (int i = 0; i < Q; i++)
  {
    int w, x, y, z;
    cin >> w >> x >> y >> z;
    x--, y--;
    if (w == 1)
    {
      z = z % 2;
      if (z == 0)
      {
        uf.merge(x, y);
        uf.merge(x + N, y + N);
      }
      else
      {
        uf.merge(x, y + N);
        uf.merge(y, x + N);
      }
    }
    else
    {
      if (uf.isSame(x, y))
      {
        cout << "YES" << endl;
      }
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}

// 結ぶ辺の長さが偶数なら同じ色同士を結ぶ　結ぶ辺の長さが奇数なら違う色同士を結ぶ　頂点X,Yが偶数メートルで移動できるかどうか Xの赤とYの赤が同じ連結成分に含まれる　同値　
// 解法 : 各頂点1つごとに2つずつ頂点を用意し, それぞれ赤色と青色とする。で, 頂点aと頂点bの間に道を作る時, ・道の長さが偶数ならaとbの同じ色同士をそれぞれグループ化する ・道の長さが奇数ならaとbの異なる色同士をそれぞれグループ化する 結論を言うと, aとbの間が偶数の距離で結ばれるというのと, aとbの同じ色が同じグループに属することは同値である。なぜなら, まずaとbがつながってない時はaとbは同じグループでないのでOK。また, aとbがつながっているときは, 同じ色でつながっているときは, 赤->青->赤->青->赤->赤というように, 色の遷移は偶数回存在しなければならない。これは, 奇数の道を偶数回通ることに対応しているので同値であることが確認できる。
// 繋がっているということは赤->青->赤のように奇数の道を偶数回通っているはず
