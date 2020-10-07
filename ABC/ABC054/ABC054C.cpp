#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  vector<vector<bool>> G(N, vector<bool>(N));
  for (int i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a][b] = 1;
    G[b][a] = 1;
  }

  vector<int> v(N);
  iota(v.begin(), v.end(), 0);
  int num = 1;
  for (int i = 1; i <= N; i++)
    num *= i;
  vector<vector<int>> b(num);
  int l = 0;
  do
  {
    for (auto x : v)
      b[l].push_back(x);
    l++;
  } while (next_permutation(v.begin(), v.end()));

  int ans = 0;
  for (int i = 0; i < b.size(); i++)
  {
    if (b[i][0] != 0)
      continue;
    bool can = true;
    for (int j = 1; j < b[i].size(); j++)
    {
      if (!G[b[i][j - 1]][b[i][j]])
      {
        can = false;
        break;
      }
    }
    if (can)
      ans++;
  }
  cout << ans << endl;
}

// 順列を生成したうえで深さ優先探索？その順列が成り立つかチェック　具体的にはエッジが存在するかをチェック
// 関係行列が0だったらfalse
// 解説読みながら問題文そのまま実装を再帰で書いてみる．
