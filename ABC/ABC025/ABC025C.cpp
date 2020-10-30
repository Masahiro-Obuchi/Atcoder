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

int field[3][3];

int calc(int total, vector<vector<int>> &b, vector<vector<int>> &c)
{
  int res = 0;
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (field[i][j] == field[i + 1][j])
        res += b[i][j];
    }
  }
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      if (field[i][j] == field[i][j + 1])
        res += c[i][j];
    }
  }
  // cerr << res << endl;
  return res;
}

int dfs(int turn, int total, vector<vector<int>> &b, vector<vector<int>> &c)
{
  if (turn == 9)
    return calc(total, b, c);

  int res = (turn % 2 == 0) ? -INT_INF : INT_INF;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (field[i][j] == -1)
      {
        field[i][j] = (turn % 2 == 0) ? 1 : 0;
        res = (turn % 2 == 0) ? max(res, dfs(turn + 1, total, b, c)) : min(res, dfs(turn + 1, total, b, c));
        field[i][j] = -1; // -1に戻す
      }
    }
  }
  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      field[i][j] = -1;
    }
  }
  int total = 0;
  vector<vector<int>> b(2, vector<int>(3));
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> b[i][j];
      total += b[i][j];
    }
  }
  vector<vector<int>> c(3, vector<int>(2));
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      cin >> c[i][j];
      total += c[i][j];
    }
  }
  int ans = dfs(0, total, b, c);
  cout << ans << endl;
  cout << total - ans << endl;
  return 0;
}

// 可読性を上げるためにまずscoreを計算する関数を書いておく
