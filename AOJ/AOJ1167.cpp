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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  const int limit = 1000100;
  vector<ll> dp(limit, INF), dp2(limit, INF);
  dp[0] = dp2[0] = 0;
  for (int i = 1;; i++)
  {
    int num = i * (i + 1) * (i + 2) / 6;
    if (num >= limit)
      break;
    for (int j = 1; j < limit; j++)
    {
      if (j - num >= 0)
      {
        dp[j] = min(dp[j], dp[j - num] + 1);
        if (num % 2 != 0)
          dp2[j] = min(dp2[j], dp2[j - num] + 1);
      }
    }
  }

  int n;
  while (true)
  {
    cin >> n;
    if (n == 0)
      break;

    cout << dp[n] << " " << dp2[n] << endl;
  }
  return 0;
}

// dp[i]:=整数iを作るために必要な正四面体の最小個数　
