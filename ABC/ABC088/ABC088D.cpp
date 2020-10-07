#include <bits/stdc++.h>
using namespace std;

const int INF = 100000000;
typedef pair<int, int> P;
const int MAX_H = 50, MAX_W = 50;
int H, W;
int sy, sx;
int gy, gx;
char maze[MAX_H][MAX_W];

int d[MAX_H][MAX_W];

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int bfs();

int main()
{
  cin >> H >> W;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cin >> maze[i][j];
    }
  }
  int cnt = 0;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (maze[i][j] == '#')
        cnt++;
    }
  }
  int res = bfs();
  if (res == INF)
    cout << -1 << endl;
  else
  {
    int ans = H * W - (cnt + res + 1);
    cout << ans << endl;
  }
}

int bfs()
{
  queue<P> que;
  // 全ての点をINFで初期化
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      d[i][j] = INF;
    }
  }
  // スタート地点をキューに入れ，その点の距離を0にする
  sy = 0, sx = 0;
  gy = H - 1, gx = W - 1;
  que.push(P(sy, sx));
  d[sy][sx] = 0;

  // キューが空になるまでループ
  while (que.size())
  {
    // キューの先頭を取り出す
    P p = que.front();
    que.pop();
    // 取り出してきた状態がゴールなら探索をやめる
    if (p.first == gy && p.second == gx)
    {
      break;
    }
    // 移動4方向をループ
    for (int i = 0; i < 4; i++)
    {
      // 移動した後の点を(nx, ny)とする
      int ny = p.first + dy[i], nx = p.second + dx[i];

      // 移動が可能かの判定と既に訪れたことがあるかの判定(d[nx][ny] != INFなら訪れたことがある)
      if (0 <= ny && ny < H && 0 <= nx && nx < W && maze[ny][nx] != '#' && d[ny][nx] == INF)
      {
        // 移動できるならキューに入れ，その点の距離をpからの距離+1で確定する
        que.push(P(ny, nx));
        d[ny][nx] = d[p.first][p.second] + 1;
      }
    }
  }
  return d[gy][gx];
}
