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

void solve()
{
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
  }

  static ll dp[71][71][71][71];

  for (int i = 0; i < 71; i++)
  {
    for (int j = 0; j < 71; j++)
    {
      for (int cnt = 0; cnt < 71; cnt++)
      {
        for (int rem = 0; rem < 71; rem++)
        {
          dp[i][j][cnt][rem] = -INF;
        }
      }
    }
  }

  dp[0][0][0][0] = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      for (int cnt = 0; cnt <= m / 2; cnt++)
      {
        for (int rem = 0; rem < k; rem++)
        {
          if (dp[i][j][cnt][rem] == -INF)
            continue;
          int ni = (j == m - 1 ? i + 1 : i);
          int nj = (j == m - 1 ? 0 : j + 1);
          if (i != ni)
          {
            dp[ni][nj][0][rem] = max(dp[ni][nj][0][rem], dp[i][j][cnt][rem]);
          }
          else
          {
            dp[ni][nj][cnt][rem] = max(dp[ni][nj][cnt][rem], dp[i][j][cnt][rem]);
          }
          if (cnt + 1 <= m / 2)
          {
            if (i != ni)
            {
              dp[ni][nj][0][(rem + a[i][j]) % k] = max(dp[ni][nj][0][(rem + a[i][j]) % k], dp[i][j][cnt][rem] + a[i][j]);
            }
            else
            {
              dp[ni][nj][cnt + 1][(rem + a[i][j]) % k] = max(dp[ni][nj][cnt + 1][(rem + a[i][j]) % k], dp[i][j][cnt][rem] + a[i][j]);
            }
          }
        }
      }
    }
  }
  cout << max(0LL, dp[n][0][0][0]) << endl;
  return;
}

// let dp[x][y][cnt][rem] be the maximum possible sum we can obtain if we are at the element ax,y right now, we took cnt elements in the row x and our current reminder is rem.
// Initially, all states are -INF except dp[0][0][0][0] = 0 Transitions are standard because this is a knapsack problem. we either take the element if cnt < m / 2 or don't take it. If the element ax,y is not the last element of the row, then transitions look lile that : dp[x][y + 1][cnt][rem] = max(dp[x][y + 1][cnt][rem], dp[x][y][cnt][rem]) - we don't take the current element. dp[x][y + 1][cnt + 1][(rem + a[x][y]) % k] = max(dp[x][y + 1][cnt + 1][(rem + a[x][y]) % k], dp[x][y][cnt][rem] + a[x][y]) - we take the current element (this transitions is only possible if cnt < m / 2)
// The transitions from the last element of the row are almost the same, but the next element is ax+1,0 and the new value of cnt is always zero. The answer is max(0, dp[n][0][0][0])
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
