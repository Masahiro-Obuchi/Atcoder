// 隣接行列によるグラフの連結判定
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

const int limit = 50;

int N, M;
vector<int> a(limit), b(limit);

vector<vector<bool>> graph(limit, vector<bool>(limit));
vector<bool> visited(limit);

void dfs(int v)
{
  visited[v] = true;
  for (int v2 = 0; v2 < N; v2++)
  {
    if (graph[v][v2] == false)
      continue;
    if (visited[v2] == true)
      continue;
    dfs(v2);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  for (int i = 0; i < M; i++)
  {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
    graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
  }

  int ans = 0;

  for (int i = 0; i < M; i++)
  {
    graph[a[i]][b[i]] = graph[b[i]][a[i]] = false;

    for (int j = 0; j < N; j++)
      visited[j] = false;

    dfs(0);

    bool bridge = false;
    for (int j = 0; j < N; j++)
      if (visited[j] == false)
        bridge = true;
    if (bridge)
      ans++;

    graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
  }

  cout << ans << endl;
  return 0;
}

// グラフ　橋検出アルゴリズム
// dfsによる連結判定
// 連結判定はdfsを用いて行う．連結判定をする際には全ての頂点を未訪問にしてから任意の1つの頂点からDFSを呼びます．そのあとに全ての頂点が訪問済みなら連結であり，そうでなければ非連結です．各辺をグラフから取り除いてグラフが連結であるか判定して非連結である場合を数え上げます．
