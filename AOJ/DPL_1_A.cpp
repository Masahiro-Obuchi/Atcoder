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

template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<ll> c(m);
  for (auto &it : c)
    cin >> it;

  vector<ll> dp(50010, INF);
  dp[0] = 0;
  for (int i = 0; i <= 50000; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (i + c[j] <= n)
        dp[i + c[j]] = min(dp[i + c[j]], dp[i] + 1);
    }
  }
  cout << dp[n] << endl;
  return 0;
}

// dp[i]をi円を支払うために必要なコインの最小枚数とおく．すると答えはdp[n].今累積された金額がx円である時にそこからコインを1枚だけ出してなりうる金額はx+c1, x+c2, ..., x+cm円のm種類のうち，どれかになる．つまりx+ci円支払うのに必要な最小枚数はdp[x+ci]またはdp[x]+1.dp[x+ci] = min(dp[x+ci], dp[x]+1)となる．これを小さい方から回す．
