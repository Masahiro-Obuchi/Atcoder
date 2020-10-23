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
// using Graph = vector<vector<Edge>>;
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;

  Graph G(n);
  vector<int> in(n, 0);

  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    in[b]++;
  }

  queue<int> que;

  for (int i = 0; i < n; i++)
    if (in[i] == 0)
      que.push(i);

  bool multi = false;

  vector<int> ans;

  while (!que.empty())
  {
    int v = que.front();
    que.pop();
    if (que.size() > 0)
      multi = true;
    ans.push_back(v);
    for (auto u : G[v])
    {
      in[u]--;
      if (in[u] == 0)
        que.push(u);
    }
  }

  for (int i = 0; i < n; i++)
    cout << ans[i] + 1 << endl;
  cout << multi << endl;
  return 0;
}

// 順位や優先度，大小関係を図る時，そのようにソートしたい時，そのような一例を求めたいときはトポロジカルソートをすればよい．
// よって、現在勝っているチームから選んでいく、つまり入次数が0の頂点からトポロジカルソートをすればよい。 このように選べば、右側にあるチームに勝つとすれば、勝つ回数の条件をみたす。
// トポロジカルソートとは全ての頂点u, vについてu/=vかつR(u, v)であったらuがvより先に現れるように頂点を一列に並べることである．
// 全ての頂点u, vについてR(u, v)かつR(v, u)ならばu = vが成り立つ．かつその時に限り，その有向グラフをトポロジカルソートできる．（つまり，ある頂点から出発してその頂点に戻ってくる路がないとき）
// この条件を満たす有向グラフを有向非巡回グラフ(DAG)という．
// 実装では隣接リストを利用して頂点の入次数も記録しておく．
// 1.入次数0の頂点vを発見する．2. 頂点vを配列の末尾に追加する．3.有向グラフから頂点vとその頂点から出ている辺を全て削除する．これを繰り返し，すべての頂点を取り除いた後に得られる配列を出力すればそれが与えられたDAGのトポロジカルソートになっている．
// https://qiita.com/Morifolium/items/6c8f0a188af2f9620db2
