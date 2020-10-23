#include <bits/stdc++.h>
using namespace std;

vector<string> a(10);
vector<vector<bool>> vs;

int make_id(int i, int j)
{
  return i * 10 + j;
}

int dfs(int x, int y)
{
  if (vs[x][y])
    return 0;
  vs[x][y] = true;
  int ret = 1;
  if (x > 0 && a[x - 1][y] == 'o')
    ret += dfs(x - 1, y);
  if (x < 9 && a[x + 1][y] == 'o')
    ret += dfs(x + 1, y);
  if (y > 0 && a[x][y - 1] == 'o')
    ret += dfs(x, y - 1);
  if (y < 9 && a[x][y + 1] == 'o')
    ret += dfs(x, y + 1);
  return ret;
}

int main()
{
  for (int i = 0; i < 10; i++)
    cin >> a[i];
  int c = 0;
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      if (a[i][j] == 'o')
        c++;
    }
  }
  c++;
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      if (a[i][j] == 'o')
        continue;
      vs = vector<vector<bool>>(10, vector<bool>(10));
      if (dfs(i, j) == c)
      {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
