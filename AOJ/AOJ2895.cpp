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

const int MOD = 1000000007;

// res[i][c] := i 文字目以降で最初に文字 c が登場する index (存在しないときは n)
vector<vector<int>> calcNext(const string &S)
{
  int n = (int)S.size();
  vector<vector<int>> res(n + 1, vector<int>(26, n));
  for (int i = n - 1; i >= 0; --i)
  {
    for (int j = 0; j < 26; ++j)
      res[i][j] = res[i + 1][j];
    res[i][S[i] - 'a'] = i;
  }
  return res;
}

void add(long long &a, long long b)
{
  a += b;
  if (a >= MOD)
    a -= MOD;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string S;
  cin >> S;
  int n = (int)S.size();
  string T = S;
  reverse(T.begin(), T.end());

  auto ns = calcNext(S);
  auto nt = calcNext(T);
  vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      for (int k = 0; k < 26; ++k)
      {
        int ni = ns[i][k];
        int nj = nt[j][k];
        if (ni + nj + 2 > n)
          continue;
        add(dp[ni + 1][nj + 1], dp[i][j]);
      }
    }
  }
  long long res = 0;
  for (int i = 0; i <= n; ++i)
  {
    for (int j = 0; i + j <= n; ++j)
    {
      int num = 1;
      for (int k = 0; k < 26; ++k)
        if (ns[i][k] + 1 + j <= n)
          ++num;
      res = (res + dp[i][j] * num % MOD) % MOD;
    }
  }
  cout << res - 1 << endl;
  return 0;
}

// https://qiita.com/drken/items/a207e5ae3ea2cf17f4bd
