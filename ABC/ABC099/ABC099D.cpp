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

// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};
int dx[6] = {1, 0, -1, 1, -1, 0}, dy[6] = {1, 1, 1, 0, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, C;
  cin >> N >> C;
  vector<vector<int>> D(C, vector<int>(C));
  for (int i = 0; i < C; i++)
  {
    for (int j = 0; j < C; j++)
    {
      cin >> D[i][j];
    }
  }
  vector<vector<int>> t(3, vector<int>(C));
  vector<vector<int>> c(N, vector<int>(N));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> c[i][j];
      t[(i + j) % 3][c[i][j] - 1]++; // 前処理として(i + j) % 3となる位置に各色が何色あるか先に計算しておく
    }
  }
  ll ans = INF;
  // 使う色を全列挙
  for (int x = 1; x <= C; x++)
  {
    for (int y = 1; y <= C; y++)
    {
      if (x == y)
        continue;
      for (int z = 1; z <= C; z++)
      {
        if (x == z || y == z)
          continue;
        ll tmp = 0;
        for (int i = 0; i < C; i++)
          tmp += D[i][x - 1] * t[0][i]; // mod 3 == 0のときに色をx-1に変えるためのコストが何回分かかるかを計算する
        for (int i = 0; i < C; i++)
          tmp += D[i][y - 1] * t[1][i]; // mod 3 == 1
        for (int i = 0; i < C; i++)
          tmp += D[i][z - 1] * t[2][i]; // mod 3 == 2
        ans = min(ans, tmp);
      }
    }
  }
  cout << ans << endl;
  return 0;
}

// どの色で最初に塗られているマスがいくつあるかを予め計算しておくとこの部分がO(C)となり，時間内に正解を得ることが出来る．
