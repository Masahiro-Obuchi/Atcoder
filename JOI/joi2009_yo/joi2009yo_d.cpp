#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int n, m;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int max_depth;

void dfs(vector<vector<int>> &map, int x, int y, int depth)
{
  map[x][y] = 0; // 現在いる薄氷を割る
  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i], ny = y + dy[i];

    if (map[nx][ny] == 1)
      dfs(map, nx, ny, depth + 1);
  }

  map[x][y] = 1; // 割った氷をもとに戻しておく

  if (map[x - 1][y] || map[x][y - 1] || map[x][y + 1] || map[x + 1][y] == 0) // 東西南北どちらにも薄氷がない場合
    if (depth > max_depth)
      max_depth = depth;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> m;
  cin >> n;
  vector<vector<int>> map(n + 2, vector<int>(m + 2)); // 端点の処理を楽にするため
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      cin >> map[i][j];
    }
  }
  max_depth = 1;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (map[i][j] == 1)
        dfs(map, i, j, 1);
    }
  }
  cout << max_depth << endl;
  return 0;
}
