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
using Graph = vector<vector<Edge>>;
// using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int H, W;
  cin >> H >> W;
  vector<vector<char>> field(H, vector<char>(W));
  int sy, sx, gy, gx;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cin >> field[i][j];
      if (field[i][j] == 's')
        sy = i, sx = j;
      else if (field[i][j] == 'g')
        gy = i, gx = j;
    }
  }

  vector<vector<int>> d(H, vector<int>(W, INT_INF));
  priority_queue<pair<int, P>, vector<pair<int, P>>, greater<pair<int, P>>> que;
  que.push({0, {sy, sx}});
  d[sy][sx] = 0;

  while (!que.empty())
  {
    pair<int, P> p = que.top();
    int cost = p.first;
    que.pop();
    if (p.second.first == gy && p.second.second == gx)
    {
      break;
    }
    if (d[p.second.first][p.second.second] < cost)
      continue;
    for (int i = 0; i < 4; i++)
    {
      int ny = p.second.first + dy[i], nx = p.second.second + dx[i];
      if (0 <= ny && ny < H && 0 <= nx && nx < W && d[ny][nx] == INT_INF)
      {
        int weight = 0;
        if (field[ny][nx] == '#')
          weight++;
        if (d[ny][nx] <= cost + weight)
          continue;
        d[ny][nx] = cost + weight;
        que.push({d[ny][nx], {ny, nx}});
      }
    }
  }

  /*
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    */

  if (d[gy][gx] <= 2)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
