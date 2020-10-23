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

int dp[160][15][100];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;

  while (1)
  {
    cin >> n >> m;
    if (n == 0 && m == 0)
      break;

    vector<vector<pair<int, int>>> xd(n + 2);
    for (int i = 0; i < n; i++)
    {
      int k;
      cin >> k;
      for (int j = 0; j < k; j++)
      {
        int x, d;
        cin >> x >> d;
        x--;
        xd[i].push_back({x, d});
      }
    }

    for (int i = 0; i < 160; i++)
    {
      for (int j = 0; j < 15; j++)
      {
        for (int l = 0; l < 100; l++)
        {
          dp[i][j][l] = INT_INF;
        }
      }
    }

    for (int j = 0; j < xd[0].size(); j++)
      dp[0][j][m] = 0;

    if (m)
      for (int j = 0; j < xd[1].size(); j++)
      {
        dp[1][j][m - 1] = 0;
      }

    for (int i = 0; i < n - 1; i++)
    {
      for (int j = 0; j < xd[i].size(); j++)
      {
        for (int l = 0; l < m + 1; l++)
        {

          for (int t = 0; t < xd[i + 1].size(); t++)
          {
            int cost = (xd[i][j].second + xd[i + 1][t].second) * abs(xd[i][j].first - xd[i + 1][t].first);
            dp[i + 1][t][l] = min(dp[i + 1][t][l], dp[i][j][l] + cost);
          }

          if (l > 0)
            for (int t = 0; t < xd[i + 2].size(); t++)
            {
              int cost = (xd[i][j].second + xd[i + 2][t].second) * abs(xd[i][j].first - xd[i + 2][t].first);
              dp[i + 2][t][l - 1] = min(dp[i + 2][t][l - 1], dp[i][j][l] + cost);
            }
        }
      }
    }
    int ans = INT_INF;
    for (int j = 0; j < xd[n - 1].size(); j++)
    {
      for (int l = 0; l < m + 1; l++)
      {
        ans = min(ans, dp[n - 1][j][l]);
      }
    }
    for (int j = 0; j < xd[n - 2].size(); j++)
    {
      for (int l = 1; l < m + 1; l++)
      {
        ans = min(ans, dp[n - 2][j][l]);
      }
    }
    cout << ans << endl;
  }
  return 0;
}

//
// dp[i][j][k]:= i行j個目の石に到達したときの危険度の合計の最小値　kは1行飛ばしを行える残り回数
// 崖から飛び移る時と崖に飛び移るときに気を付ける　iがn-1のときのlが0以上とiがn-2のときのlが1以上の時のminを計算する
// グリッドDPの実装ヤバい版　DPはまず漸化式を考える　ある行iにいるときに次にどこに行くのかを考える．jを全て試してmも全て試す　行先をlとしてlも全部試す
