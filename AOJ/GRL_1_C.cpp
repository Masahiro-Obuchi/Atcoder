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
    ll weight;
    Edge(int t, ll w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
*/
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

vector<vector<ll>> d(110, vector<ll>(110, INF));

void warshallFloyd(int n)
{
  for (int k = 0; k < n; k++) // 経由する頂点
  {
    for (int i = 0; i < n; i++) // 始点
    {
      for (int j = 0; j < n; j++) // 終点
      {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]); // 距離
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int V, E;
  cin >> V >> E;
  for (int i = 0; i < E; i++)
  {
    int s, t;
    cin >> s >> t;
    ll dist;
    cin >> dist;
    d[s][t] = dist;
  }

  for (int i = 0; i < V; i++)
    d[i][i] = 0;
  warshallFloyd(V);

  bool ok = true;
  for (int i = 0; i < V; i++)
  {
    if (d[i][i] < 0)
    {
      ok = false;
      break;
    }
  }

  if (!ok)
    cout << "NEGATIVE CYCLE" << endl;
  else
  {
    for (int i = 0; i < V; i++)
    {
      for (int j = 0; j < V; j++)
      {
        if (d[i][j] >= INF / 2)
        {
          if (j == 0)
            cout << "INF";
          else
            cout << " "
                 << "INF";
        }
        else
        {
          if (j == 0)
            cout << d[i][j];
          else
            cout << " " << d[i][j];
        }
      }
      cout << endl;
    }
  }
  return 0;
}

// Gに負の閉路がない限り、Gに負の重みをもつ辺が存在しても適用可。Gに負の閉路があるかどうかの判定に使える。すなわち、ある頂点vから頂点v（それ自身)への最短距離が負になれば、Gに負の閉路が存在すると判断できる。
