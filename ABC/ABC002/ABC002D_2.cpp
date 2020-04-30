#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<vector<bool>> graph(12, vector<bool>(12));
  for (int i = 0; i < M; i++)
  {
    int x, y;
    cin >> x >> y;
    x--, y--;
    graph[x][y] = graph[y][x] = true;
  }

  int ans = 1; // 最低人数は一人

  for (int bit = 0; bit < (1 << N); bit++)
  {
    vector<int> candidate;
    for (int i = 0; i < N; i++)
    {
      if (bit & (1 << i))
        candidate.push_back(i);
    }

    bool ok = true;
    for (auto a : candidate)
    {
      for (auto b : candidate)
      { // 二重ループで全ての個々人間の関係を見ることが出来る
        if (a == b)
          continue;               // 同一ノードは無視
        if (graph[a][b] == false) // 直接繋がっていないノードが存在する集合(bit)ははじく
          ok = false;
      }
    }
    if (ok)
      ans = max(ans, (int)candidate.size());
  }

  cout << ans << endl;
  return 0;
}

// 重みなし無向グラフとbit全探索の組み合わせ
// 木構造を用いてDFS?bit全探索で全ての場合を試す．
// __builtin_popcount()関数はgccのビルトイン関数で、引数のbitがいくつ立っているのかを返してくれる．
// 派閥に含まれる全ての議員が互いに知り合い同士 = 全てのノードが直接繋がっているような集合を考えればよい．
// 知り合い関係はcon[12][12]で保存した方が楽そう
// 木構造と隣接行列の使い分け
// 木構造を使った場合の解法も作れるように
