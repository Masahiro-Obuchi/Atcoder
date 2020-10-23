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
// using Graph = vector<vector<Edge>>;
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a, b;
  cin >> a >> b;
  int n;
  cin >> n;

  vector<vector<int>> dp(a + 1, vector<int>(b + 1));
  vector<vector<bool>> ng(a + 1, vector<bool>(b + 1));

  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    ng[x][y] = true;
  }

  for (int i = 1; i <= a; i++)
  {
    for (int j = 1; j <= b; j++)
    {
      if (i == 1 && j == 1 && !ng[i][j])
        dp[i][j] = 1;
      else if (!ng[i][j])
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      else
        dp[i][j] = 0;
    }
  }

  cout << dp[a][b] << endl;
  return 0;
}

// グリッドDP 交差点(i, j)に移動する方法をdp[i][j]とする．
// 遷移はソースコードの通り
