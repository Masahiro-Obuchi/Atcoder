
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 100000000;
typedef pair<int, int> P;
const int MAX_H = 20, MAX_W = 20;
int H, W;
int sy = 0, sx = 0;
int gy = 0, gx = 0;
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
  int ans = 0;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      for (int k = 0; k < H; k++)
      {
        for (int l = 0; l < W; l++)
        {
          if (maze[i][j] == '.')
            sy = i, sx = j;
          if (maze[k][l] == '.')
            gy = k, gx = l;
          if (maze[sy][sx] == '#' or maze[gy][gx] == '#')
            continue;
          if (sy != gy or sx != gx)
          {
            int now = bfs();
            if (now != INF)
              ans = max(ans, now);
          }
        }
      }
    }
  }
  cout << ans << endl;
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

// 各sy, sxについて最も遠い距離を求めた方が良さそう．int res = 0などとして各キューの要素に対してmax(res, d[p.first][p.second])などとする？INFのときはcontinue
