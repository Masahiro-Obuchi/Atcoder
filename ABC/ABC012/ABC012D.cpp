#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

vector<vector<int>> dist(300, vector<int>(300, INT_INF));

void warshallFloyd(int n)
{
  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++)
  {
    int a, b, t;
    cin >> a >> b >> t;
    a--, b--;
    dist[a][b] = dist[b][a] = t;
  }

  for (int i = 0; i < N; i++)
  {
    dist[i][i] = 0;
  }
  warshallFloyd(N);
  int ans = INT_INF;
  for (int i = 0; i < N; i++)
  {
    int tmp = 0;
    for (int j = 0; j < N; j++)
    {
      tmp = max(tmp, dist[i][j]);
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}

// 全点対間最短経路を知りたいのでワーシャルフロイドを用いる．
