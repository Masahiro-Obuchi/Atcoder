#include <bits/stdc++.h>
using namespace std;

vector<int> to[110]; // 木構造とDFSについて考える
vector<bool> memo(110);
int ans = 0;
bool flag;

void dfs(int v, int p = -1)
{                     // 親に戻ったりしないようにどっから来たのかも引数にとる
  for (int u : to[v]) // 隣接の頂点を全部なめる
  // vectorの要素においてto[v]となっているものすべて？
  {
    if (u == p) // 親に戻ってきてしまったらcontinue
      continue;
    if (memo[u])
    { // 閉路
      flag = false;
    }
    else
    {
      memo[u] = true;
      dfs(u, v);
    }
  }
  return;
}

int main()
{
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++)
  {
    int u, v;
    cin >> u >> v;
    u--; // 1indexedだから0から始めるようにする
    v--;
    to[u].push_back(v);
    to[v].push_back(u);
  }
  for (int i = 0; i < 110; i++)
  {
    memo[i] = false;
  }

  for (int i = 0; i < N; i++)
  {
    if (memo[i] == false)
    { // まだ調べていない頂点
      flag = true;
      dfs(i, -1);
      if (flag)
        ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

// すでに探索した頂点をmemoで記録しておいて，同じところに2度来たら，その連結成分は閉路を持つので木ではないのでカウントしない．
