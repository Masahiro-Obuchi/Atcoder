#include <bits/stdc++.h>
using namespace std;
struct Edge
{
  int to, id;
};
vector<vector<Edge>> g;
vector<int> ans;
void dfs(int v, int c = -1, int p = -1)
{
  int k = 1;
  for (auto u : g[v])
  {
    int ei = u.id;
    if (u.to == p)
      continue;
    if (k == c)
      k++;
    ans[ei] = k;
    k++;
    dfs(u.to, ans[ei], v);
  }
}
int main()
{
  int N;
  cin >> N;
  g.resize(N);
  ans = vector<int>(N - 1);
  for (int i = 0; i < N - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back((Edge){b, i});
    g[b].push_back((Edge){a, i});
  }
  dfs(0);
  int mx = 0;
  for (int i = 0; i < N; i++)
  {
    mx = max(mx, int(g[i].size()));
  }
  cout << mx << endl;
  for (int i = 0; i < N - 1; i++)
  {
    cout << ans[i] << endl;
  }
  return 0;
}

// 色数 >= 最大時数であることが分かる．もっと，丁寧に図を書いて実験を行う．そうすればDFSで解けることが分かる．辺の情報を保持する方法．
