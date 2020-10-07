#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int w, h, x, y;

void dfs(vector<vector<int>> &map, int x, int y)
{
  // 今いるところを0に置き換える
  map[x][y] = 0;

  for (int dx = -1; dx <= 1; dx++)
  {
    for (int dy = -1; dy <= 1; dy++)
    {
      // x方向にdx移動したものをnx，y方向にdy移動したものをnyとおく
      int nx = x + dx, ny = y + dy;

      // nxとnyが地図の範囲内かどうかとmap[nx][ny]が陸なのかを判定
      if (0 <= nx && nx < h && 0 <= ny && ny < w && map[nx][ny] == 1)
        dfs(map, nx, ny);
    }
  }
  return;
}

void solve(vector<vector<int>> &map)
{
  int ans = 0;
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      if (map[i][j] == 1)
      {
        dfs(map, i, j);
        ans++;
      }
    }
  }
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  while (1)
  {
    cin >> w >> h;
    if (w == 0 && h == 0)
      break;
    vector<vector<int>> map(h, vector<int>(w));
    for (int i = 0; i < h; i++)
    {
      for (int j = 0; j < w; j++)
      {
        cin >> map[i][j];
      }
    }
    solve(map);
  }
  return 0;
}
