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
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &it : a)
    cin >> it;
  sort(a.begin(), a.end());
  vector<int> cnt(n);
  for (int i = 0; i < n; i++)
  {
    while (i + cnt[i] < n && a[i + cnt[i]] - a[i] <= 5)
    {
      cnt[i]++;
    }
  }

  vector<vector<int>> dp(n + 1, vector<int>(k + 1));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= k; j++)
    {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      if (j + 1 <= k)
      {
        dp[i + cnt[i]][j + 1] = max(dp[i + cnt[i]][j + 1], dp[i][j] + cnt[i]);
      }
    }
  }
  cout << dp[n][k] << endl;
  return;
} // E
// dpi,j := the maximum number of students in at most j non-empty teams if we consider first i students. 1st transition : just skip the i-th (0-indexed) student. dpi+1,j+i = max(dpi+1,j+1, dpi,j). The second possible transition is to take some team starting from the i-th student. take the maximum by number of students team starting from the i-th student is always optimally. Why it is so? So the second transition is the following: let cnti be the number of students in a team if the i-th student is the first in it. If we consider the student with the maximum programming skill in the team, we can take him to this team instad of forming the new team with this student because this is always not worse. We can calculate this part in O(n2) naively or in O(n) using two pointers. dpi+cnti,j+1=max(dpi+cnti,j+1,dpi,j+cnti) .
// ナップサック的

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
