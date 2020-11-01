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
//using Graph = vector<vector<Edge>>;
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;
const double PI = acos(-1.0);

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

static const int N = 100;
static const int INFTY = (1 << 21);

int n, M[N][N];
int d[N]; // 距離で訪問状態(color)を管理する

void bfs(int s)
{
  queue<int> q;
  q.push(s);
  for (int i = 0; i < n; i++)
    d[i] = INFTY;
  d[s] = 0;
  int u;
  while (!q.empty())
  {
    u = q.front(), q.pop();
    for (int v = 0; v < n; v++)
    {
      if (M[u][v] == 0)
        continue;
      if (d[v] != INFTY)
        continue;
      d[v] = d[u] + 1;
      q.push(v);
    }
  }
  for (int i = 0; i < n; i++)
  {
    cout << i + 1 << " " << ((d[i] == INFTY) ? (-1) : d[i]) << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int u, k, v;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      M[i][j] = 0;
  }

  for (int i = 0; i < n; i++)
  {
    cin >> u >> k;
    u--;
    for (int j = 0; j < k; j++)
    {
      cin >> v;
      v--;
      M[u][v] = 1;
    }
  }

  bfs(0);

  return 0;
}
