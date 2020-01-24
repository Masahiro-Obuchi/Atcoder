#include <bits/stdc++.h>
using namespace std;

const int INF = 100000000;
typedef pair<int, int> P;
const int MAX_H = 1000, MAX_W = 1000;
int H, W, N;
int sy, sx;
int gy, gx;
char maze[MAX_H][MAX_W];

int d[MAX_H][MAX_W];

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int bfs(int goal);

int main()
{
  cin >> H >> W >> N;

  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cin >> maze[i][j];
    }
  }
  int ans = 0;
  for (int goal = 1; goal <= N; goal++)
  {
    ans += bfs(goal);
  }
  cout << ans << endl;
}

int bfs(int goal)
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
  bool find = false;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (goal == 1)
      {
        if (maze[i][j] == 'S')
        {
          sy = i, sx = j;
          find = true;
          break;
        }
      }
      else
      {
        if (maze[i][j] == '0' + (goal - 1))
        {
          sy = i, sx = j;
          find = true;
          break;
        }
      }
    }
    if (find)
      break;
  }
  bool find2 = false;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (maze[i][j] == '0' + goal)
      {
        gy = i, gx = j;
        find2 = true;
        break;
      }
    }
    if (find2)
      break;
  }
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
      if (0 <= ny && ny < H && 0 <= nx && nx < W && maze[ny][nx] != 'X' && d[ny][nx] == INF)
      {
        // 移動できるならキューに入れ，その点の距離をpからの距離+1で確定する
        que.push(P(ny, nx));
        d[ny][nx] = d[p.first][p.second] + 1;
      }
    }
  }
  return d[gy][gx];
}
