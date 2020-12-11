#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
/*
struct Edge
{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
*/
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

struct star
{
  int x, y, size;
};

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (auto &it : grid)
    cin >> it;

  vector<vector<int>> L(n, vector<int>(m)), R(n, vector<int>(m)), D(n, vector<int>(m)), U(n, vector<int>(m));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      // cerr << "i: " << i << "  j: " << j << endl;
      if (i > 0)
      {
        if (grid[i][j] != '.')
          U[i][j] = U[i - 1][j] + 1;
      }
      else
      {
        if (grid[i][j] == '*')
          U[i][j] = 1;
      }
      if (j > 0)
      {
        if (grid[i][j] != '.')
          L[i][j] = L[i][j - 1] + 1;
      }
      else
      {
        if (grid[i][j] == '*')
          L[i][j] = 1;
      }
    }
  }

  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = m - 1; j >= 0; j--)
    {
      if (i < n - 1)
      {
        if (grid[i][j] != '.')
          D[i][j] = D[i + 1][j] + 1;
      }
      else
      {
        if (grid[i][j] == '*')
          D[i][j] = 1;
      }
      if (j < m - 1)
      {
        if (grid[i][j] != '.')
          R[i][j] = R[i][j + 1] + 1;
      }
      else
      {
        if (grid[i][j] == '*')
          R[i][j] = 1;
      }
    }
  }

  vector<star> ans;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][j] == '*')
      {
        int len = min(U[i][j], min(D[i][j], min(R[i][j], L[i][j]))) - 1;
        if (len != 0)
        {
          ans.push_back({i, j, len});
        }
      }
    }
  }

  vector<string> f(n, string(m, '.'));
  vector<vector<int>> h(n, vector<int>(m)), v(n, vector<int>(m));
  for (auto it : ans)
  {
    if (it.x - it.size >= 0)
      v[it.x - it.size][it.y]++;
    if (it.x + it.size + 1 < n)
      v[it.x + it.size + 1][it.y]--;
    if (it.y - it.size >= 0)
      h[it.x][it.y - it.size]++;
    if (it.y + it.size + 1 < m)
      h[it.x][it.y + it.size + 1]--;
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (i > 0)
        v[i][j] += v[i - 1][j];
      if (j > 0)
        h[i][j] += h[i][j - 1];
      if (h[i][j] > 0 || v[i][j] > 0)
        f[i][j] = '*';
    }
  }

  if (f == grid)
  {
    cout << ans.size() << endl;
    for (auto it : ans)
    {
      cout << it.x + 1 << " " << it.y + 1 << " " << it.size << endl;
    }
  }
  else
    cout << -1 << endl;
  return;
}
// Ui,j will denote the distance to the nearest dot character to the top from the current position. After calculating all these matrices the maximum possible length of rays of the star with center in position (i, j) is min(Ui,j, Di,j, Ri,j, Li,j) - 1
// The second part is to draw all stars in O(N^2). Let's calculate another two matrices ---h and v. Let the center of the current star is (i, j) and its size is s. Let's increase hi,j-s by one and hi, j+s+1 by one. (if (j + s + 1) <= m) if i > 1 then set vi,j:=vi,j + vi-1,j hi:=hi,j + hi,j-1 if either hi,j or vi,j greater than zero, then the character is '*'
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  t = 1;
  for (int i = 0; i < t; i++)
  {
    solve();
  }
  return 0;
}
